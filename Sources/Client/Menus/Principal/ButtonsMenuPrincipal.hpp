/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef BUTTONSMENUPRINCIPAL_HPP
#define BUTTONSMENUPRINCIPAL_HPP

#include <string>


/**** BUTTON CREATE ****/
struct ButtonCreatePrincipal {
    static const std::string name() { return "BUTTON_CREATE"; };
    static const std::string nameFocus() { return "BUTTON_CREATE_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_create.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_create_focus.png"; };
    static const unsigned int sizeX ;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ButtonCreatePrincipal::sizeX = 480;
const unsigned int ButtonCreatePrincipal::sizeY = 113;
const unsigned int ButtonCreatePrincipal::topX = 1225;
const unsigned int ButtonCreatePrincipal::topY = 362;


/**** BUTTON JOIN ****/
struct ButtonJoinPrincipal {
    static const std::string name() { return "BUTTON_JOIN"; };
    static const std::string nameFocus() { return "BUTTON_JOIN_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_join.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_join_focus.png"; };
    static const unsigned int sizeX ;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ButtonJoinPrincipal::sizeX = 480;
const unsigned int ButtonJoinPrincipal::sizeY = 113;
const unsigned int ButtonJoinPrincipal::topX = 1225;
const unsigned int ButtonJoinPrincipal::topY = 532;


/**** BUTTON SETTINGS ****/
struct ButtonSettingsPrincipal {
    static const std::string name() { return "BUTTON_SETTINGS"; };
    static const std::string nameFocus() { return "BUTTON_SETTINGS_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_settings.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_settings_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ButtonSettingsPrincipal::sizeX = 480;
const unsigned int ButtonSettingsPrincipal::sizeY = 113;
const unsigned int ButtonSettingsPrincipal::topX = 1225;
const unsigned int ButtonSettingsPrincipal::topY = 702;


/**** EXIT GAME ****/
struct ExitGamePrincipal {
    static const std::string name() { return "EXIT_GAME"; };
    static const std::string nameFocus() { return "EXIT_GAME_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/exit.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/exit_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ExitGamePrincipal::sizeX = 59;
const unsigned int ExitGamePrincipal::sizeY = 59;
const unsigned int ExitGamePrincipal::topX = 36;
const unsigned int ExitGamePrincipal::topY = 939;


/**** BUTTON CLOSE ****/
struct ButtonClosePrincipal {
    static const std::string name() { return "BUTTON_CLOSE"; };
    static const std::string nameFocus() { return "BUTTON_CLOSE_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_close.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_close_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ButtonClosePrincipal::sizeX = 59;
const unsigned int ButtonClosePrincipal::sizeY = 59;
const unsigned int ButtonClosePrincipal::topX = 1732;
const unsigned int ButtonClosePrincipal::topY = 94;


#endif //BUTTONSMENUPRINCIPAL_HPP