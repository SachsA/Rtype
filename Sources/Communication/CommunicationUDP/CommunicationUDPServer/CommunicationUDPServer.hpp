/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#ifndef CPP_RTYPE_2018_COMMUNICATIONUDPSERVER_HPP
#define CPP_RTYPE_2018_COMMUNICATIONUDPSERVER_HPP

#include <memory>
#include <vector>

#include "../../Sockets/SocketUdp/Server/SocketUdpServer.hpp"
#include "../../../Commands/CoreCommands/CoreCommand.hpp"
#include "../../../Commands/CommandParser/CommandParser.hpp"


class CommunicationUDPServer {
public:
    CommunicationUDPServer(std::string const &port);
    ~CommunicationUDPServer() = default;

    bool send(std::string const &, std::string const &, std::string const &);
    bool send(std::string const &, std::string const &);
    std::vector<std::shared_ptr<ACommand>> receive();

    unsigned long getNbClient();

    std::string _port;

private:
    fd_set rdfs;
    std::string _url;
    SOCKET sockFd;
    std::vector<UdpClient> _clients;
    SocketUdpServer socket;
    CommandParser parser;
};

#endif //CPP_RTYPE_2018_UDPCOMMUNICATIONSERVER_HPP
