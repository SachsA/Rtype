/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include "AlienPrincipal.hpp"

AlienPrincipal::AlienPrincipal()
        : AEntityClient("alienPrincipal")
{
    setAssetPath("../Ressources/Enemies/Assets/enemy_alien_17.png");
    setPosition(0, 0);
    setSize(200, 211);
    setSoundName(ENGINE_SOUND());
}

extern "C" {
#ifdef _WIN32
__declspec(dllexport) AEntityClient *buildEngine()
#elif defined (linux)
AEntityClient *buildEngine()
#endif
{
    return new AlienPrincipal();
}
}
