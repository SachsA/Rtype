/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#include <iostream>
#include <sstream>
#include "CommandParser.hpp"

void CommandParser::addClientCmd(std::vector<std::shared_ptr<ACommand>> &commandVector, std::string &cmd)
{
    auto parsedCmd = hashCmd(cmd);

    switch (getTypeCmd(parsedCmd)) {
        case CommandType::VALID_USER : {
            auto ptr = std::make_shared<ValidUserCommand>(parsedCmd[0], parsedCmd[1] != "0");
            commandVector.emplace_back(ptr);
            return;
        }
        case CommandType::LIST_INSTANCES_RESPONSE : {
            auto ptr = std::make_shared<InstancesListResponseCommand>("", parsedCmd[0]);
            commandVector.emplace_back(ptr);
            return;
        }
        case CommandType::JOIN_INSTANCE_RESPONSE : {
            auto ptr = std::make_shared<JoinInstanceResponseCommand>("", parsedCmd[0]);
            commandVector.emplace_back(ptr);
            return;
        }
        case CommandType::CREATE_INSTANCE_RESPONSE : {
            auto ptr = std::make_shared<CreateInstanceResponseCommand>("", parsedCmd[0], parsedCmd[1]);
            commandVector.emplace_back(ptr);
            return;
        }
        case CommandType::DISCONNECT_SERVER: {
            auto ptr = std::make_shared<DisconnectServerCommand>("");
            commandVector.emplace_back(ptr);
            return;
        }
        case CommandType::SLOT_STATUS_RESPONSE : {
            auto ptr = std::make_shared<SlotStatusResponseCommand>("", parsedCmd[0]);
            commandVector.emplace_back(ptr);
            return;
        }
        case CommandType::JOIN_SLOT_RESPONSE : {
            auto ptr = std::make_shared<JoinSlotResponseCommand>("", atoi(parsedCmd[0].data()));
            commandVector.emplace_back(ptr);
            return;
        }
        case CommandType::LEAVE_SLOT_RESPONSE : {
            auto ptr = std::make_shared<LeaveSlotResponseCommand>("", parsedCmd[0] != "0");
            commandVector.emplace_back(ptr);
            return;
        }
        case CommandType::PLAYER_READY_RESPONSE : {
            auto ptr = std::make_shared<PlayerReadyResponseCommand>("", parsedCmd[0] != "0");
            commandVector.emplace_back(ptr);
            return;
        }
        case CommandType::ALL_PLAYER_READY : {
            auto ptr = std::make_shared<AllPlayerReadyCommand>("", parsedCmd[0] != "0");
            commandVector.emplace_back(ptr);
            return;
        }

        default:
            return;
    }
}

