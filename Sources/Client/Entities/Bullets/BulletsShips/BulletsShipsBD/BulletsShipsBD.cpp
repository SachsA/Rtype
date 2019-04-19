/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include "BulletsShipsBD.hpp"

BulletsShipsBD::BulletsShipsBD()
        : AEntityClient("bulletsShipsBD")
{
    setAssetPath("../Ressources/Effects/Assets/ship_big_bullet_2.png");
    setPosition(0, 0);
    setSize(100, 50);
    setSoundName(SHOT_ALLY_SOUND());
}

extern "C" {
#ifdef _WIN32
__declspec(dllexport) AEntityClient *buildEngine()
#elif defined (linux)
AEntityClient *buildEngine()
#endif
{
    return new BulletsShipsBD();
}
}
