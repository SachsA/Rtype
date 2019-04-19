/*
** EPITECH PROJECT, 2021
** Project: CPP_rtype_2018
** File: SocketUdpClient.cpp
** File description:
** UDP sockets for the client
**
** Created by Alexandre Sachs on 19/11/18 at 18:32
*/

#include <iostream>
#include <cstring>
#include <vector>
#include "SocketUdpClient.hpp"
#include "../../ErrorsSocket/ErrorsSocket.hpp"

SocketUdpClient::SocketUdpClient(std::string const &ip, std::string const &port, SOCKADDR_IN &sin, SOCKET &sockFd)
    : _ip(ip), _port(port), _sin(sin), _sockFd(sockFd)
{
    initWindows();
    initConnection(ip, port, sin, sockFd);
}

SocketUdpClient::SocketUdpClient(SOCKADDR_IN &sin, SOCKET &sockFd)
    : _sin(sin), _sockFd(sockFd)
{

}

SocketUdpClient::~SocketUdpClient()
{
    endWindows();
}

void SocketUdpClient::initialisation(std::string const &ip, std::string const &port)
{
    _ip = ip;
    _port = port;
    initWindows();
    initConnection(ip, port, _sin, _sockFd);
}

void SocketUdpClient::initWindows()
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

void SocketUdpClient::endWindows()
{
#ifdef WIN32
    WSACleanup();
#endif
}

int SocketUdpClient::sockError()
{
#ifdef WIN32
    return WSAGetLastError();
#else
    return errno;
#endif
}

std::string SocketUdpClient::sockErrMessage()
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

void SocketUdpClient::initConnection(std::string const &address, std::string const &port, SOCKADDR_IN &sin, SOCKET &sockFd)
{
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
}

void SocketUdpClient::initSocket(SOCKET &sockFd)
{
    if ((sockFd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET) {
        _errorStream << "! SocketUdp initialization failed ! " << sockErrMessage() << ": [" << sockError() << "]";
        throw ErrorsSocket(std::cerr, _errorStream.str());
    }
}

void SocketUdpClient::closeSocket(SOCKET &sockFd)
{
    if (closesocket(sockFd) < CLOSE_ERROR) {
        _errorStream << "! Close socket failed ! " << sockErrMessage() << ": [" << sockError() << "]";
        throw ErrorsSocket(std::cerr, _errorStream.str());
    }
}

std::string SocketUdpClient::receivePacket(SOCKET &sockFd, SOCKADDR_IN &sockAddr)
{
    socklen_t sinsize = sizeof(sockAddr);
    char buffer[MAX_LINE];
    ssize_t size = recvfrom(sockFd, buffer, MAX_LINE - 1, 0, (SOCKADDR *) &sockAddr, &sinsize);

	if (size <= 0)
		return std::string("DISCONNECT_ME");
    buffer[size] = '\0';
    return std::string(reinterpret_cast<char *>(buffer));
}

bool SocketUdpClient::sendPacket(SOCKET &sockFd, std::string const &packet_to_send, SOCKADDR_IN &sockAddr)
{
    socklen_t sinsize = sizeof(sockAddr);

    std::vector<char> vec(packet_to_send.begin(), packet_to_send.end());
    vec.push_back('\0');
    ssize_t size = sendto(sockFd, &vec[0], strlen((char *) &vec[0]), 0, (const SOCKADDR *) &sockAddr, sinsize);
	if (size <= 0)
		return false;
	return true;
}