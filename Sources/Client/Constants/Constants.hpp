/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>


static const unsigned int WINDOW_WIDTH = 1920;
static const unsigned int WINDOW_HEIGHT = 1080;

//static const std::string IP_ADDRESS() {return "10.10.253.139"; };
static const std::string IP_ADDRESS() {return "localhost"; };
static const std::string SERVER_PORT() {return "6000"; };

static const std::string WINDOW_TITLE() { return "R-TYPE"; };

static const std::string FONT_FILENAME() { return "../Ressources/Fonts/source_sans_pro_regular.ttf"; };


// WHITE (255, 255, 255, 1) || #FFFFFF
// BLUE (4, 16, 28, 1) || #04101C
// BLUE SHIP (68, 114, 196, 1) || #4472C4
// YELLOW (255, 255, 0, 1) || #FFFF00
// GREEN (0, 175, 80, 1) || #00B050
// RED (191, 0, 0, 1) || #BF0000

#endif //CONSTANTS_HPP
