/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#include <iostream>
#include "Lobby.hpp"

namespace GameEngine {

Lobby::Lobby(std::vector<User> &users, std::unordered_map<std::string, AEntity *> &entities, CommunicationTCPServer &serverCom,
    CommunicationTCPServer &lobbyCom, std::mutex &instanceMutex, int &id)
    : _users(users), _entities(entities), _time(std::chrono::system_clock::now()), _communicationServer(serverCom),
      _communicationLobby(lobbyCom), _mutex(instanceMutex), _id(id)
{
    int i = 0;
    while (i < 4) {
        _slots.emplace_back(Slot());
        i++;
    }
}

GameInstanceStatus Lobby::menuLoop()
{
    std::vector<ACommand> commands;

    createThread();

    _mutex.lock();
    while (!_users.empty() && !isPlayersReady()) {
        if (_users.empty()) {
            return GameInstanceStatus::EXIT;
        }
        _mutex.unlock();
        _commands = _communicationLobby.receive();
        update();
        _mutex.lock();
    }
    _mutex.unlock();
    return GameInstanceStatus::GAME;
}

bool Lobby::isUpdateTime(int fpms)
{
    auto now = std::chrono::system_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(now - _time);
    bool ret = false;

    if (diff.count() > fpms) {
        while (_time < now - std::chrono::milliseconds(fpms)) {
            _time += std::chrono::milliseconds(fpms);
        }
        ret = true;
    }
    return ret;
}

void Lobby::update()
{
    auto it = _commands.begin();

    while (!_commands.empty() && it != _commands.end()) {

        switch (it->get()->commandType) {
            case JOIN_SLOT :
                joinSlot(*static_cast<JoinSlotCommand *>(it->get()));
                break;

            case LEAVE_SLOT :
                leaveSlot(*static_cast<LeaveSlotCommand *>(it->get()));
                break;

            case PLAYER_READY :
                playerReady(*static_cast<PlayerReadyCommand *>(it->get()));
                break;

            case PLAYER_ALIVE :
                playerAlive(*static_cast<PlayerAliveCommand *>(it->get()));
                break;

            case SLOT_STATUS :
                slotStatus(*static_cast<SlotStatusCommand *>(it->get()));
                break;

            case LEAVE_INSTANCE :
                leaveLobby(*static_cast<LeaveInstanceCommand *>(it->get()));
                break;

            default:
                break;
        }
        _commands.erase(it);
    }
}

std::vector<User, std::allocator<User>>::iterator Lobby::getUser(std::string const &name)
{
    auto iterator = _users.begin();
    auto iteEnd = _users.end();
    while (iterator != iteEnd) {
        if (iterator->_name == name) {
            return iterator;
        }
        iterator++;
    }
    return iteEnd;
}

void Lobby::slotStatus(SlotStatusCommand const &cmd)
{
    std::string message;

    int i = 0;
    _mutex.lock();
    while (i < _slots.size()) {
        if (!message.empty()) {
            message += "/";
        }
        if (getUser(_slots[i].userName) != _users.end()) {
            message += getUser(_slots[i].userName)->_name;
            if (getUser(_slots[i].userName)->ready)
                message += ":1";
            else
                message += ":0";
        } else {
            message += "EMPTY";
        }
        i++;
    }
    _mutex.unlock();
    _communicationLobby.send(cmd.userName, "SLOT_STATUS_RESPONSE", message);
}

void Lobby::joinSlot(JoinSlotCommand const &cmd)
{
	std::string name;
    _mutex.lock();

    for (auto &user : _users) {
        if (user._name == cmd.userName) {
            _slots[cmd.slotPosition].userName = user._name;
			switch (cmd.slotPosition)
			{
			case 0:
				name = "Blue";
				break;
			case 1:
				name = "Red";
				break;
			case 2:
				name = "Yellow";
				break;
			case 3:
				name = "Green";
				break;
			default:
				break;
			}
#ifdef _WIN32
			user._ship = loadEntity("./lib/ship" + name + "Server.dll");
#elif defined (linux)
			user._ship = loadEntity("./lib/libship" + name + "Server.so");
#endif


            std::string message;
            message += std::to_string(cmd.slotPosition);
            _mutex.unlock();
            _communicationLobby.send(cmd.userName, "JOIN_SLOT_RESPONSE", message);
            return;
        }
    }
    _mutex.unlock();

}

bool Lobby::leaveSlot(LeaveSlotCommand const &cmd)
{
    int i = 0;

    _mutex.lock();
    while (i < 4) {
        if (getUser(_slots[i].userName)->_name == cmd.userName) {
            _entities.erase(getUser(_slots[i].userName)->_ship);
            getUser(_slots[i].userName)->_ship = "";

            getUser(_slots[i].userName)->ready = false;
            _slots[i].userName = "";
            _mutex.unlock();
            _communicationLobby.send(cmd.userName, "LEAVE_SLOT_RESPONSE", "1");
            return true;
        }
        i++;
    }
    _mutex.unlock();


    return false;
}


void Lobby::playerReady(PlayerReadyCommand const &cmd)
{
    _mutex.lock();
    for (auto &user : _users) {
        if (user._name == cmd.userName) {
            if (cmd.join) {
                user.ready = true;
                _communicationLobby.send(cmd.userName, "PLAYER_READY_RESPONSE", "1");
            } else {
                user.ready = false;
                _communicationLobby.send(cmd.userName, "PLAYER_READY_RESPONSE", "0");
            }
            _mutex.unlock();
            return;
        }
    }
    _mutex.unlock();
}


void Lobby::playerAlive(PlayerAliveCommand const &cmd)
{
    _mutex.lock();
    for (auto &user : _users) {
        if (user._name == cmd.userName) {
            user._lastAliveSign = std::chrono::system_clock::now();
            _mutex.unlock();
            return;
        }
    }
    _mutex.unlock();

}

bool Lobby::leaveLobby(LeaveInstanceCommand const &cmd)
{

    _mutex.lock();
    auto ite = _users.begin();
    auto iteEnd = _users.end();

    while (ite != iteEnd) {
        if (ite->_name == cmd.userName) {
            _communicationLobby.disconnectClient(ite->_name);
            _users.erase(ite);
            _mutex.unlock();
            return true;
        }
        ite++;
    }
    _mutex.unlock();
    return false;
}


void Lobby::createThread()
{

}


void Lobby::sendUpdates()
{

}


std::string Lobby::loadEntity(std::string const &library)
{
    EntityLoader entityLoader(library.data());

    AEntity *entity = entityLoader.load("buildEngine");

    if (entity == nullptr)
        return nullptr;

    std::string pos;
    pos += std::to_string(_id);
	_entities.emplace(pos, entity);
    _id++;
    return pos;
}

bool Lobby::isPlayersReady()
{
    int pos = 0;
    int criticNumberPlayer = 0;

    while (pos < _slots.size()) {
        if (!_slots[pos].userName.empty() && getUser(_slots[pos].userName) != _users.end()) {
            criticNumberPlayer++;
            if (!getUser(_slots[pos].userName)->ready)
                return false;
        }
        pos++;
    }
    if (criticNumberPlayer > 0) {
        _communicationLobby.send("ALL_PLAYER_READY", "1");
        return true;
    }
    return false;
}


//
// Fonction utilisé par le Thread. Il bouclera à l'infini sur cette fonction.
//
void Lobby::getCommands()
{
    for (auto &user : _users) {
//        _commands.emplace_back(user.read());
    }
}

}
