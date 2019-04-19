/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include "AMenu.hpp"

AMenu::AMenu(SFMLHandler const &sfmlHandler, std::string &userName, std::string &serverName)
        : _userName(userName), _serverName(serverName) {
    _sfmlHandler = sfmlHandler;
}