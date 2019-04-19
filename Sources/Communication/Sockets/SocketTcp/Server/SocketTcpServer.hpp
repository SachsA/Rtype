/*
** EPITECH PROJECT, 2021
** Project: CPP_rtype_2018
** File: SocketTcpServer.hpp
** File description:
** Define SocketTcpServer class
**
** Created by Alexandre Sachs on 19/11/18 at 18:32
*/

#ifndef CPP_RTYPE_2018_SOCKET_TCP_SERVER_H
#define CPP_RTYPE_2018_SOCKET_TCP_SERVER_H

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
#include <memory>

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

#include <vector>
#include <sstream>

#define CLOSE_ERROR -1
#define MAX_LINE    1024
#define MAX_CLIENTS 4

struct TcpClient {
    TcpClient(SOCKET &sockFd, std::string &nameFd) {
        sock = sockFd;
        name = nameFd;
    }
    SOCKET sock;
    std::string name;
};

class SocketTcpServer
{
public:
    explicit SocketTcpServer(SOCKET &, std::string const &);
    ~SocketTcpServer();

    int sockError();
    std::string sockErrMessage();

    void initWindows();
    void endWindows();

    void initConnection(SOCKET &, std::string const &);
    void closeSocket(SOCKET &);

    ssize_t sendPacket(SOCKET &, std::string const &);
    std::string receivePacket(SOCKET &);

    void sendPacketToAllClients(std::vector<std::shared_ptr<TcpClient>> &, std::string &, int);

    void removeClient(std::vector <std::shared_ptr<TcpClient>> &, int);
    bool addClient(SOCKET &, std::string &, std::vector <std::shared_ptr<TcpClient>> &);

    void clearClients(std::vector <std::shared_ptr<TcpClient>> &);
    bool disconnectClient(std::vector <std::shared_ptr<TcpClient>> &, std::string &, int);

    bool disconnectServer(SOCKET &, std::vector <std::shared_ptr<TcpClient>> &, std::string &);

    void acceptClient(SOCKET &, SOCKET &);

    int _nbClients = 0;
private:
    std::ostringstream _errorStream;

    void initSocket(SOCKET &);
    void listenClient(SOCKET &);
    void bindSocket(SOCKET &, SOCKADDR_IN &);
};

#endif //CPP_RTYPE_2018_SOCKET_TCP_SERVER_H