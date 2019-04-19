/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include "AlienKappa.hpp"

AlienKappa::AlienKappa()
        : AEntityClient("alienKappa")
{
    setAssetPath("../Ressources/Enemies/Assets/enemy_alien_7.png");
    setSoundName(ENGINE_SOUND());
    setPosition(0, 0);
    setSize(150, 148);
}

extern "C" {
#ifdef _WIN32
__declspec(dllexport) AEntityClient *buildEngine()
#elif defined (linux)
AEntityClient *buildEngine()
#endif
{
    return new AlienKappa();
}
}
