/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef MODELMENUROOMS_HPP
#define MODELMENUROOMS_HPP

#include <string>


/**** MENU ROOMS MODEL ****/
struct MenuRoomsModel {
    static const std::string name() { return "ROOMS_MODEL"; };
    static const std::string nameFocus() { return ""; };
    static const std::string path() { return "../Ressources/Menus/Models/server_list_model.png"; };
    static const std::string pathFocus() { return ""; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int MenuRoomsModel::sizeX = 1920;
const unsigned int MenuRoomsModel::sizeY = 1080;
const unsigned int MenuRoomsModel::topX = 0;
const unsigned int MenuRoomsModel::topY = 0;


#endif //MODELMENUROOMS_HPP
