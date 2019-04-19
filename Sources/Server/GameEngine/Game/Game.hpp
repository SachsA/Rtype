/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#ifndef CPP_RTYPE_2018_GAME_HPP
#define CPP_RTYPE_2018_GAME_HPP

#include <vector>
#include <string>
#include <mutex>
#include <unordered_map>

#include "../../../Communication/CommunicationTCP/CommunicationTCPServer/CommunicationTCPServer.hpp"
#include "../../../Communication/CommunicationUDP/CommunicationUDPServer/CommunicationUDPServer.hpp"

#include "../Entities/AEntity.hpp"
#include "../../GameInstance/GameInstanceStatus.hpp"
#include "../LibLoader/LibLoader.hpp"
#include "../../User/User.hpp"

namespace GameEngine {

class Game {
public:
    Game(std::vector<User> &users,  std::unordered_map<std::string, AEntity *> &entities, CommunicationTCPServer &serverCom, CommunicationUDPServer &gameCom, std::mutex &mutex, int &_id);
    ~Game();

public:
    GameInstanceStatus menuLoop();
    void mainLoopThread();

private:
    bool loadEntity(std::string const &library);
    void getCommands();
    void update();
    void sendUpdates();
    bool gameOver();
    bool checkCollisions();
    bool isCollide(AEntity const &first, AEntity const &second);
    void updateEntitiesAfterImpact(AEntity &first, AEntity &second);
    void deleteUselessEntities();
    bool isUpdateTime(int fpms);
    void popRandomEntities();

    void inputKey(KeyInputCommand const &cmd);
    void playerAlive(PlayerAliveCommand const &cmd);
    void disconnectClient(DisconnectClientCommand const &cmd);
    void createLibraryCommand(CreateLibraryCommand const &cmd);

    std::vector<User, std::allocator<User>>::iterator getUser(std::string const &name);
    auto getEntity(std::string const &name);


    bool checkDuplicate(std::vector<std::shared_ptr<ACommand>> const &, std::shared_ptr<ACommand> const &);

    std::vector<User> &_users;
    std::unordered_map<std::string, AEntity *> &_entities;
    std::vector<std::shared_ptr<ACommand>> _commands;
    std::chrono::time_point<std::chrono::system_clock> _time;
    std::chrono::time_point<std::chrono::system_clock> _lastPopEnemy;

    CommunicationTCPServer &_communicationServer;
    CommunicationUDPServer &_communicationGame;

    std::mutex &_mutex;
    std::mutex _commandMutex;
    int &_id;
    bool _leaving;


};

}

#endif //CPP_RTYPE_2018_GAME_HPP
