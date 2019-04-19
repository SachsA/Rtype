/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#include <iostream>
#include <random>
#include "ShipBlue.hpp"

ShipBlue::ShipBlue() : Ship("shipBlue") {
    position.x = 50;
    position.y = 100;
}

extern "C" {
#ifdef _WIN32
	__declspec(dllexport) AEntity *buildEngine()
#elif defined (linux)
	AEntity *buildEngine()
#endif
{
    return new ShipBlue();
}
}