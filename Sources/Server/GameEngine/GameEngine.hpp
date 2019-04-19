/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#ifndef CPP_RTYPE_2018_GAMEENGINE_HPP
#define CPP_RTYPE_2018_GAMEENGINE_HPP

#include <vector>
#include <mutex>
#include <unordered_map>

#include "../../Communication/CommunicationUDP/CommunicationUDPServer/CommunicationUDPServer.hpp"

#include "../../Commands/ACommand.hpp"
#include "../GameInstance/GameInstanceStatus.hpp"

#include "../User/User.hpp"
#include "Entities/AEntity.hpp"
#include "Game/Game.hpp"
#include "Lobby/Lobby.hpp"


namespace GameEngine {


class GameEngine {
public:
    explicit GameEngine(std::vector<User> &users, std::mutex &instanceMutex);
    virtual ~GameEngine() = default;

public:
    GameInstanceStatus lobby(CommunicationTCPServer &, CommunicationTCPServer &);
    GameInstanceStatus game(CommunicationTCPServer &, CommunicationUDPServer &);

private:
    std::vector<User> &_users;
    std::unordered_map<std::string, AEntity *> _entities;
    int _id;
    std::mutex &_mutex;
};

}

#endif //CPP_RTYPE_2018_GAMEENGINE_HPP
