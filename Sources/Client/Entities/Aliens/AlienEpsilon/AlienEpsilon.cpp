/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include "AlienEpsilon.hpp"

AlienEpsilon::AlienEpsilon()
        : AEntityClient("alienEpsilon")
{
    setAssetPath("../Ressources/Enemies/Assets/enemy_alien_12.png");
    setPosition(0, 0);
    setSize(200, 109);
    setSoundName(ENGINE_SOUND());
}

extern "C" {
#ifdef _WIN32
__declspec(dllexport) AEntityClient *buildEngine()
#elif defined (linux)
AEntityClient *buildEngine()
#endif
{
    return new AlienEpsilon();
}
}
