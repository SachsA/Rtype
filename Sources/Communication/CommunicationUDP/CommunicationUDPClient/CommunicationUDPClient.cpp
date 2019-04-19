/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#include <cstring>
#include <iostream>
#include "CommunicationUDPClient.hpp"

CommunicationUDPClient::CommunicationUDPClient(std::string const &ip, std::string const &port)
    : socket(ip, port, _sin, sockFd)
{}

CommunicationUDPClient::CommunicationUDPClient()
    : socket(_sin, sockFd)
{}

void CommunicationUDPClient::initialisation(std::string const &ip, std::string const &port)
{
    socket.initialisation(ip, port);
}

std::vector<std::shared_ptr<ACommand>> CommunicationUDPClient::receive()
{
    std::vector<std::shared_ptr<ACommand>> vectorCommand;

    FD_ZERO(&rdfs);
    FD_SET(sockFd, &rdfs);

	select(sockFd + 1, &rdfs, NULL, NULL, NULL);

    if (FD_ISSET(sockFd, &rdfs)) {
        std::string res = socket.receivePacket(sockFd, _sin);
        if (res == "DISCONNECT_ME") {
			socket.closeSocket(sockFd);
			return vectorCommand;
		}
        parser.addGameClientCmd(vectorCommand, res);
    }
    return vectorCommand;
}

bool CommunicationUDPClient::send(std::string const &content)
{
    std::string message = content;
	return socket.sendPacket(sockFd, message, _sin);
}

bool CommunicationUDPClient::send(std::string const &clientName, std::string const &type, std::string const &content)
{
    std::string message = type + ";" + content;
    socket.sendPacket(sockFd, message, _sin);
    return true;
}

void CommunicationUDPClient::mainLoopThread()
{}