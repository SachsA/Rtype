/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#include <iostream>
#include "GameEngine.hpp"

namespace GameEngine {

GameEngine::GameEngine(std::vector<User> &users, std::mutex &instanceMutex)
    : _users(users), _mutex(instanceMutex), _id(0)
{

}

GameInstanceStatus GameEngine::lobby(CommunicationTCPServer &serverCom, CommunicationTCPServer &lobbyCom) {
    Lobby lobby(_users, _entities, serverCom, lobbyCom, _mutex, _id);

    return lobby.menuLoop();
}

GameInstanceStatus GameEngine::game(CommunicationTCPServer &serverCom, CommunicationUDPServer &gameCom) {
    Game game(_users, _entities, serverCom, gameCom, _mutex, _id);

    return game.menuLoop();
}

}