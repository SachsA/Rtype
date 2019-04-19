/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include "BulletsEnemiesMD.hpp"

BulletsEnemiesMD::BulletsEnemiesMD()
        : AEntityClient("bulletsEnemiesMD")
{
    setAssetPath("../Ressources/Effects/Assets/enemy_medium_bullet_1.png");
    setPosition(0, 0);
    setSize(80, 40);
    setSoundName(SHOT_ENEMY_SOUND());
}

extern "C" {
#ifdef _WIN32
__declspec(dllexport) AEntityClient *buildEngine()
#elif defined (linux)
AEntityClient *buildEngine()
#endif
{
    return new BulletsEnemiesMD();
}
}
