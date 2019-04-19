/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include <string>
#include "ErrorsMenuLobby.hpp"

ErrorsMenuLobby::ErrorsMenuLobby(std::ostream &os, const std::string &message) noexcept
        : Errors(os, "MenuRooms : " + message) {}