/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef AMENU_HPP
#define AMENU_HPP

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "../SFMLHandler/SFMLHandler.hpp"

enum InstanceStatus {
    LOGIN_INSTANCE,
    PRINCIPAL_INSTANCE,
    RIGHT_INSTANCE,
    ROOMS_INSTANCE,
    LOBBY_INSTANCE,
	SETTINGS_INSTANCE,
	PAUSE_INSTANCE,
	PREVIOUS_INSTANCE,
    EXIT_INSTANCE,
    UNDEFINED_INSTANCE,
    GAME_INSTANCE,
};

class AMenu {
public:
	explicit AMenu(SFMLHandler const &, std::string &userName, std::string &serverName);

    virtual ~AMenu() = default;
    virtual InstanceStatus launch(enum Event const &event, InstanceStatus const &last) = 0;

protected:
    SFMLHandler _sfmlHandler;
	std::string &_userName;
    std::string &_serverName;
};

#endif //AMENU_HPP
