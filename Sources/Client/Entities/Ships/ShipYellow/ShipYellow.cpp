/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include "ShipYellow.hpp"

ShipYellow::ShipYellow()
        : AEntityClient("ship") {

    setAssetPath("../Ressources/Ships/Assets/ship_destroyer_yellow.png");
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
    return new ShipYellow();
}
}
