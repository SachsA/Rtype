/*
** EPITECH PROJECT, 2021
** Project: CPP_rtype_2018
** File: SocketTcpClient.hpp
** File description:
** Define SocketTcpClient class
**
** Created by Alexandre Sachs on 19/11/18 at 18:32
*/

#ifndef CPP_RTYPE_2018_SOCKET_TCP_CLIENT_H
#define CPP_RTYPE_2018_SOCKET_TCP_CLIENT_H

#ifdef _WIN32

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

#define SOCKET_ERROR -1
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

class SocketTcpClient
{
public:
    explicit SocketTcpClient(std::string const &, std::string const &, SOCKET &);
    explicit SocketTcpClient();
    ~SocketTcpClient();

    int sockError();
    std::string sockErrMessage();

    bool initialisation(std::string const &, std::string const &, SOCKET &);

    void initWindows();
    void endWindows();

    bool initConnection(std::string &, std::string &, SOCKET &);
    bool closeSocket(SOCKET &);

    bool sendPacket(SOCKET &, std::string &);
    std::string receivePacket(SOCKET &);

private:
    std::ostringstream _errorStream;

    void initSocket(SOCKET &);
    bool connectToServer(SOCKADDR_IN &, SOCKET &);

    std::string _ip;
    std::string _port;
};

#endif //CPP_RTYPE_2018_SOCKET_TCP_CLIENT_H