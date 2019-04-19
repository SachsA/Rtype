/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#include <iostream>
#include <thread>
#include <random>
#include "Game.hpp"

namespace GameEngine {

Game::Game(std::vector<User> &users, std::unordered_map<std::string, AEntity *> &entities,
    CommunicationTCPServer &serverCom,
    CommunicationUDPServer &gameCom, std::mutex &instanceMutex, int &id)
    : _users(users), _entities(entities), _time(std::chrono::system_clock::now()), _lastPopEnemy(std::chrono::system_clock::now()), _communicationServer(serverCom),
      _communicationGame(gameCom), _mutex(instanceMutex), _id(id), _leaving(false)
{

}

Game::~Game()
{

}

auto Game::getEntity(std::string const &name)
{
    auto iterator = _entities.begin();
    auto iteEnd = _entities.end();
    while (iterator != iteEnd) {
        if (iterator->first == name) {
            return iterator;
        }
        iterator++;
    }
    return iteEnd;
}

bool Game::isUpdateTime(int fpms)
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

bool Game::loadEntity(std::string const &library)
{
#ifdef _WIN32
	std::string libName = "./lib/" + library + "Server.dll";
#elif defined (linux)
	std::string libName = "./lib/lib" + library + "Server.so";
#endif
    EntityLoader entityLoader(libName.data());

    AEntity *entity = entityLoader.load("buildEngine");

    if (entity == nullptr)
        return false;

    _entities.emplace(std::to_string(_id), entity);
    _id++;

    return true;
}


GameInstanceStatus Game::menuLoop()
{
    std::thread thread(&Game::mainLoopThread, this);

    while (!_users.empty() && !gameOver()) {
        getCommands();
        update();
        deleteUselessEntities();
        sendUpdates();
    }
    _mutex.lock();
    _leaving = true;
    thread.join();
    _mutex.unlock();
    _communicationGame.send("END_GAME", "");
    _communicationGame.send("END_GAME", "");
    _communicationGame.send("END_GAME", "");
    return GameInstanceStatus::LOBBY;
}

bool Game::gameOver()
{
    _mutex.lock();


    auto it = _users.begin();

    while (it != _users.end()) {
        auto itEntity = getEntity(it->_ship);
        if (itEntity != _entities.end() && itEntity->second->getHP() > 0) {
            _mutex.unlock();
            return false;
        }
        it++;
    }
    _mutex.unlock();
    return true;
}

void Game::getCommands()
{
    _commandMutex.lock();
    auto it = _commands.begin();

    while (!_commands.empty()) {
        switch (it->get()->commandType) {
            case INPUT_KEY :
                inputKey(*static_cast<KeyInputCommand *>(it->get()));
                break;
            case GAME_PLAYER_ALIVE :
                playerAlive(*static_cast<PlayerAliveCommand *>(it->get()));
                break;
            case DISCONNECT_CLIENT :
                disconnectClient(*static_cast<DisconnectClientCommand *>(it->get()));
                break;
            case CREATE_LIBRARY :
                createLibraryCommand(*static_cast<CreateLibraryCommand *>(it->get()));
                break;
            default:
                break;
        }
        _commands.erase(it);
    }
    _commandMutex.unlock();
}

void Game::inputKey(KeyInputCommand const &cmd)
{
    if (cmd.key == "KEY_UP") {
        if (getEntity(getUser(cmd.userName)->_ship) != _entities.end())
            getEntity(getUser(cmd.userName)->_ship)->second->setUpdate(MoveUpCommand());
    } else if (cmd.key == "KEY_DOWN") {
        if (getEntity(getUser(cmd.userName)->_ship) != _entities.end())
            getEntity(getUser(cmd.userName)->_ship)->second->setUpdate(MoveDownCommand());
    } else if (cmd.key == "KEY_LEFT") {
        if (getEntity(getUser(cmd.userName)->_ship) != _entities.end()) {
            getEntity(getUser(cmd.userName)->_ship)->second->setUpdate(MoveLeftCommand());
        }
    } else if (cmd.key == "KEY_RIGHT") {
        if (getEntity(getUser(cmd.userName)->_ship) != _entities.end()) {
            getEntity(getUser(cmd.userName)->_ship)->second->setUpdate(MoveRightCommand());
        }
    } else if (cmd.key == "KEY_SPACE") {
        if (getEntity(getUser(cmd.userName)->_ship) != _entities.end())
            getEntity(getUser(cmd.userName)->_ship)->second->setUpdate(AttackCommand());
    }
}

void Game::playerAlive(PlayerAliveCommand const &cmd)
{}

void Game::disconnectClient(DisconnectClientCommand const &cmd)
{}

void Game::createLibraryCommand(CreateLibraryCommand const &cmd)
{
    loadEntity(cmd.name);
    _entities[std::to_string(_id - 1)]->setCreationPosition(cmd.pos);
    _entities[std::to_string(_id - 1)]->setCreationDate(cmd.spawnTime);
}

std::vector<User, std::allocator<User>>::iterator Game::getUser(std::string const &name)
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

void Game::update()
{
    popRandomEntities();
    for (auto &entity : _entities) {
        auto cmd = entity.second->getUpdate();
        if (!cmd.empty())
            _commands.insert(_commands.begin(), cmd.begin(), cmd.end());
    }
    checkCollisions();
}


void Game::popRandomEntities()
{
    auto now = std::chrono::system_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(now - _lastPopEnemy);

    std::random_device r;
    std::default_random_engine randomEngine(r());
    std::uniform_int_distribution<int> distribution(1, 3);
    int entityLevel = distribution(randomEngine);

    if (diff.count() > 5000) {
        std::string lib;

        if (entityLevel == 1)
            lib = "alienAlpha";
        else if (entityLevel == 2)
            lib = "alienBeta";
        else if (entityLevel == 3)
            lib = "alienDelta";
        _commands.emplace_back(std::make_shared<CreateLibraryCommand>(lib, Vector2D<double>(1800.0, 500.0), now));

        _lastPopEnemy = now;
    }
}

void Game::sendUpdates()
{
    for (auto &entity : _entities) {
        _communicationGame.send("UPDATE_ENTITY", entity.first + ";" + entity.second->getType() + ";" +
                                                 std::to_string(entity.second->getPosition().x) + ";" +
                                                 std::to_string(entity.second->getPosition().y));

    }
}

bool Game::checkCollisions()
{
    auto firstIterator = _entities.begin();
    auto itEnd = _entities.end();

    while (firstIterator != itEnd) {
        auto secondIterator = firstIterator;
        secondIterator++;
        while (secondIterator != itEnd) {
            if (isCollide(*firstIterator->second, *secondIterator->second)) {
                updateEntitiesAfterImpact(*firstIterator->second, *secondIterator->second);
                return true;
            }
            secondIterator++;
        }
        firstIterator++;
    }
    return false;
}

bool Game::isCollide(AEntity const &first, AEntity const &second)
{
    auto minFirst = Vector2D<float>(first.getPosition().x,
                                    first.getPosition().y);
    auto maxFirst = Vector2D<float>(first.getPosition().x + first.getHitBox().botRightCorner.x,
                                    first.getPosition().y + first.getHitBox().botRightCorner.y);
    auto minSecond = Vector2D<float>(second.getPosition().x,
                                     second.getPosition().y);
    auto maxSecond = Vector2D<float>(second.getPosition().x + second.getHitBox().botRightCorner.x,
                                     second.getPosition().y + second.getHitBox().botRightCorner.y);

    if (first.getHP() == 0 || second.getHP() == 0)
        return false;

    if (((minFirst.y <= minSecond.y && maxFirst.y > minSecond.y) ||
         (minSecond.y <= minFirst.y && maxSecond.y > minFirst.y)) &&
        ((minFirst.x <= minSecond.x && maxFirst.x > minSecond.x) ||
         (minSecond.x <= minFirst.x && maxSecond.x > minFirst.x))) {
        return true;
    }
    return false;
}

void Game::updateEntitiesAfterImpact(AEntity &first, AEntity &second)
{
    first.takeDamage(second);
    second.takeDamage(first);
}

void Game::deleteUselessEntities()
{
    auto it = _entities.begin();

    while (!_entities.empty() && it != _entities.end()) {
        if ((it->second->getPosition().x  < -400) ||
            (it->second->getPosition().x > 2500)) {
            _entities.erase(it->first);
            return;
        }
        if (it->second->getHP() <= 0) {
            it->second->setPosition(Vector2D<double>(-400, -400));
            _communicationGame.send("UPDATE_ENTITY", it->first + ";" + it->second->getType() + ";" +
                                                     std::to_string(it->second->getPosition().x) + ";" +
                                                     std::to_string(it->second->getPosition().y));
            return;
        }
        it++;
    }
}

void Game::mainLoopThread()
{
    _mutex.lock();
    while (!_users.empty() && !_leaving) {
        _mutex.unlock();
        auto cmd = _communicationGame.receive();
        _commandMutex.lock();
        while (!cmd.empty()) {
            if (!checkDuplicate(_commands, cmd.front()))
                _commands.emplace_back(cmd.front());
            cmd.erase(cmd.begin());
        }
        _commandMutex.unlock();
    }
    _mutex.unlock();
}

bool Game::checkDuplicate(std::vector<std::shared_ptr<ACommand>> const &commands, std::shared_ptr<ACommand> const &node)
{
    for (auto &command : commands) {
        if (command->commandType == node->commandType && command->userName == node->userName) {
            if (command->commandType == INPUT_KEY) {
                auto cmd1 = *static_cast<KeyInputCommand *>(&(*command));
                auto cmd2 = *static_cast<KeyInputCommand *>(&(*node));
                if (cmd1.key == cmd2.key) {
                    return true;
                }
            }
        }
    }
    return false;
}

}