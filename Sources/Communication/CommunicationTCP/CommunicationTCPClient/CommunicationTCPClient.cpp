/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#include <cstring>
#include <iostream>
#include "CommunicationTCPClient.hpp"

CommunicationTCPClient::CommunicationTCPClient(std::string const &ip, std::string const &port)
    : socket{ip, port, sockFd}
{}

CommunicationTCPClient::CommunicationTCPClient()
    : socket{}
{}

bool CommunicationTCPClient::initialisation(std::string const &ip, std::string const &port)
{
	return socket.initialisation(ip, port, sockFd);
}

std::vector<std::shared_ptr<ACommand>> CommunicationTCPClient::receive()
{
    FD_ZERO(&rdfs);
    FD_SET(sockFd, &rdfs);

    std::vector<std::shared_ptr<ACommand>> commandVector;

//    if ((ret = select(sockFd + 1, &rdfs, nullptr, nullptr, nullptr)) == -1) {
//        perror("select()");
//        exit(errno);
//    }
    if (FD_ISSET(sockFd, &rdfs)) {
        std::string res = socket.receivePacket(sockFd);
		parser.addClientCmd(commandVector, res);
    }
    return commandVector;
}

bool CommunicationTCPClient::send(std::string const &clientName, std::string const &type, std::string const &content)
{
    std::string message = type + ";" + content;
	return socket.sendPacket(sockFd, message);
}

bool CommunicationTCPClient::send(std::string const &content)
{
    std::string message = content;
	return socket.sendPacket(sockFd, message);
}

bool CommunicationTCPClient::decoClient()
{
	return socket.closeSocket(sockFd);
}

void CommunicationTCPClient::mainLoopThread()
{}