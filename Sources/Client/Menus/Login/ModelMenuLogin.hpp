/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#ifndef MODELMENULOGIN_HPP
#define MODELMENULOGIN_HPP

#include <string>

/**** MENU LOGIN MODEL ****/
struct MenuLoginModel {
    static const std::string name() { return "LOGIN_MODEL"; };
    static const std::string nameFocus() { return ""; };
    static const std::string path() { return "../Ressources/Menus/Models/login_model.png"; };
    static const std::string pathFocus() { return ""; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int MenuLoginModel::sizeX = 1920;
const unsigned int MenuLoginModel::sizeY = 1080;
const unsigned int MenuLoginModel::topX = 0;
const unsigned int MenuLoginModel::topY = 0;

#endif //MODELMENULOGIN_HPP