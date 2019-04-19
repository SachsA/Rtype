/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef MODELMENURIGHT_HPP
#define MODELMENURIGHT_HPP

#include <string>


/**** MENU RIGHT MODEL ****/
struct MenuRightModel {
    static const std::string name() { return "RIGHT_MODEL"; };
    static const std::string nameFocus() { return ""; };
    static const std::string path() { return "../Ressources/Menus/Models/lobby_settings_model.png"; };
    static const std::string pathFocus() { return ""; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int MenuRightModel::sizeX = 1920;
const unsigned int MenuRightModel::sizeY = 1080;
const unsigned int MenuRightModel::topX = 0;
const unsigned int MenuRightModel::topY = 0;


#endif //MODELMENURIGHT_HPP
