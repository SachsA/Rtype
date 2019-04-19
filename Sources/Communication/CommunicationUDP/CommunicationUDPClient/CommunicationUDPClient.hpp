/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#ifndef CPP_RTYPE_2018_COMMUNICATIONUDPCLIENT_HPP
#define CPP_RTYPE_2018_COMMUNICATIONUDPCLIENT_HPP

#include <vector>
#include <memory>
#include "../../Sockets/SocketUdp/Client/SocketUdpClient.hpp"
#include "../../../Commands/ACommand.hpp"
#include "../../../Commands/CommandParser/CommandParser.hpp"

class CommunicationUDPClient {
public:
    CommunicationUDPClient(std::string const &ip, std::string const &port);
    CommunicationUDPClient();
    ~CommunicationUDPClient() = default;

    void mainLoopThread();
    bool send(std::string const &, std::string const &, std::string const &);
    bool send(std::string const &);
    std::vector<std::shared_ptr<ACommand>> receive();
    void initialisation(std::string const &, std::string const &);

private:
    SocketUdpClient socket;

    fd_set rdfs;

    SOCKET sockFd;
    SOCKADDR_IN _sin;
    CommandParser parser;
//    std::vector<std::unique_ptr<ACommand>> sending;
//    std::vector<std::unique_ptr<ACommand>> reception;

};

#endif //CPP_RTYPE_2018_COMMUNICATIONUDPCLIENT_HPP
