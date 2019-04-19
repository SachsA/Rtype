/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef SOUNDS_HPP
#define SOUNDS_HPP

#include <string>


static const std::string MUSIC_MENU_FILENAME() { return "../Ressources/Sounds/Musics/menuMusic.wav"; };
static const std::string MUSIC_MENU() { return "menuMusic"; };

static const std::string MUSIC_GAME_FILENAME() { return "../Ressources/Sounds/Musics/gameMusic.wav"; };
static const std::string MUSIC_GAME() { return "gameMusic"; };


static const std::string POWER_UP_SOUND_FILENAME() { return "../Ressources/Sounds/Bonus/powerUpSound.wav"; };
static const std::string POWER_UP_SOUND() { return "powerUp"; };


static const std::string CONFIRM_SOUND_FILENAME() { return "../Ressources/Sounds/Menus/confirmSound.wav"; };
static const std::string CONFIRM_SOUND() { return "confirmSound"; };

static const std::string CLICK_SOUND_FILENAME() { return "../Ressources/Sounds/Menus/clickSound.wav"; };
static const std::string CLICK_SOUND() { return "clickSound"; };

static const std::string RETURN_SOUND_FILENAME() { return "../Ressources/Sounds/Menus/returnSound.wav"; };
static const std::string RETURN_SOUND() { return "returnSound"; };


static const std::string ENGINE_SOUND_FILENAME() { return "../Ressources/Sounds/Ships/engineSound.wav"; };
static const std::string ENGINE_SOUND() { return "engineSound"; };

static const std::string EXPLOSION_SOUND_FILENAME() { return "../Ressources/Sounds/Ships/explosionSound.wav"; };
static const std::string EXPLOSION_SOUND() { return "explosionSound"; };


static const std::string SHOT_ALLY_SOUND_FILENAME() { return "../Ressources/Sounds/Shots/shotAllySound.wav"; };
static const std::string SHOT_ALLY_SOUND() { return "shotAllySound"; };

static const std::string SHOT_ENEMY_SOUND_FILENAME() { return "../Ressources/Sounds/Shots/shotEnemySound.wav"; };
static const std::string SHOT_ENEMY_SOUND() { return "shotEnemySound"; };


#endif //SOUNDS_HPP
