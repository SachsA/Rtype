/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef MENUSETTINGS_HPP
#define MENUSETTINGS_HPP

#include "../AMenu.hpp"
#include "../../SFMLHandler/SFMLHandler.hpp"
#include "../../Components/Button/Button.hpp"
#include "../../../Communication/CommunicationTCP/CommunicationTCPClient/CommunicationTCPClient.hpp"

class MenuSettings: public AMenu {
public:
    MenuSettings(SFMLHandler const &sfmlHandler, std::string &userName, std::string &serverName, CommunicationTCPClient &server);
    MenuSettings(MenuSettings const &) = default;
    ~MenuSettings() override = default;
    InstanceStatus launch(enum Event const &event, InstanceStatus const &last) override;

private:
    /* FONCTIONS */
    void draw();
    void drawSoundUp();
    void drawSoundDown();
    void drawSoundIcon();
    InstanceStatus manageEvent(enum Event const &event);
    InstanceStatus buttonPressed(Vector2D<int> const &position);
    InstanceStatus buttonReleased(Vector2D<int> const &position);

    void initializeAssets();
    void initializeButtons();
    void initializeSoundUp();
    void initializeSoundDown();
    void initializeSoundIcon();
    void setTextsVolume(std::string const &name, std::string const &volume);
    void validAsset(std::string const &name, std::string const &path, Vector2D<unsigned int> const &position, Vector2D<unsigned int> const &size);
    void validButton(Vector2D<std::string> const &names, Vector2D<std::string> const &paths, Vector2D<unsigned int> const &position, Vector2D<unsigned int> const &size);

    void createButton(Vector2D<std::string> const &names, Vector2D<std::string> const &paths, Vector2D<unsigned int> const &position, Vector2D<unsigned int> const &size);
    void setButtonInstance(std::string const &name, InstanceStatus const &status);
    void manageSounds(std::string const &name);
    void putSoundUp(std::string const &sounds);
    void putSoundDown(std::string const &sounds);

    void sendLeaveServer();

    /* VARIABLES */
    std::unordered_map<std::string, Button> _buttons;
    CommunicationTCPClient &_server;
};

#endif //MENUSETTINGS_HPP
