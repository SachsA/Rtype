/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef BUTTONSMENULOBBY_HPP
#define BUTTONSMENULOBBY_HPP

#include <string>


/**** BUTTON CLOSE ****/
struct ButtonCloseLobby {
    static const std::string name() { return "BUTTON_CLOSE"; };
    static const std::string nameFocus() { return "BUTTON_CLOSE_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_close.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_close_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ButtonCloseLobby::sizeX = 59;
const unsigned int ButtonCloseLobby::sizeY = 59;
const unsigned int ButtonCloseLobby::topX = 1732;
const unsigned int ButtonCloseLobby::topY = 94;


/**** SHIP SECTION BLUE ****/
struct ShipSectionBlue {
    static const std::string name() { return "SHIP_SECTION_BLUE"; };
    static const std::string nameFocus() { return ""; };
    static const std::string path() { return ""; };
    static const std::string pathFocus() { return ""; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ShipSectionBlue::sizeX = 226;
const unsigned int ShipSectionBlue::sizeY = 188;
const unsigned int ShipSectionBlue::topX = 193;
const unsigned int ShipSectionBlue::topY = 310;


/**** SHIP SECTION RED ****/
struct ShipSectionRed {
    static const std::string name() { return "SHIP_SECTION_RED"; };
    static const std::string nameFocus() { return ""; };
    static const std::string path() { return ""; };
    static const std::string pathFocus() { return ""; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ShipSectionRed::sizeX = 226;
const unsigned int ShipSectionRed::sizeY = 188;
const unsigned int ShipSectionRed::topX = 601;
const unsigned int ShipSectionRed::topY = 666;


/**** SHIP SECTION YELLOW ****/
struct ShipSectionYellow {
    static const std::string name() { return "SHIP_SECTION_YELLOW"; };
    static const std::string nameFocus() { return ""; };
    static const std::string path() { return ""; };
    static const std::string pathFocus() { return ""; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ShipSectionYellow::sizeX = 226;
const unsigned int ShipSectionYellow::sizeY = 188;
const unsigned int ShipSectionYellow::topX = 1051;
const unsigned int ShipSectionYellow::topY = 310;


/**** SHIP SECTION GREEN ****/
struct ShipSectionGreen {
    static const std::string name() { return "SHIP_SECTION_GREEN"; };
    static const std::string nameFocus() { return ""; };
    static const std::string path() { return ""; };
    static const std::string pathFocus() { return ""; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ShipSectionGreen::sizeX = 226;
const unsigned int ShipSectionGreen::sizeY = 188;
const unsigned int ShipSectionGreen::topX = 1455;
const unsigned int ShipSectionGreen::topY = 666;


/**** EXIT GAME ****/
struct ExitGameLobby {
    static const std::string name() { return "EXIT_GAME"; };
    static const std::string nameFocus() { return "EXIT_GAME_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/exit.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/exit_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ExitGameLobby::sizeX = 59;
const unsigned int ExitGameLobby::sizeY = 59;
const unsigned int ExitGameLobby::topX = 36;
const unsigned int ExitGameLobby::topY = 939;

#endif //BUTTONSMENULOBBY_HPP
