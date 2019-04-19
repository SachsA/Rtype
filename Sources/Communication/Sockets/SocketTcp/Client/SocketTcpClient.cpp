/*
** EPITECH PROJECT, 2021
** Project: CPP_rtype_2018
** File: SocketTcpClient.cpp
** File description:
** Tcp sockets for the client
**
** Created by Alexandre Sachs on 19/11/18 at 18:32
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <signal.h>
#include "SocketTcpClient.hpp"
#include "../../ErrorsSocket/ErrorsSocket.hpp"

SocketTcpClient::SocketTcpClient(std::string const &ip, std::string const &port, SOCKET &sockFd)
    : _ip(ip), _port(port)
{
    initialisation(ip, port, sockFd);
}

SocketTcpClient::SocketTcpClient()
{

}

SocketTcpClient::~SocketTcpClient()
{
    endWindows();
}

bool SocketTcpClient::initialisation(std::string const &ip, std::string const &port, SOCKET &sockFd)
{
    _ip = ip;
    _port = port;
    initWindows();
    return initConnection(_ip, _port, sockFd);
}

void SocketTcpClient::initWindows()
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

void SocketTcpClient::endWindows()
{
#ifdef WIN32
    WSACleanup();
#endif
}

int SocketTcpClient::sockError()
{
#ifdef WIN32
    return WSAGetLastError();
#else
    return errno;
#endif
}

std::string SocketTcpClient::sockErrMessage()
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

bool SocketTcpClient::initConnection(std::string &address, std::string &port, SOCKET &sockFd)
{
    SOCKADDR_IN sin{0};
    struct hostent *hostInfo;

    initSocket(sockFd);
    hostInfo = gethostbyname(address.c_str());
    if (hostInfo == nullptr) {
        _errorStream << "! Unknown host ! " << sockErrMessage() << ": [" << sockError() << "]";
        throw ErrorsSocket(std::cerr, _errorStream.str());
    }
    sin.sin_addr = *(IN_ADDR *) hostInfo->h_addr;
    sin.sin_port = htons(static_cast<uint16_t>(atoi(port.c_str())));
    sin.sin_family = AF_INET;

    return connectToServer(sin, sockFd);
}

bool SocketTcpClient::connectToServer(SOCKADDR_IN &sin, SOCKET &sockFd)
{
    return connect(sockFd, (SOCKADDR *)&sin, sizeof(SOCKADDR)) != SOCKET_ERROR;
}

void SocketTcpClient::initSocket(SOCKET &sockFd)
{
    if ((sockFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET) {
        _errorStream << "! SocketTcp initialization failed ! " << sockErrMessage() << ": [" << sockError() << "]";
        throw ErrorsSocket(std::cerr, _errorStream.str());
    }
}

bool SocketTcpClient::closeSocket(SOCKET &sockFd)
{
    return closesocket(sockFd) >= CLOSE_ERROR;
}

std::string SocketTcpClient::receivePacket(SOCKET &sockFd)
{
    char buffer[MAX_LINE];
    ssize_t size = recv(sockFd, buffer, MAX_LINE - 1, 0);

	if (size <= 0)
        return "DISCONNECT_SERVER";
    buffer[size] = '\0';
    return std::string(reinterpret_cast<char *>(buffer));
}

bool SocketTcpClient::sendPacket(SOCKET &sockFd, std::string &packet_to_send)
{
    std::vector<char> vec(packet_to_send.begin(), packet_to_send.end());
    vec.push_back('\0');
    ssize_t size = send(sockFd, &vec[0], strlen((char *) &vec[0]), 0);
    return size > 0;
}