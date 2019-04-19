/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include "AlienTheta.hpp"

AlienTheta::AlienTheta()
        : AEntityClient("alienTheta")
{
    setAssetPath("../Ressources/Enemies/Assets/enemy_alien_9.png");
    setSoundName(ENGINE_SOUND());
    setPosition(0, 0);
    setSize(150, 164);
}

extern "C" {
#ifdef _WIN32
__declspec(dllexport) AEntityClient *buildEngine()
#elif defined (linux)
AEntityClient *buildEngine()
#endif
{
    return new AlienTheta();
}
}
