/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef MODELMENUSETTINGS_HPP
#define MODELMENUSETTINGS_HPP

#include <string>


/**** MENU SETTINGS MODEL ****/
struct MenuSettingsModel {
    static const std::string name() { return "SETTINGS_MODEL"; };
    static const std::string nameFocus() { return ""; };
    static const std::string path() { return "../Ressources/Menus/Models/settings_model.png"; };
    static const std::string pathFocus() { return ""; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int MenuSettingsModel::sizeX = 1920;
const unsigned int MenuSettingsModel::sizeY = 1080;
const unsigned int MenuSettingsModel::topX = 0;
const unsigned int MenuSettingsModel::topY = 0;


#endif //MODELMENUSETTINGS_HPP
