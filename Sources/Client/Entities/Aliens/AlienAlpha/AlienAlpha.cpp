/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include "AlienAlpha.hpp"

AlienAlpha::AlienAlpha()
        : AEntityClient("alienAlpha")
{
    setAssetPath("../Ressources/Enemies/Assets/enemy_alien_16.png");
    setPosition(0, 0);
    setSize(200, 179);
    setSoundName(ENGINE_SOUND());
}

extern "C" {
#ifdef _WIN32
__declspec(dllexport) AEntityClient *buildEngine()
#elif defined (linux)
AEntityClient *buildEngine()
#endif
{
    return new AlienAlpha();
}
}
