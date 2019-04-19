/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef MODELMENUPAUSE_HPP
#define MODELMENUPAUSE_HPP

#include <string>


/**** MENU PAUSE MODEL ****/
struct MenuPauseModel {
    static const std::string name() { return "PAUSE_MODEL"; };
    static const std::string nameFocus() { return ""; };
    static const std::string path() { return "../Ressources/Menus/Models/pause_model.png"; };
    static const std::string pathFocus() { return ""; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int MenuPauseModel::sizeX = 1920;
const unsigned int MenuPauseModel::sizeY = 1080;
const unsigned int MenuPauseModel::topX = 0;
const unsigned int MenuPauseModel::topY = 0;

#endif //MODELMENUPAUSE_HPP
