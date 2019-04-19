/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef MENUROOMS_HPP
#define MENUROOMS_HPP

#include "../AMenu.hpp"
#include "../../SFMLHandler/SFMLHandler.hpp"
#include "../../Components/Button/Button.hpp"
#include "../../../Communication/CommunicationTCP/CommunicationTCPClient/CommunicationTCPClient.hpp"
#include "../../../Communication/CommunicationUDP/CommunicationUDPClient/CommunicationUDPClient.hpp"


class MenuRooms: public AMenu {
public:
    MenuRooms(SFMLHandler const &sfmlHandler, std::string &userName, std::string &serverName,
            CommunicationTCPClient &server, std::vector<std::string> &listServer, CommunicationTCPClient &lobbyTCP,
            CommunicationUDPClient &lobbyUDP);
    MenuRooms(MenuRooms const &) = default;
    ~MenuRooms() override = default;
    InstanceStatus launch(enum Event const &event, InstanceStatus const &last) override;

private:
    /* FONCTIONS */
    void draw();
    void drawItems(std::string const &name, Vector2D<unsigned int> const &position,
                              Vector2D<unsigned int> const &size, int const &index);
    InstanceStatus manageEvent(enum Event const &event);
    InstanceStatus buttonPressed(Vector2D<int> const &position);
    InstanceStatus buttonReleased(Vector2D<int> const &position);

	InstanceStatus returnToLogin();
    InstanceStatus sendLeaveServer();

    void initializeAssets();
    void initializeButtons();
    void setItemText(std::string const &name, int const &index);
    void validAsset(std::string const &name, std::string const &path, Vector2D<unsigned int> const &position, Vector2D<unsigned int> const &size);
    void validButton(Vector2D<std::string> const &names, Vector2D<std::string> const &paths, Vector2D<unsigned int> const &position, Vector2D<unsigned int> const &size);

    void createButton(Vector2D<std::string> const &names, Vector2D<std::string> const &paths, Vector2D<unsigned int> const &position, Vector2D<unsigned int> const &size);
    void setButtonInstance(std::string const &name, InstanceStatus const &status);

    InstanceStatus sendJoinInstance(std::string const &server);
    bool validItems(std::string const &name);
    void resetItems();

    /* VARIABLES */
    std::unordered_map<std::string, Button> _buttons;
    std::vector<std::string> &_listServer;
    CommunicationTCPClient &_server;
    CommunicationTCPClient &_lobbyTCP;
    CommunicationUDPClient &_lobbyUDP;
};

#endif //MENUROOMS_HPP
