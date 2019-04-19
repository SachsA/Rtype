/*
** EPITECH PROJECT, 2021
** Project: CPP_rtype_2018
** File: SocketUdpClient.hpp
** File description:
** Define SocketUdpClient class
**
** Created by Alexandre Sachs on 19/11/18 at 18:32
*/

#ifndef CPP_RTYPE_2018_SOCKET_UDP_CLIENT_H
#define CPP_RTYPE_2018_SOCKET_UDP_CLIENT_H

#ifdef _WIN32

#pragma comment(lib, "ws2_32.lib")

#include <winsock2.h>

#include <BaseTsd.h>
typedef SSIZE_T ssize_t;

typedef int socklen_t;

#elif defined (linux)

#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>

#define INVALID_SOCKET -1

#define closesocket(s) close(s)

typedef int SOCKET;
typedef struct in_addr IN_ADDR;
typedef struct sockaddr SOCKADDR;
typedef struct sockaddr_in SOCKADDR_IN;

#else
    #error not defined for this platform
#endif

#include <sstream>

#define CLOSE_ERROR -1
#define MAX_LINE    1024

class SocketUdpClient
{
public:
    explicit SocketUdpClient(std::string const &, std::string const &, SOCKADDR_IN &sin, SOCKET &sockFd);
    explicit SocketUdpClient(SOCKADDR_IN &sin, SOCKET &sockFd);
    ~SocketUdpClient();

    int sockError();
    std::string sockErrMessage();

    void initialisation(std::string const &, std::string const &);


    void initWindows();
    void endWindows();

    void initConnection(std::string const &, std::string const &, SOCKADDR_IN &, SOCKET &);
    void closeSocket(SOCKET &);

    bool sendPacket(SOCKET &, std::string const &, SOCKADDR_IN &);
    std::string receivePacket(SOCKET &, SOCKADDR_IN &);

private:
    std::ostringstream _errorStream;
    std::string _ip;
    std::string _port;
    SOCKADDR_IN &_sin;
    SOCKET &_sockFd;

    void initSocket(SOCKET &);
};

#endif //CPP_RTYPE_2018_SOCKET_UDP_CLIENT_H