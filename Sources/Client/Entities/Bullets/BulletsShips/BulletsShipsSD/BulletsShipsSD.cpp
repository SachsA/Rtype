/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include "BulletsShipsSD.hpp"

BulletsShipsSD::BulletsShipsSD()
        : AEntityClient("bulletsShipsSD")
{
    setAssetPath("../Ressources/Effects/Assets/ship_small_bullet_1.png");
    setPosition(0, 0);
    setSize(40, 40);
    setSoundName(SHOT_ALLY_SOUND());
}

extern "C" {
#ifdef _WIN32
__declspec(dllexport) AEntityClient *buildEngine()
#elif defined (linux)
AEntityClient *buildEngine()
#endif
{
    return new BulletsShipsSD();
}
}
