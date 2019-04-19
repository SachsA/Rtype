/*
** EPITECH PROJECT, 2021
** Project: CPP_rtype_2018
** File: SocketUdpServer.hpp
** File description:
** Define SocketUdpServer class
**
** Created by Alexandre Sachs on 19/11/18 at 18:32
*/

#ifndef CPP_RTYPE_2018_SOCKET_UDP_SERVER_H
#define CPP_RTYPE_2018_SOCKET_UDP_SERVER_H

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
#define SOCKET_ERROR -1

#define closesocket(s) close(s)

typedef int SOCKET;
typedef struct in_addr IN_ADDR;
typedef struct sockaddr SOCKADDR;
typedef struct sockaddr_in SOCKADDR_IN;

#else
    #error not defined for this platform
#endif

#include <sstream>
#include <vector>

#define CLOSE_ERROR -1
#define MAX_LINE    1024
#define MAX_CLIENTS 4

typedef struct
{
    SOCKADDR_IN sin;
    char name[MAX_LINE];
} UdpClient;

class SocketUdpServer
{
public:
    explicit SocketUdpServer(SOCKET &, std::string const &);
    ~SocketUdpServer();

    int sockError();
    std::string sockErrMessage();

    void initWindows();
    void endWindows();

    void initConnection(SOCKET &, std::string const &);
    void closeSocket(SOCKET &);

    bool sendPacket(SOCKET &, std::string &, SOCKADDR_IN &);
    std::string receivePacket(SOCKET &, SOCKADDR_IN &);

    UdpClient getClient(std::vector<UdpClient> &, SOCKADDR_IN &);
    int getPosClient(std::vector<UdpClient> &, SOCKADDR_IN &);

    bool checkClientExists(std::vector<UdpClient> &, SOCKADDR_IN &);
    void sendPacketToAllClients(SOCKET &, std::vector<UdpClient> &, std::string &);

    void removeClient(std::vector<UdpClient> &, int);
    void addClient(SOCKET &, SOCKADDR_IN &, std::string &, std::vector<UdpClient> &);
    bool disconnectClient(SOCKET &, SOCKADDR_IN &, std::vector<UdpClient> &, UdpClient &, std::string &);

    bool disconnectServer(SOCKET &, std::vector<UdpClient> &, std::string &);

private:
    std::ostringstream _errorStream;

    void initSocket(SOCKET &);
    void bindSocket(SOCKET &, SOCKADDR_IN &);
};

#endif //CPP_RTYPE_2018_SOCKET_UDP_SERVER_H