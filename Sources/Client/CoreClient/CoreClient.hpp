/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef CORECLIENT_HPP
#define CORECLIENT_HPP

#include <unordered_map>
#include "../SFMLHandler/SFMLHandler.hpp"
#include "../Menus/AMenu.hpp"
#include "../../Communication/CommunicationTCP/CommunicationTCPClient/CommunicationTCPClient.hpp"
#include "../../Communication/CommunicationUDP/CommunicationUDPClient/CommunicationUDPClient.hpp"

class CoreClient {
public:
    CoreClient();
    ~CoreClient();
    CoreClient(CoreClient const &) = default;
    void launchClient();

private:
    /* FUNCTIONS */
	void loadMusics();
	void loadSounds();

    void validPath(std::string const &path);

    void initializeInstances();

    void launchInstance(InstanceStatus &status, InstanceStatus &last, enum Event const &event);

    /* VARIABLES */

    std::string _userName;
	std::string _serverName;
    std::vector<std::string> _listServer;

    SFMLHandler _sfmlHandler;

    std::unordered_map<InstanceStatus, std::unique_ptr<AMenu>> _instances;

    CommunicationTCPClient _communicationServer;
    CommunicationTCPClient _communicationLobby;
    CommunicationUDPClient _communicationGame;
};

#endif //CORECLIENT_HPP
