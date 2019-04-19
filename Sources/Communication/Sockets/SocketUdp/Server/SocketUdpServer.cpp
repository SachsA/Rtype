/*
** EPITECH PROJECT, 2021
** Project: CPP_rtype_2018
** File: SocketUdpServer.cpp
** File description:
** UDP sockets for the server
**
** Created by Alexandre Sachs on 19/11/18 at 18:32
*/

#include <iostream>
#include <cstring>
#include "SocketUdpServer.hpp"
#include "../../ErrorsSocket/ErrorsSocket.hpp"

SocketUdpServer::SocketUdpServer(SOCKET &sockFd, std::string const &port)
{
    initWindows();
    initConnection(sockFd, port);
}

SocketUdpServer::~SocketUdpServer()
{
    endWindows();
}

void SocketUdpServer::initWindows()
{
#ifdef WIN32
    WSADATA wsa;
    int err = WSAStartup(MAKEWORD(2, 2), &wsa);

    if(err < 0) {
        _errorStream << "! WSAStartup failed !";
        throw ErrorsSocket(std::cerr, _errorStream.str());
    }
#endif
}

void SocketUdpServer::endWindows()
{
#ifdef WIN32
    WSACleanup();
#endif
}

int SocketUdpServer::sockError()
{
#ifdef WIN32
    return WSAGetLastError();
#else
    return errno;
#endif
}

std::string SocketUdpServer::sockErrMessage()
{
#ifdef WIN32
    wchar_t err[256];
    memset(err, 0, 256);
    FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM, NULL, sockError(),
                  MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), err, 255, NULL);
	std::wstring ws(err);
	std::string str(ws.begin(), ws.end());
	return str;
#else
    return strerror(errno);
#endif
}

void SocketUdpServer::initConnection(SOCKET &sockFd, std::string const &port)
{
    SOCKADDR_IN sin{0};

    initSocket(sockFd);

    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_port = htons(static_cast<uint16_t>(atoi(port.c_str())));
    sin.sin_family = AF_INET;

    bindSocket(sockFd, sin);
}

void SocketUdpServer::initSocket(SOCKET &sockFd)
{
    if ((sockFd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET) {
        _errorStream << "! SocketUdp initialization failed ! " << sockErrMessage() << ": [" << sockError() << "]";
        throw ErrorsSocket(std::cerr, _errorStream.str());
    }
}

void SocketUdpServer::bindSocket(SOCKET &sock, SOCKADDR_IN &sin)
{
    if (bind(sock, (SOCKADDR * ) & sin, sizeof sin) == SOCKET_ERROR) {
        _errorStream << "! Bind failed ! " << sockErrMessage() << ": [" << sockError() << "]";
        throw ErrorsSocket(std::cerr, _errorStream.str());
    }
}

void SocketUdpServer::closeSocket(SOCKET &sockFd)
{
    if (closesocket(sockFd) < CLOSE_ERROR) {
        _errorStream << "! Close socket failed ! " << sockErrMessage() << ": [" << sockError() << "]";
        throw ErrorsSocket(std::cerr, _errorStream.str());
    }
}

std::string SocketUdpServer::receivePacket(SOCKET &sockFd, SOCKADDR_IN &sockAddr)
{
    socklen_t sinsize = sizeof(sockAddr);
    char buffer[MAX_LINE];
    ssize_t size = recvfrom(sockFd, buffer, MAX_LINE - 1, 0, (SOCKADDR * ) & sockAddr, &sinsize);

	if (size <= 0)
		return std::string("");
	buffer[size] = '\0';
    return std::string(reinterpret_cast<char *>(buffer));
}

bool SocketUdpServer::sendPacket(SOCKET &sockFd, std::string &packet_to_send, SOCKADDR_IN &sockAddr)
{
    socklen_t sinsize = sizeof(sockAddr);

    std::vector<char> writable(packet_to_send.begin(), packet_to_send.end());
    writable.push_back('\0');
    ssize_t size = sendto(sockFd, &writable[0], strlen((char *) &writable[0]), 0, (const SOCKADDR *) &sockAddr,
                          sinsize);

	if (size <= 0)
		return false;
	return true;
}

UdpClient SocketUdpServer::getClient(std::vector <UdpClient> &clients, SOCKADDR_IN &csin)
{
    for (auto &client : clients) {
        if (client.sin.sin_addr.s_addr == csin.sin_addr.s_addr
            && client.sin.sin_port == csin.sin_port) {
            return client;
        }
    }
    return UdpClient{};
}

int SocketUdpServer::getPosClient(std::vector <UdpClient> &clients, SOCKADDR_IN &csin)
{
    for (unsigned int i = 0; i < clients.size(); i++) {
        if (clients[i].sin.sin_addr.s_addr == csin.sin_addr.s_addr
            && clients[i].sin.sin_port == csin.sin_port) {
            return i;
        }
    }
    return -1;
}

bool SocketUdpServer::checkClientExists(std::vector <UdpClient> &clients, SOCKADDR_IN &csin)
{
    for (auto &client : clients) {
        if (client.sin.sin_addr.s_addr == csin.sin_addr.s_addr
            && client.sin.sin_port == csin.sin_port) {
            return true;
        }
    }
    return false;
}

void SocketUdpServer::sendPacketToAllClients(SOCKET &sock, std::vector <UdpClient> &clients, std::string &buffer)
{
    std::string mes;

    for (auto &client : clients) {
        mes = "";
        mes.append(buffer);
        sendPacket(sock, mes, client.sin);
    }
}

void SocketUdpServer::addClient(SOCKET &sockFd, SOCKADDR_IN &sin, std::string &res, std::vector <UdpClient> &clients)
{
    UdpClient clt = {sin};

    strncpy(clt.name, res.c_str(), MAX_LINE - 1);
    clients.push_back(clt);
    res = "Connect to the server.";
    UdpClient client = getClient(clients, sin);
    sendPacketToAllClients(sockFd, clients, res);
}

bool SocketUdpServer::disconnectServer(SOCKET &sockFd, std::vector <UdpClient> &clients, std::string &str)
{
    UdpClient client{};

    if (str == "DISCONNECT_SERVER") {
        std::string message("DISCONNECT_ME");
        sendPacketToAllClients(sockFd, clients, message);
        return true;
    }
    return false;
}

bool SocketUdpServer::disconnectClient(SOCKET &sockFd, SOCKADDR_IN &sin, std::vector <UdpClient> &clients, UdpClient &client,
                                       std::string &res)
{
    std::string message("Disconnected from the server.");

    if (res == "DISCONNECT_ME") {
        sendPacketToAllClients(sockFd, clients, message);
        sendPacket(sockFd, res, client.sin);
        int pos = getPosClient(clients, sin);
        removeClient(clients, pos);
        return true;
    }
    return false;
}

void SocketUdpServer::removeClient(std::vector <UdpClient> &clients, int toRemove)
{
    clients.erase(clients.begin() + toRemove);
}