/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#ifndef CPP_RTYPE_2018_GAMECOMMAND_HPP
#define CPP_RTYPE_2018_GAMECOMMAND_HPP

#include <string>
#include "../ACommand.hpp"

// INPUT SERVER

struct JoinCommand : public ACommand {
    JoinCommand(std::string const &name, std::string const &server) : ACommand(CommandType::JOIN_INSTANCE, name) {
        serverName = server;
    };

    std::string serverName;
};

struct CreateInstanceCommand : public ACommand
{
    CreateInstanceCommand(std::string const &name, std::string const &server, bool publicStatus) : ACommand(CommandType::CREATE_INSTANCE, name) {
        isPublic = publicStatus;
        serverName = server;
    };

    std::string serverName;
    bool isPublic;
};

struct InstancesListCommand : public ACommand
{
    InstancesListCommand(std::string const &name) : ACommand(CommandType::LIST_INSTANCES, name) {

    };

};

struct DisconnectClientCommand : public ACommand {
    DisconnectClientCommand(std::string const &name) : ACommand(CommandType::DISCONNECT_CLIENT, name) {
    };
};

// OUTPUT SERVER

struct InstancesListResponseCommand : public ACommand
{
    InstancesListResponseCommand(std::string const &name, std::string const &body) : ACommand(CommandType::LIST_INSTANCES_RESPONSE, name) {
        instanceList = body;
    };
    std::string instanceList;
};


struct ValidUserCommand : public ACommand
{
    ValidUserCommand(std::string const &name, bool const &confirmation) : ACommand(CommandType::VALID_USER, name) {
        accept = confirmation;
    };
    bool accept;
};

struct CreateInstanceResponseCommand : public ACommand
{
    CreateInstanceResponseCommand(std::string const &name, std::string const &server, std::string const serverPort) : ACommand(CommandType::CREATE_INSTANCE_RESPONSE, name) {
        serverName = server;
        port = serverPort;
    };

    std::string port;
    std::string serverName;
};

struct JoinInstanceResponseCommand : public ACommand {
    JoinInstanceResponseCommand(std::string const &name, std::string const &port) : ACommand(CommandType::JOIN_INSTANCE_RESPONSE, name) {
        serverPort = port;
    };

    std::string serverPort;
};

struct DisconnectServerCommand : public ACommand {
	DisconnectServerCommand(std::string const &name) : ACommand(CommandType::DISCONNECT_SERVER, name) {
	};
};

#endif //CPP_RTYPE_2018_GAMECOMMAND_HPP
