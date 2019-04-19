/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include "AlienEta.hpp"

AlienEta::AlienEta()
        : AEntityClient("alienEta")
{
    setAssetPath("../Ressources/Enemies/Assets/enemy_alien_10.png");
    setPosition(0, 0);
    setSize(150,201);
    setSoundName(ENGINE_SOUND());
}

extern "C" {
#ifdef _WIN32
__declspec(dllexport) AEntityClient *buildEngine()
#elif defined (linux)
AEntityClient *buildEngine()
#endif
{
    return new AlienEta();
}
}
