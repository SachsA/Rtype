/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#ifndef BUTTONLOGINMENU_HPP
#define BUTTONLOGINMENU_HPP

#include <string>

/*** BUTTON LOGIN ***/
struct ButtonLogin {
    static const std::string name() { return "BUTTON_LOGIN"; };
    static const std::string nameFocus() { return "BUTTON_LOGIN_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_login.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_login_focus.png"; };
    static const unsigned int sizeX ;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ButtonLogin::sizeX = 353;
const unsigned int ButtonLogin::sizeY = 92;
const unsigned int ButtonLogin::topX = 783;
const unsigned int ButtonLogin::topY = 798;


/*** TEXT USERNAME LOGIN ***/
struct TextUsernameLogin {
    static const std::string name() { return "TEXT_USERNAME"; };
    static const std::string nameFocus() { return "TEXT_USERNAME_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/input_text.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/input_text_focus.png"; };
    static const unsigned int sizeX ;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int TextUsernameLogin::sizeX = 699;
const unsigned int TextUsernameLogin::sizeY = 119;
const unsigned int TextUsernameLogin::topX = 610;
const unsigned int TextUsernameLogin::topY = 579;


/*** TEXT INFOS LOGIN ***/
struct TextInfosLogin {
    static const std::string name() { return "TEXT_INFO"; };
    static const std::string nameFocus() { return ""; };
    static const std::string path() { return ""; };
    static const std::string pathFocus() { return ""; };
    static const unsigned int sizeX ;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int TextInfosLogin::sizeX = 699;
const unsigned int TextInfosLogin::sizeY = 194;
const unsigned int TextInfosLogin::topX = 610;
const unsigned int TextInfosLogin::topY = 343;


/**** EXIT GAME ****/
struct ExitGameLogin {
    static const std::string name() { return "EXIT_GAME"; };
    static const std::string nameFocus() { return "EXIT_GAME_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/exit.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/exit_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ExitGameLogin::sizeX = 59;
const unsigned int ExitGameLogin::sizeY = 59;
const unsigned int ExitGameLogin::topX = 36;
const unsigned int ExitGameLogin::topY = 939;


static const std::string INFO_LOGIN() { return "ENTER YOUR USERNAME TO START !"; };
static const std::string ERROR_LOGIN() { return "YOUR USERNAME IS ALREADY USED !"; };

#endif //BUTTONLOGINMENU_HPP
