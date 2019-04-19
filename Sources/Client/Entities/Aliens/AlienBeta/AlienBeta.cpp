/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include "AlienBeta.hpp"

AlienBeta::AlienBeta()
        : AEntityClient("alienBeta")
{
    setAssetPath("../Ressources/Enemies/Assets/enemy_alien_15.png");
    setPosition(0, 0);
    setSize(200, 255);
    setSoundName(ENGINE_SOUND());
}

extern "C" {
#ifdef _WIN32
__declspec(dllexport) AEntityClient *buildEngine()
#elif defined (linux)
AEntityClient *buildEngine()
#endif
{
    return new AlienBeta();
}
}
