//
// EPITECH PROJECT, 2018
// cpp_rtype
// File description:
// GameInstance's HeaderFile
//

#ifndef GAME_INSTANCE_HPP_
#define GAME_INSTANCE_HPP_

#include <string>
#include <unordered_map>
#include <mutex>

#include "../../Communication/CommunicationTCP/CommunicationTCPServer/CommunicationTCPServer.hpp"
#include "../../Communication/CommunicationUDP/CommunicationUDPServer/CommunicationUDPServer.hpp"

#include "../GameEngine/GameEngine.hpp"

class GameInstance {

public:
	GameInstance(CommunicationTCPServer &serverCom, std::string const &port, bool publicStatus);
	GameInstance(GameInstance const &original);
	GameInstance &operator=(GameInstance const &);
	~GameInstance() = default;

	void mainLoopThread(void *instancesArray);
	bool addPlayerToGame(User const &user);

	GameInstanceStatus status;

	GameEngine::GameEngine gameEngine;
	CommunicationTCPServer &_communicationServer;

	CommunicationTCPServer _communicationLobby;
	CommunicationUDPServer _communicationGame;
	bool isPublic;


//private:
	std::vector<User> _users;
	std::mutex mutex;
};

#endif //GAME_INSTANCE_HPP_
