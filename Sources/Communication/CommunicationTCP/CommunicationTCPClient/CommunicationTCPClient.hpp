/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#ifndef CPP_RTYPE_2018_COMMUNICATIONTCPCLIENT_HPP
#define CPP_RTYPE_2018_COMMUNICATIONTCPCLIENT_HPP

#include <memory>
#include <vector>
#include "../../../Commands/ACommand.hpp"
#include "../../Sockets/SocketTcp/Server/SocketTcpServer.hpp"
#include "../../Sockets/SocketTcp/Client/SocketTcpClient.hpp"
#include "../../../Commands/CommandParser/CommandParser.hpp"

class CommunicationTCPClient {
public:
    CommunicationTCPClient(std::string const &ip, std::string const &port);
    CommunicationTCPClient();
    ~CommunicationTCPClient() = default;

    void mainLoopThread();

    bool send(std::string const &, std::string const &, std::string const &);
    bool send(std::string const &);
    std::vector<std::shared_ptr<ACommand>> receive();
    bool initialisation(std::string const &, std::string const &);

	bool decoClient();


private:
    int ret;
    fd_set rdfs;
    SOCKET sockFd;
    SocketTcpClient socket;
    CommandParser parser;
};


#endif //CPP_RTYPE_2018_COMMUNICATIONTCPCLIENT_HPP
