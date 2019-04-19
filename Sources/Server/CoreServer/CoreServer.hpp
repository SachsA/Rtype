//
// EPITECH PROJECT, 2018
// cpp_rtype
// File description:
// Header file for CoreServer
//

#ifndef CORE_HPP_
#define CORE_HPP_

#include <string>
#include <unordered_map>

#include "../../Commands/GameCommands/GameCommands.hpp"
#include "../../Commands/CoreCommands/CoreCommand.hpp"
#include "../../Commands/LobbyCommands/LobbyCommands.hpp"

#include "../../ThreadPool/ThreadPool.hpp"

class CoreServer {
public:
	CoreServer(); 	//the default constructor
	~CoreServer();

	void mainLoop();

private:
	void handleCmd(ACommand &cmd);
	bool addPlayerToGame(const User &user, const std::string &serverName);

	void createGameInstance(CreateInstanceCommand const &cmd);
	void instancesList(InstancesListCommand const &cmd);
	void joinGameInstance(JoinCommand const &cmd);
	void disconnectClient(DisconnectClientCommand const &cmd);

	CommunicationTCPServer _communication;
	ThreadPool _threadPool;
	std::unordered_map<std::string, GameInstance *> _gameInstances;
	int _id;
};

#endif // CORE_HPP_