void CommandParser::addServerCmd(std::vector<std::shared_ptr<ACommand>> &commandVector, std::string &cmd)
{
    auto parsedCmd = hashCmd(cmd);

    switch (getTypeCmd(parsedCmd)) {
        case CommandType::INPUT_KEY : {
            auto ptr = std::make_shared<KeyInputCommand>(parsedCmd[0], parsedCmd[1]);
            commandVector.emplace_back(ptr);
            return;
        }
        case CommandType::PLAYER_ALIVE : {
            auto ptr = std::make_shared<PlayerAliveCommand>(parsedCmd[0]);
            commandVector.emplace_back(ptr);
            return;
        }
        case CommandType::VALID_USER : {
            auto ptr = std::make_shared<ValidUserCommand>(parsedCmd[0], parsedCmd[1] != "0");
            commandVector.emplace_back(ptr);
            return;
        }
        case CommandType::CREATE_INSTANCE : {
            auto ptr = std::make_shared<CreateInstanceCommand>(parsedCmd[0], parsedCmd[1], parsedCmd[2] != "0");
            commandVector.emplace_back(ptr);
            return;
        }
        case CommandType::JOIN_INSTANCE : {
            auto ptr = std::make_shared<JoinCommand>(parsedCmd[0], parsedCmd[1]);
            commandVector.emplace_back(ptr);
            return;
        }
        case CommandType::LIST_INSTANCES : {
            auto ptr = std::make_shared<InstancesListCommand>(parsedCmd[0]);
            commandVector.emplace_back(ptr);
            return;
        }
        case CommandType::SLOT_STATUS : {
            auto ptr = std::make_shared<SlotStatusCommand>(parsedCmd[0]);
            commandVector.emplace_back(ptr);
            return;
        }
        case CommandType::JOIN_SLOT : {
            auto ptr = std::make_shared<JoinSlotCommand>(parsedCmd[0], atoi(parsedCmd[1].data()));
            commandVector.emplace_back(ptr);
            return;
        }
        case CommandType::LEAVE_SLOT : {
            auto ptr = std::make_shared<LeaveSlotCommand>(parsedCmd[0]);
            commandVector.emplace_back(ptr);
            return;
        }
        case CommandType::LEAVE_INSTANCE : {
            auto ptr = std::make_shared<LeaveInstanceCommand>(parsedCmd[0]);
            commandVector.emplace_back(ptr);
            return;
        }
        case CommandType::PLAYER_READY : {
            auto ptr = std::make_shared<PlayerReadyCommand>(parsedCmd[0], parsedCmd[1] != "0");
            commandVector.emplace_back(ptr);
            return;
        }
        case CommandType::DISCONNECT_CLIENT : {
            auto ptr = std::make_shared<DisconnectClientCommand>(parsedCmd[0]);
            commandVector.emplace_back(ptr);
            return;
        }
        default:
            return;
    }
}

CommandType CommandParser::getTypeCmd(std::vector<std::string> &cmd)
{
    if (cmd.empty())
        return CommandType::UNDEFINED_CMD;
    auto cmdType = cmd.front();
    cmd.erase(cmd.begin());

    if (cmd.size() == 2 && cmdType == "INPUT_KEY") return CommandType::INPUT_KEY;
    if (cmd.size() == 1 && cmdType == "PLAYER_ALIVE") return CommandType::PLAYER_ALIVE;
    if (cmd.size() == 2 && cmdType == "VALID_USER") return CommandType::VALID_USER;
    if (cmd.size() == 3 && cmdType == "CREATE_INSTANCE") return CommandType::CREATE_INSTANCE;
    if (cmd.size() == 2 && cmdType == "CREATE_INSTANCE_RESPONSE") return CommandType::CREATE_INSTANCE_RESPONSE;
    if (cmd.size() == 2 && cmdType == "JOIN_INSTANCE") return CommandType::JOIN_INSTANCE;
    if (cmd.size() == 1 && cmdType == "JOIN_INSTANCE_RESPONSE") return CommandType::JOIN_INSTANCE_RESPONSE;
    if (cmd.size() == 1 && cmdType == "LEAVE_INSTANCE") return CommandType::LEAVE_INSTANCE;
    if (cmd.size() == 1 && cmdType == "LIST_INSTANCES") return CommandType::LIST_INSTANCES;
    if (cmd.size() == 1 && cmdType == "LIST_INSTANCES_RESPONSE") return CommandType::LIST_INSTANCES_RESPONSE;
    if (cmd.size() == 1 && cmdType == "SLOT_STATUS") return CommandType::SLOT_STATUS;
    if (cmd.size() == 1 && cmdType == "SLOT_STATUS_RESPONSE") return CommandType::SLOT_STATUS_RESPONSE;
    if (cmd.size() == 2 && cmdType == "JOIN_SLOT") return CommandType::JOIN_SLOT;
    if (cmd.size() == 1 && cmdType == "JOIN_SLOT_RESPONSE") return CommandType::JOIN_SLOT_RESPONSE;
    if (cmd.size() == 1 && cmdType == "LEAVE_SLOT") return CommandType::LEAVE_SLOT;
    if (cmd.size() == 1 && cmdType == "LEAVE_SLOT_RESPONSE") return CommandType::LEAVE_SLOT_RESPONSE;
    if (cmd.size() == 2 && cmdType == "PLAYER_READY") return CommandType::PLAYER_READY;
    if (cmd.size() == 1 && cmdType == "PLAYER_READY_RESPONSE") return CommandType::PLAYER_READY_RESPONSE;
    if (cmd.size() == 1 && cmdType == "ALL_PLAYER_READY") return CommandType::ALL_PLAYER_READY;
    if (cmd.size() == 1 && cmdType == "LEAVE_SERVER") return CommandType::DISCONNECT_CLIENT;
    if (cmd.size() == 0 && cmdType == "DISCONNECT_SERVER") return CommandType::DISCONNECT_SERVER;
    return CommandType::UNDEFINED_CMD;
}


