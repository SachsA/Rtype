/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Alexandre Sachs
*/

#ifndef GAMEINSTANCE_HPP
#define GAMEINSTANCE_HPP

#include <mutex>
#include "../AMenu.hpp"
#include "../../SFMLHandler/SFMLHandler.hpp"
#include "ErrorsGameInstance.hpp"
#include "../../../Communication/CommunicationTCP/CommunicationTCPClient/CommunicationTCPClient.hpp"
#include "../../../Communication/CommunicationUDP/CommunicationUDPClient/CommunicationUDPClient.hpp"
#include "../../Entities/AEntity.hpp"

class GameInstance : public AMenu {
public:
	GameInstance(SFMLHandler const &sfmlHandler, std::string &userName, std::string &serverName,
		CommunicationTCPClient &server, std::vector<std::string> &listServer, CommunicationTCPClient &lobbyTCP,
		CommunicationUDPClient &lobbyUDP);
	GameInstance(GameInstance const &) = default;
	~GameInstance() override = default;
	InstanceStatus launch(enum Event const &event, InstanceStatus const &last) override;

	bool checkDuplicate(std::shared_ptr<ACommand> &node);


	void launchThread();
private:
    /* FONCTIONS */
	void draw();
    void drawShader();
    void mainLoopThread();

    InstanceStatus manageEvent(enum Event const &event);
    bool manageCommand();
    InstanceStatus returnToLogin();
    void updateEntity(UpdateEntityCommand const &command);
    void updatePlayerStatus(PlayerStatusCommand const &status);
    void loadEntity(UpdateEntityCommand const &command);

    void updateItems();
    void drawEntities();
    void initializeShader();
	void initializeAssets();

	void validAsset(std::string const &name, std::string const &path, Vector2D<unsigned int> const &position, Vector2D<unsigned int> const &size);

	/* VARIABLES */
	std::vector<std::string> &_listServer;
	CommunicationTCPClient &_server;
	CommunicationTCPClient &_lobbyTCP;
	CommunicationUDPClient &_lobbyUDP;

	std::mutex _commandMutex;
    std::unordered_map<std::string, AEntityClient *> _entities;
	std::vector<std::shared_ptr<ACommand>> _commands;

	float _offsetStarOne= 0.f;
	float _offsetStarTwo = 0.f;
	float _offsetStarThree = 0.f;
};

#endif //GAMEINSTANCE_HPP