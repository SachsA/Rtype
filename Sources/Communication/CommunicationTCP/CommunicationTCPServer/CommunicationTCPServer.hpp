/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#ifndef CPP_RTYPE_2018_COMMUNICATIONTCPSERVER_HPP
#define CPP_RTYPE_2018_COMMUNICATIONTCPSERVER_HPP

#include <memory>
#include <vector>

#include "../../Sockets/SocketTcp/Server/SocketTcpServer.hpp"
#include "../../../Commands/CoreCommands/CoreCommand.hpp"
#include "../../../Commands/CommandParser/CommandParser.hpp"


class CommunicationTCPServer {
public:
    CommunicationTCPServer(std::string const &port);
    ~CommunicationTCPServer() = default;

    void mainLoopThread();

    bool send(std::string const &, std::string const &, std::string const &);
    bool send(std::string const &, std::string const &);
    std::vector<std::shared_ptr<ACommand>> receive();
    bool disconnectClient(std::string const &userName);

    std::string _port;
private:
    int max;
    fd_set rdfs;
    std::string _url;
    SOCKET sockFd;
    std::vector<std::shared_ptr<TcpClient>> _clients;
    SocketTcpServer socket;
    CommandParser parser;
};


#endif //CPP_RTYPE_2018_COMMUNICATIONTCPSERVER_HPP