void CommandParser::addGameServerCmd(std::vector<std::shared_ptr<ACommand>> &commandVector, std::string &cmd)
{
    auto parsedCmd = hashCmd(cmd);

    switch (getGameTypeCmd(parsedCmd)) {
        case CommandType::INPUT_KEY : {
            auto ptr = std::make_shared<KeyInputCommand>(parsedCmd[0], parsedCmd[1]);
            commandVector.emplace_back(ptr);
            return;
        }
        default:
            return;

    }
}

void CommandParser::addGameClientCmd(std::vector<std::shared_ptr<ACommand>> &commandVector, std::string &cmd)
{
    auto parsedCmd = hashCmd(cmd);

    switch (getGameTypeCmd(parsedCmd)) {
        case CommandType::GAME_PLAYER_STATUS : {
            auto ptr = std::make_shared<PlayerStatusCommand>(parsedCmd[0]);
            commandVector.emplace_back(ptr);
            return;
        }
        case CommandType::UPDATE_ENTITY : {
            auto ptr = std::make_shared<UpdateEntityCommand>(parsedCmd[0], parsedCmd[1],
                                                             Vector2D<double>(atof(parsedCmd[2].data()),
                                                                              atof(parsedCmd[3].data())));
            commandVector.emplace_back(ptr);
            return;
        }
        case CommandType::END_GAME : {
            auto ptr = std::make_shared<EndGameCommand>();
            commandVector.emplace_back(ptr);
            return;
        }
        default:
            return;

    }
}

CommandType CommandParser::getGameTypeCmd(std::vector<std::string> &cmd)
{
    if (cmd.empty())
        return CommandType::UNDEFINED_CMD;
    auto cmdType = cmd.front();
    cmd.erase(cmd.begin());

    if (cmd.size() == 2 && cmdType == "INPUT_KEY") return CommandType::INPUT_KEY;
    if (cmd.size() == 1 && cmdType == "GAME_PLAYER_ALIVE") return CommandType::GAME_PLAYER_ALIVE;
    if (cmd.size() == 1 && cmdType == "GAME_PLAYER_STATUS") return CommandType::GAME_PLAYER_STATUS;
    if (cmd.size() == 4 && cmdType == "UPDATE_ENTITY") return CommandType::UPDATE_ENTITY;
    if (cmd.size() == 1 && cmdType == "DISCONNECT_CLIENT") return CommandType::DISCONNECT_CLIENT;
    if (cmd.size() == 0 && cmdType == "DISCONNECT_SERVER") return CommandType::DISCONNECT_SERVER;
    if (cmd.size() == 0 && cmdType == "END_GAME") return CommandType::END_GAME;
    return CommandType::UNDEFINED_CMD;
}

std::vector<std::string> CommandParser::hashCmd(std::string const &cmd)
{
    std::vector<std::string> parsedCmd;
    std::string str;
    std::istringstream stream(cmd);

    while (getline(stream, str, ';')) {
        parsedCmd.push_back(str);
    }
    return parsedCmd;
}