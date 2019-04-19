/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef BUTTONSMENURIGHT_HPP
#define BUTTONSMENURIGHT_HPP

#include <string>


/**** BUTTON PUBLIC ****/
struct ButtonPublicRight {
    static const std::string name() { return "BUTTON_PUBLIC"; };
    static const std::string nameFocus() { return "BUTTON_PUBLIC_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_public.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_public_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ButtonPublicRight::sizeX = 480;
const unsigned int ButtonPublicRight::sizeY = 113;
const unsigned int ButtonPublicRight::topX = 1225;
const unsigned int ButtonPublicRight::topY = 362;


/**** BUTTON PRIVATE ****/
struct ButtonPrivateRight {
    static const std::string name() { return "BUTTON_PRIVATE"; };
    static const std::string nameFocus() { return "BUTTON_PRIVATE_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_private.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_private_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ButtonPrivateRight::sizeX = 480;
const unsigned int ButtonPrivateRight::sizeY = 113;
const unsigned int ButtonPrivateRight::topX = 1225;
const unsigned int ButtonPrivateRight::topY = 532;


/**** BUTTON SETTINGS ****/
struct ButtonSettingsRight {
    static const std::string name() { return "BUTTON_SETTINGS"; };
    static const std::string nameFocus() { return "BUTTON_SETTINGS_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_settings.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_settings_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ButtonSettingsRight::sizeX = 480;
const unsigned int ButtonSettingsRight::sizeY = 113;
const unsigned int ButtonSettingsRight::topX = 1225;
const unsigned int ButtonSettingsRight::topY = 702;


/**** BUTTON CLOSE ****/
struct ButtonCloseRight {
    static const std::string name() { return "BUTTON_CLOSE"; };
    static const std::string nameFocus() { return "BUTTON_CLOSE_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_close.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_close_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ButtonCloseRight::sizeX = 59;
const unsigned int ButtonCloseRight::sizeY = 59;
const unsigned int ButtonCloseRight::topX = 1732;
const unsigned int ButtonCloseRight::topY = 94;


/**** TEXT INFOS SERVER ****/
struct TextInfosServer {
    static const std::string name() { return "TEXT_INFOSSERVER"; };
    static const std::string nameFocus() { return "TEXT_INFOSSERVER_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/input_text.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/input_text_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int TextInfosServer::sizeX = 699;
const unsigned int TextInfosServer::sizeY = 173;
const unsigned int TextInfosServer::topX = 202;
const unsigned int TextInfosServer::topY = 505;


/**** TEXT SERVERNAME ****/
struct TextServerName {
    static const std::string name() { return "TEXT_SERVERNAME"; };
    static const std::string nameFocus() { return "TEXT_SERVERNAME_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/input_text.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/input_text_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int TextServerName::sizeX = 699;
const unsigned int TextServerName::sizeY = 119;
const unsigned int TextServerName::topX = 202;
const unsigned int TextServerName::topY = 705;


/**** EXIT GAME ****/
struct ExitGameRight {
    static const std::string name() { return "EXIT_GAME"; };
    static const std::string nameFocus() { return "EXIT_GAME_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/exit.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/exit_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ExitGameRight::sizeX = 59;
const unsigned int ExitGameRight::sizeY = 59;
const unsigned int ExitGameRight::topX = 36;
const unsigned int ExitGameRight::topY = 939;


static const std::string INFOS_SERVER() { return "ENTER THE NAME OF YOUR GAME AND CHOOSE IT'S TYPE !"; };
static const std::string ERROR_SERVER() { return "THE NAME OF YOUR GAME IS ALREADY USED !"; };


#endif //BUTTONSMENURIGHT_HPP