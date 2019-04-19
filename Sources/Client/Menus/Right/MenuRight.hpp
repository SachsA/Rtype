/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef MENURIGHT_HPP
#define MENURIGHT_HPP

#include "../AMenu.hpp"
#include "../../SFMLHandler/SFMLHandler.hpp"
#include "../../Components/Button/Button.hpp"
#include "../../../Communication/CommunicationTCP/CommunicationTCPClient/CommunicationTCPClient.hpp"
#include "../../../Communication/CommunicationUDP/CommunicationUDPClient/CommunicationUDPClient.hpp"

class MenuRight: public AMenu {
public:
    MenuRight(SFMLHandler const &sfmlHandler, std::string &userName, std::string &serverName,
        CommunicationTCPClient &server, CommunicationTCPClient &lobbyTCP, CommunicationUDPClient &lobbyUDP);
    MenuRight(MenuRight const &) = default;
    ~MenuRight() override = default;
    InstanceStatus launch(enum Event const &event, InstanceStatus const &last) override;

private:
    /* FONCTIONS */
    void draw();
    InstanceStatus manageEvent(enum Event const &event);
    InstanceStatus buttonPressed(Vector2D<int> const &position);
    InstanceStatus buttonReleased(Vector2D<int> const &position);
    InstanceStatus textEntered(std::string const &text);

	InstanceStatus returnToLogin();

    void sendLeaveServer();

    void initializeAssets();
    void initializeButtons();
    void initializeServerName();
    void initializeServerInfos();
    void validAsset(std::string const &name, std::string const &path, Vector2D<unsigned int> const &position, Vector2D<unsigned int> const &size);
    void validButton(Vector2D<std::string> const &names, Vector2D<std::string> const &paths, Vector2D<unsigned int> const &position, Vector2D<unsigned int> const &size);

    void createButton(Vector2D<std::string> const &names, Vector2D<std::string> const &paths, Vector2D<unsigned int> const &position, Vector2D<unsigned int> const &size);
    void setButtonInstance(std::string const &name, InstanceStatus const &status);

    InstanceStatus optionsMenu(std::string const &key);
	InstanceStatus sendCreateInstance(std::string const &name, InstanceStatus const &status);

    /* VARIABLES */
    bool _focusInput;
    std::unordered_map<std::string, Button> _buttons;

    CommunicationTCPClient &_server;
    CommunicationTCPClient &_lobbyTCP;
    CommunicationUDPClient &_lobbyUDP;
};

#endif //MENURIGHT_HPP
