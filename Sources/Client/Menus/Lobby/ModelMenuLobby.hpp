/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef MODELMENULOBBY_HPP
#define MODELMENULOBBY_HPP

#include <string>


/**** MENU LOBBY MODEL ****/
struct MenuLobbyModel {
    static const std::string name() { return "LOBBY_MODEL"; };
    static const std::string nameFocus() { return nullptr; };
    static const std::string path() { return "../Ressources/Menus/Models/lobby_model.png"; };
    static const std::string pathFocus() { return nullptr; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int MenuLobbyModel::sizeX = 1920;
const unsigned int MenuLobbyModel::sizeY = 1080;
const unsigned int MenuLobbyModel::topX = 0;
const unsigned int MenuLobbyModel::topY = 0;


#endif //MODELMENULOBBY_HPP