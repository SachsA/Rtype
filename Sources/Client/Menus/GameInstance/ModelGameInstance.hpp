/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Alexandre Sachs
*/

#ifndef MODELGAMEINSTANCE_HPP
#define MODELGAMEINSTANCE_HPP

#include <string>

/**** GAME INSTANCE MODEL ****/
struct GameInstanceModel {
    static const std::string name() { return "GAMEINSTANCE_MODEL"; };
    static const std::string nameFocus() { return nullptr; };
    static const std::string path() { return "../Ressources/Background/Assets/background_space_motion.png"; };
    static const std::string pathFocus() { return nullptr; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int GameInstanceModel::sizeX = 1920;
const unsigned int GameInstanceModel::sizeY = 1080;
const unsigned int GameInstanceModel::topX = 0;
const unsigned int GameInstanceModel::topY = 0;


struct GameInstanceStarOne {
    static const std::string name() { return "GAMEINSTANCE_STAR_ONE_MODEL"; };
    static const std::string nameFocus() { return nullptr; };
    static const std::string path() { return "../Ressources/Background/Assets/background_star_one.png"; };
    static const std::string pathFocus() { return nullptr; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int GameInstanceStarOne::sizeX = 1920;
const unsigned int GameInstanceStarOne::sizeY = 1080;
const unsigned int GameInstanceStarOne::topX = 0;
const unsigned int GameInstanceStarOne::topY = 0;


struct GameInstanceStarTwo {
    static const std::string name() { return "GAMEINSTANCE_STAR_TWO_MODEL"; };
    static const std::string nameFocus() { return nullptr; };
    static const std::string path() { return "../Ressources/Background/Assets/background_star_two.png"; };
    static const std::string pathFocus() { return nullptr; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int GameInstanceStarTwo::sizeX = 1920;
const unsigned int GameInstanceStarTwo::sizeY = 1080;
const unsigned int GameInstanceStarTwo::topX = 0;
const unsigned int GameInstanceStarTwo::topY = 0;


struct GameInstanceStarThree {
    static const std::string name() { return "GAMEINSTANCE_STAR_THREE_MODEL"; };
    static const std::string nameFocus() { return nullptr; };
    static const std::string path() { return "../Ressources/Background/Assets/background_star_three.png"; };
    static const std::string pathFocus() { return nullptr; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int GameInstanceStarThree::sizeX = 1920;
const unsigned int GameInstanceStarThree::sizeY = 1080;
const unsigned int GameInstanceStarThree::topX = 0;
const unsigned int GameInstanceStarThree::topY = 0;


#endif //MODELGAMEINSTANCE_HPP