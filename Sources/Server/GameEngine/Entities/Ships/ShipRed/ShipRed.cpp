/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#include <iostream>
#include <random>
#include "ShipRed.hpp"

ShipRed::ShipRed() : Ship("shipRed") {
    position.x = 50;
    position.y = 350;
}

extern "C" {
#ifdef _WIN32
	__declspec(dllexport) AEntity *buildEngine()
#elif defined (linux)
	AEntity *buildEngine()
#endif
	{
    return new ShipRed();
}
}