/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef MODELMENUPRINCIPAL_HPP
#define MODELMENUPRINCIPAL_HPP

#include <string>


/**** MENU PRINCIPAL MODEL ****/
struct MenuPrincipalModel {
    static const std::string name() { return "PRINCIPAL_MODEL"; };
    static const std::string nameFocus() { return ""; };
    static const std::string path() { return "../Ressources/Menus/Models/principal_model.png"; };
    static const std::string pathFocus() { return ""; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int MenuPrincipalModel::sizeX = 1920;
const unsigned int MenuPrincipalModel::sizeY = 1080;
const unsigned int MenuPrincipalModel::topX = 0;
const unsigned int MenuPrincipalModel::topY = 0;


#endif //MODELMENUPRINCIPAL_HPP
