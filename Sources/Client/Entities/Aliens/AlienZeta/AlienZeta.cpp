/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include "AlienZeta.hpp"

AlienZeta::AlienZeta()
        : AEntityClient("alienZeta")
{
    setAssetPath("../Ressources/Enemies/Assets/enemy_alien_11.png");
    setSoundName(ENGINE_SOUND());
    setPosition(0, 0);
    setSize(150, 162);
}

extern "C" {
#ifdef _WIN32
__declspec(dllexport) AEntityClient *buildEngine()
#elif defined (linux)
AEntityClient *buildEngine()
#endif
{
    return new AlienZeta();
}
}
