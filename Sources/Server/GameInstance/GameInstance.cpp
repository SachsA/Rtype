//
// EPITECH PROJECT, 2018
// cpp_rtype
// File description:
// GameInstance's functions
//


#include <iostream>
#include "GameInstance.hpp"

#ifdef _WIN32
//INCLUDE POUR WINDOWS
#elif defined (linux)

#include <unistd.h>

#endif

GameInstance::GameInstance(CommunicationTCPServer &serverCom, std::string const &port, bool publicStatus)
    : status(GameInstanceStatus::LOBBY), gameEngine(_users, mutex), _communicationServer(serverCom),
      _communicationLobby(port + "0"), _communicationGame(port + "1"), isPublic(publicStatus)
{

}

GameInstance::GameInstance(GameInstance const &original)
    : status(original.status), _users(original._users), gameEngine(_users, mutex),
      _communicationServer(original._communicationServer),
      _communicationLobby(original._communicationLobby._port), _communicationGame(original._communicationGame._port)
{

}

GameInstance &GameInstance::operator=(GameInstance const &original)
{
    _users = original._users;
    status = original.status;
    return *this;
}

void GameInstance::mainLoopThread(void *ptr)
{
    auto instancesArray = static_cast<std::unordered_map<std::string, GameInstance> *>(ptr);

    int i = 0;

    mutex.lock();
    while (status != EXIT && !_users.empty()) {
        mutex.unlock();
        if (status == GameInstanceStatus::LOBBY) {
            status = gameEngine.lobby(_communicationServer, _communicationLobby);
        } else if (status == GameInstanceStatus::GAME) {
            status = gameEngine.game(_communicationServer, _communicationGame);
        }
        mutex.lock();
    }
    mutex.unlock();
}

bool GameInstance::addPlayerToGame(User const &user)
{
    mutex.lock();
    for (auto &player : _users) {
        if (player._name == user._name) {
            mutex.unlock();
            return false;
        }
    }
    _users.emplace_back(user);
    mutex.unlock();
    return true;
}
