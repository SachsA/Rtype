/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include "BulletsShipsMD.hpp"

BulletsShipsMD::BulletsShipsMD()
        : AEntityClient("bulletsShipsMD")
{
    setAssetPath("../Ressources/Effects/Assets/ship_medium_bullet_2.png");
    setPosition(0, 0);
    setSize(80, 31);
    setSoundName(SHOT_ALLY_SOUND());
}

extern "C" {
#ifdef _WIN32
__declspec(dllexport) AEntityClient *buildEngine()
#elif defined (linux)
AEntityClient *buildEngine()
#endif
{
    return new BulletsShipsMD();
}
}
