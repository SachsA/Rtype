//
// EPITECH PROJECT, 2018
// cpp_rtype
// File description:
// server's core functions
//

#include <sstream>
#include <iostream>
#include "CoreServer.hpp"
#include "../../Client/Constants/Constants.hpp"

CoreServer::CoreServer()
    : _communication(SERVER_PORT()), _id(0)
{}

CoreServer::~CoreServer()
{
    for (auto &instance : _gameInstances) {
        instance.second->mutex.lock();
        instance.second->status = EXIT;
        instance.second->mutex.unlock();
    }
}

void CoreServer::mainLoop()
{
    bool isRunning = true;

    while (isRunning) {
        auto cmd = _communication.receive();

        while (cmd.size() > 0) {
            handleCmd(*cmd.front());
            cmd.erase(cmd.begin());
        }
    }
}


void CoreServer::handleCmd(ACommand &cmd)
{
    switch (cmd.commandType) {
        case JOIN_INSTANCE:
            joinGameInstance(*static_cast<JoinCommand *>(&cmd));
            break;
        case DISCONNECT_CLIENT:
            disconnectClient(*static_cast<DisconnectClientCommand *>(&cmd));
            break;
        case CREATE_INSTANCE:
            createGameInstance(*static_cast<CreateInstanceCommand *>(&cmd));
            break;
        case LIST_INSTANCES:
            instancesList(*static_cast<InstancesListCommand *>(&cmd));
            break;
        default:
            break;
    }
}


void CoreServer::joinGameInstance(JoinCommand const &cmd)
{
    if (addPlayerToGame(User(cmd.userName), cmd.serverName)) {
        for (auto &instance : _gameInstances) {
            if (instance.first == cmd.serverName) {
				if (!_communication.send(cmd.userName, "JOIN_INSTANCE_RESPONSE", instance.second->_communicationLobby._port.substr(0, 3)))
					break;
            }
        }
    } else {
        _communication.send(cmd.userName, "JOIN_INSTANCE_RESPONSE", "-1");
    }
}


void CoreServer::createGameInstance(CreateInstanceCommand const &cmd)
{
    if (_gameInstances.size() > 100) {
        _communication.send(cmd.userName, "CREATE_INSTANCE_RESPONSE", cmd.serverName + ";-1");
        return;
    }

    for(auto &instance : _gameInstances) {
        if (instance.first == cmd.serverName) {
            _communication.send(cmd.userName, "CREATE_INSTANCE_RESPONSE", cmd.serverName + ";-1");
            return;
        }
    }

    std::stringstream strstream;
    strstream <<  "7";
    if (_id < 10)
        strstream << 0;
    strstream << _id;
    _id++;

    std::string port;
    strstream >> port;
    while (port.size() < 3) {
        port.append("0");
    }

    _gameInstances.emplace(cmd.serverName, new GameInstance(_communication, port, cmd.isPublic));

    addPlayerToGame(User(cmd.userName), cmd.serverName);
    _communication.send(cmd.userName, "CREATE_INSTANCE_RESPONSE", cmd.serverName + ";" + port);

    _threadPool.createThread(_gameInstances.at(cmd.serverName), &_gameInstances);

}


void CoreServer::instancesList(InstancesListCommand const &cmd)
{
    std::string strBuf;
    auto ite = _gameInstances.begin();
    auto iteEnd = _gameInstances.end();

    while (ite != iteEnd) {
        if (ite->second->status == GameInstanceStatus::EXIT || ite->second->_users.empty()) {
            _gameInstances.erase(ite);
        }
        ite++;
    }

    for (auto node : _gameInstances) {
        if (node.second->status == GameInstanceStatus::EXIT)
            continue;

        if (strBuf.size() > 0) {
            strBuf.append(":");
        }
        if (node.second->isPublic && node.second->status == GameInstanceStatus::LOBBY)
            strBuf.append(node.first);
    }

    if (strBuf.length() == 0) {
        strBuf = "EMPTY";
    }
    _communication.send(cmd.userName, "LIST_INSTANCES_RESPONSE", strBuf);
}


bool CoreServer::addPlayerToGame(const User &user, const std::string &serverName)
{
    auto gameInstanceIterator = _gameInstances.find(serverName);

    if (gameInstanceIterator != _gameInstances.end()) {
        if (!gameInstanceIterator->second->addPlayerToGame(user)) {
            return false;
        }
        return true;
    }
    return false;
}


void CoreServer::disconnectClient(DisconnectClientCommand const &cmd)
{
    _communication.disconnectClient(cmd.userName);
}