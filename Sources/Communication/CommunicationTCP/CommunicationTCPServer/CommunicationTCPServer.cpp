/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#include <cstring>
#include <iostream>

#include "CommunicationTCPServer.hpp"
#include "../../../Client/Constants/Constants.hpp"

CommunicationTCPServer::CommunicationTCPServer(std::string const &port)
    : _url(IP_ADDRESS()), _port(port), socket{sockFd, port}
{
    max = sockFd;
}

std::vector<std::shared_ptr<ACommand>> CommunicationTCPServer::receive()
{
    int pos = 0;
    FD_ZERO(&rdfs);
    FD_SET(sockFd, &rdfs);

    std::vector<std::shared_ptr<ACommand>> commandVector;


    for (int i = 0; i < socket._nbClients; i++)
        FD_SET(_clients[i]->sock, &rdfs);

    if (select(max + 1, &rdfs, nullptr, nullptr, nullptr) == -1) {
        perror("select()");
        exit(errno);
    }

    if (FD_ISSET(sockFd, &rdfs)) {
        std::string res;
        SOCKET clientSock = -1;

        socket.acceptClient(sockFd, clientSock);
        if ((res = socket.receivePacket(clientSock)).empty())
            return commandVector;

        max = clientSock > max ? clientSock : max;
        FD_SET(clientSock, &rdfs);

        for (pos = 0; pos < socket._nbClients; pos++)
            if (_clients[pos]->sock == clientSock)
                break;

        if (socket._nbClients <= MAX_CLIENTS) {
            std::string response;
            if (!socket.addClient(clientSock, res, _clients)) {
                response = "VALID_USER;" + res + ";0";
                socket.sendPacket(clientSock, response);
                socket.closeSocket(clientSock);
            } else {
                response = "VALID_USER;" + res + ";1";

                if (socket.sendPacket(clientSock, response) <= 0) {
                    response = std::string("DISCONNECT_ME_NO_SEND");
                    socket.disconnectClient(_clients, response, pos);
                    return commandVector;
                }
            }
        } else {
            std::string response = "VALID_USER;" + res + ";0";
            if (socket.sendPacket(clientSock, response) <= 0) {
                response = std::string("DISCONNECT_ME_NO_SEND");
                socket.disconnectClient(_clients, response, pos);
                return commandVector;
            }
        }
    } else {
        for (int i = 0; i < socket._nbClients; i++) {
            if (FD_ISSET(_clients[i]->sock, &rdfs)) {
                std::string res = socket.receivePacket(_clients[i]->sock);
                if (res.empty()) {
                    res = std::string("DISCONNECT_ME_NO_SEND");
                    socket.disconnectClient(_clients, res, i);
                    continue;
                }
                parser.addServerCmd(commandVector, res);
            }
        }
    }
    return commandVector;
}

bool CommunicationTCPServer::send(std::string const &type, std::string const &content)
{
    std::string message = type + ";" + content;
    socket.sendPacketToAllClients(_clients, message, -1);
    return true;
}

bool CommunicationTCPServer::send(std::string const &clientName, std::string const &type, std::string const &content)
{
    int i = 0;

    for (auto &client : _clients) {
        if (strcmp(client->name.c_str(), clientName.data()) == 0) {
            std::string message = type + ";" + content;
            if (socket.sendPacket(client->sock, message) <= 0) {
                message = std::string("DISCONNECT_ME_NO_SEND");
                socket.disconnectClient(_clients, message, i);
                return false;
            }
            return true;
        }
        i++;
    }
    return false;
}

bool CommunicationTCPServer::disconnectClient(std::string const &userName)
{
    std::string message("DISCONNECT_ME_NO_SEND");
    int i = 0;
    for (auto &client : _clients) {
        if (client->name == userName) {
            socket.disconnectClient(_clients, message, i);
            return true;
        }
        i++;
    }
    return false;
}

void CommunicationTCPServer::mainLoopThread()
{

}