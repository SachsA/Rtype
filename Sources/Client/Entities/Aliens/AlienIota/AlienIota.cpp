/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include "AlienIota.hpp"

AlienIota::AlienIota()
        : AEntityClient("alienIota")
{
    setAssetPath("../Ressources/Enemies/Assets/enemy_alien_8.png");
    setSoundName(ENGINE_SOUND());
    setPosition(0, 0);
    setSize(150, 125);
}

extern "C" {
#ifdef _WIN32
__declspec(dllexport) AEntityClient *buildEngine()
#elif defined (linux)
AEntityClient *buildEngine()
#endif
{
    return new AlienIota();
}
}
