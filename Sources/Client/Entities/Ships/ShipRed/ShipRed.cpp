/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include "ShipRed.hpp"

ShipRed::ShipRed()
        : AEntityClient("ship") {

    setAssetPath("../Ressources/Ships/Assets/ship_destroyer_red.png");
    setSoundName(ENGINE_SOUND());
    setPosition(0, 0);
    setSize(200, 129);
}

extern "C" {
#ifdef _WIN32
	__declspec(dllexport) AEntityClient *buildEngine()
#elif defined (linux)
	AEntityClient *buildEngine()
#endif
	{
    return new ShipRed();
}
}
