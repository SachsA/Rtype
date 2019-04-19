/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include "AlienGamma.hpp"

AlienGamma::AlienGamma()
        : AEntityClient("alienGamma")
{
    setAssetPath("../Ressources/Enemies/Assets/enemy_alien_14.png");
    setPosition(0, 0);
    setSize(200, 120);
    setSoundName(ENGINE_SOUND());
}

extern "C" {
#ifdef _WIN32
__declspec(dllexport) AEntityClient *buildEngine()
#elif defined (linux)
AEntityClient *buildEngine()
#endif
{
    return new AlienGamma();
}
}
