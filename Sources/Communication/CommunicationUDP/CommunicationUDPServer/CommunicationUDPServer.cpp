/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#include <cstring>

#include <iostream>
#include "CommunicationUDPServer.hpp"
#include "../../../Client/Constants/Constants.hpp"

CommunicationUDPServer::CommunicationUDPServer(std::string const &port)
    : _url(IP_ADDRESS()), _port(port), socket(sockFd, port)
{}

std::vector<std::shared_ptr<ACommand>> CommunicationUDPServer::receive()
{
    FD_ZERO(&rdfs);
    FD_SET(sockFd, &rdfs);
    std::vector <std::shared_ptr<ACommand>> commandVector;

    int max = sockFd;

    if (select(max + 1, &rdfs, nullptr, nullptr, nullptr) == -1) {
        perror("select()");
        exit(errno);
    }
    if (FD_ISSET(sockFd, &rdfs)) {
        SOCKADDR_IN sin{0};
        std::string res = socket.receivePacket(sockFd, sin);

        if (!socket.checkClientExists(_clients, sin))
            socket.addClient(sockFd, sin, res, _clients);
        parser.addGameServerCmd(commandVector, res);
    }
    return commandVector;
}

bool CommunicationUDPServer::send(std::string const &type, std::string const &content)
{

    std::string message = type + ";" + content;
    socket.sendPacketToAllClients(sockFd, _clients, message);
    socket.sendPacketToAllClients(sockFd, _clients, message);
    return true;
}

bool CommunicationUDPServer::send(std::string const &clientName, std::string const &type, std::string const &content)
{
    for (auto &client : _clients) {
        if (strcmp(client.name, clientName.data()) == 0) {
            std::string message = type + ";" + content;
            return socket.sendPacket(sockFd, message, client.sin);
        }
    }
    return false;
}

unsigned long CommunicationUDPServer::getNbClient()
{
    return _clients.size();
}