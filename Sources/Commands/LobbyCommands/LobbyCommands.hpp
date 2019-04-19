/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#ifndef CPP_RTYPE_2018_LOBBYCOMMANDS_HPP
#define CPP_RTYPE_2018_LOBBYCOMMANDS_HPP

#include <string>
#include "../ACommand.hpp"

struct JoinSlotCommand : public ACommand {
    JoinSlotCommand(std::string const &name, const int pos) : ACommand(CommandType::JOIN_SLOT, name)
    {
        slotPosition = pos;
    };
    int slotPosition;
};


struct LeaveSlotCommand : public ACommand {
    LeaveSlotCommand(std::string const &name) : ACommand(CommandType::LEAVE_SLOT, name)
    {
    };
};

struct PlayerReadyCommand : public ACommand {
    PlayerReadyCommand(std::string const &name, bool joinrequest) : ACommand(CommandType::PLAYER_READY, name)
    {
        join = joinrequest;
    };
    bool join;
};

struct PlayerAliveCommand : public ACommand {
    PlayerAliveCommand(std::string const &name) : ACommand(CommandType::PLAYER_ALIVE, name)
    {};
};

struct SlotStatusCommand : public ACommand {
    SlotStatusCommand(std::string const &name) : ACommand(CommandType::SLOT_STATUS, name)
    {};
};

struct LeaveInstanceCommand : public ACommand {
    LeaveInstanceCommand(std::string const &name) : ACommand(CommandType::LEAVE_INSTANCE, name)
    {
    };
};

// OUTPUT SERVER


struct AllPlayerReadyCommand : public ACommand {
    AllPlayerReadyCommand(std::string const &name, bool confirmation) : ACommand(CommandType::ALL_PLAYER_READY, name)
    {
        validation = confirmation;
    };
    bool validation;
};

struct JoinSlotResponseCommand : public ACommand {
    JoinSlotResponseCommand(std::string const &name, int const pos) : ACommand(CommandType::JOIN_SLOT_RESPONSE, name)
    {
        slotPos = pos;
    };
    int slotPos;
};

struct LeaveSlotResponseCommand : public ACommand {
    LeaveSlotResponseCommand(std::string const &name, bool const confirmation) : ACommand(CommandType::LEAVE_SLOT_RESPONSE, name)
    {
        validation = confirmation;
    };
    bool validation;
};

struct PlayerReadyResponseCommand : public ACommand {
    PlayerReadyResponseCommand(std::string const &name, bool confirmation) : ACommand(
        CommandType::PLAYER_READY_RESPONSE, name)
    {
        validation = confirmation;
    };
    bool validation;
};

struct SlotStatusResponseCommand : public ACommand {
    SlotStatusResponseCommand(std::string const &name, std::string cmdBody) : ACommand(
        CommandType::SLOT_STATUS_RESPONSE, name)
    {
        body = cmdBody;
    };
    std::string body;
};


#endif //CPP_RTYPE_2018_LOBBYCOMMANDS_HPP
