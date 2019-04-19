/*
** EPITECH PROJECT, 2021
** Project: CPP_rtype_2018
** File: SocketTcpServer.cpp
** File description:
** TCP sockets for the server
**
** Created by Alexandre Sachs on 19/11/18 at 18:32
*/


#include <iostream>
#include <cstring>
#include "SocketTcpServer.hpp"
#include "../../ErrorsSocket/ErrorsSocket.hpp"

SocketTcpServer::SocketTcpServer(SOCKET &sockFd, std::string const &port)
{
    initWindows();
    initConnection(sockFd, port);
}

SocketTcpServer::~SocketTcpServer()
{
    endWindows();
}

void SocketTcpServer::initWindows()
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

void SocketTcpServer::endWindows()
{
#ifdef WIN32
    WSACleanup();
#endif
}

int SocketTcpServer::sockError()
{
#ifdef WIN32
    return WSAGetLastError();
#else
    return errno;
#endif
}

std::string SocketTcpServer::sockErrMessage()
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

void SocketTcpServer::initConnection(SOCKET &sockFd, std::string const &port)
{
    SOCKADDR_IN sin{0};

    initSocket(sockFd);

    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_port = htons(static_cast<uint16_t>(atoi(port.c_str())));
    sin.sin_family = AF_INET;

    bindSocket(sockFd, sin);
    listenClient(sockFd);
}

void SocketTcpServer::initSocket(SOCKET &sockFd)
{
    if ((sockFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET) {
        _errorStream << "! SocketTcp initialization failed ! " << sockErrMessage() << ": [" << sockError() << "]";
        throw ErrorsSocket(std::cerr, _errorStream.str());
    }
}

void SocketTcpServer::bindSocket(SOCKET &sock, SOCKADDR_IN &sin)
{
    if (bind(sock, (SOCKADDR * ) & sin, sizeof sin) == SOCKET_ERROR) {
        _errorStream << "! Bind failed ! " << sockErrMessage() << ": [" << sockError() << "]";
        throw ErrorsSocket(std::cerr, _errorStream.str());
    }
}

void SocketTcpServer::listenClient(SOCKET &sockFd)
{
    if (listen(sockFd, MAX_CLIENTS) == SOCKET_ERROR) {
        _errorStream << "! Listen Client failed ! " << sockErrMessage() << ": [" << sockError() << "]";
        throw ErrorsSocket(std::cerr, _errorStream.str());
    }
}

void SocketTcpServer::closeSocket(SOCKET &sockFd)
{
    if (closesocket(sockFd) < CLOSE_ERROR) {
        _errorStream << "! Close socket failed ! " << sockErrMessage() << ": [" << sockError() << "]";
        throw ErrorsSocket(std::cerr, _errorStream.str());
    }
}

void SocketTcpServer::acceptClient(SOCKET &sock, SOCKET &clientSock)
{
    SOCKADDR_IN csin = {0};
    socklen_t sinsize = sizeof csin;

    clientSock = accept(sock, (SOCKADDR * ) & csin, &sinsize);
    if (clientSock == SOCKET_ERROR) {
        _errorStream << "! Accept Client failed ! " << sockErrMessage() << ": [" << sockError() << "]";
        throw ErrorsSocket(std::cerr, _errorStream.str());
    }
}

std::string SocketTcpServer::receivePacket(SOCKET &sockFd)
{
	char buffer[MAX_LINE];
	ssize_t size = recv(sockFd, buffer, MAX_LINE - 1, 0);

	if (size <= 0)
		return std::string("");
	buffer[size] = '\0';
	return std::string(reinterpret_cast<char *>(buffer));
}

ssize_t SocketTcpServer::sendPacket(SOCKET &sockFd, std::string const &packet_to_send)
{
    std::vector<char> writable(packet_to_send.begin(), packet_to_send.end());
    writable.push_back('\0');
#ifdef _WIN32
	ssize_t size = send(sockFd, &writable[0], strlen((char *)&writable[0]), 0); 
#elif defined (linux)
    ssize_t size = send(sockFd, &writable[0], strlen((char *) &writable[0]), MSG_NOSIGNAL);
#endif
	return size;
}

void SocketTcpServer::sendPacketToAllClients(std::vector <std::shared_ptr<TcpClient>> &clients, std::string &buffer, int pos)
{
    std::string mes;

    if (buffer.empty())
        buffer = "ALIVE";

    for (int i = 0; i < _nbClients; i++) {
        mes = "";
        mes.append(buffer);
        if (pos != i && sendPacket(clients[i]->sock, mes) <= 0) {
            closeSocket(clients[i]->sock);
            removeClient(clients, i);
            i--;
        }
    }
}

bool SocketTcpServer::addClient(SOCKET &sockFd, std::string &name, std::vector <std::shared_ptr<TcpClient>> &clients)
{
    for (auto &client : clients) {
        if (client->name == name) {
            return false;
        }
    }

    auto clt = std::make_shared<TcpClient>(sockFd, name);
    std::string res("Connect to the server.");

    clients.push_back(clt);
    _nbClients++;
    return true;
}

bool SocketTcpServer::disconnectServer(SOCKET &sockFd, std::vector <std::shared_ptr<TcpClient>> &clients, std::string &str)
{
    if (str == "DISCONNECT_SERVER") {
        std::string message("DISCONNECT_ME");
        sendPacketToAllClients(clients, message, -1);
        return true;
    }
    return false;
}

bool SocketTcpServer::disconnectClient(std::vector <std::shared_ptr<TcpClient>> &clients, std::string &res, int pos)
{
    std::string message("Disconnected from the server.");

    if (res == "DISCONNECT_ME_NO_SEND") {
        sendPacketToAllClients(clients, message, pos);
        closeSocket(clients[pos]->sock);
        removeClient(clients, pos);
        return true;
    }
    return false;
}

void SocketTcpServer::removeClient(std::vector <std::shared_ptr<TcpClient>> &clients, int toRemove)
{
    _nbClients--;
    clients.erase(clients.begin() + toRemove);
}

void SocketTcpServer::clearClients(std::vector <std::shared_ptr<TcpClient>> &clients)
{
    for (int i = 0; i < _nbClients; i++) {
        closeSocket(clients[i]->sock);
        removeClient(clients, i);
    }
}