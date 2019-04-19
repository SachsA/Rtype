/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#ifndef CPP_RTYPE_2018_LOBBY_HPP
#define CPP_RTYPE_2018_LOBBY_HPP

#include <array>
#include <vector>
#include <mutex>
#include <unordered_map>

//#include "../../../Communication/CommunicationTCP/CommunicationTCPClient/CommunicationTCPClient.hpp"
#include "../../../Communication/CommunicationTCP/CommunicationTCPServer/CommunicationTCPServer.hpp"

#include "../../GameInstance/GameInstanceStatus.hpp"
#include "../../User/User.hpp"
#include "../Entities/AEntity.hpp"
#include "../../../Commands/ACommand.hpp"
#include "../../../Commands/LobbyCommands/LobbyCommands.hpp"
#include "Slots/Slot.hpp"
#include "../LibLoader/LibLoader.hpp"

namespace GameEngine {

class Lobby {
public:
    Lobby(std::vector<User> &users, std::unordered_map<std::string, AEntity *> &entities, CommunicationTCPServer &serverCom,
        CommunicationTCPServer &lobbyCom, std::mutex &mutex, int &_id);
    ~Lobby() = default;

public:
    GameInstanceStatus menuLoop();

private:
    bool isPlayersReady();
    void getCommands();
    void getUpdates();
    void update();
    void sendUpdates();

    void slotStatus(SlotStatusCommand const &cmd);
    void joinSlot(JoinSlotCommand const &cmd);
    bool leaveSlot(LeaveSlotCommand const &cmd);
    bool leaveLobby(LeaveInstanceCommand const &cmd);
    void playerReady(PlayerReadyCommand const &cmd);
    void playerAlive(PlayerAliveCommand const &cmd);
    bool isUpdateTime(int fpms);

    std::vector<User, std::allocator<User>>::iterator getUser(std::string const &name);

    std::string loadEntity(std::string const &library);

    void createThread();

    std::vector<Slot> _slots;
    std::vector<User> &_users;
    std::unordered_map<std::string, AEntity *> &_entities;
    std::vector<std::shared_ptr<ACommand>> _commands;
    std::chrono::time_point<std::chrono::system_clock> _time;

    CommunicationTCPServer &_communicationServer;
    CommunicationTCPServer &_communicationLobby;
    std::mutex &_mutex;
    int &_id;
};

}

#endif //CPP_RTYPE_2018_LOBBY_HPP
