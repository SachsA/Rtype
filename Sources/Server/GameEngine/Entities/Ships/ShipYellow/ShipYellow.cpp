/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#include <iostream>
#include <random>
#include "ShipYellow.hpp"

ShipYellow::ShipYellow() : Ship("shipYellow") {
    position.x = 50;
    position.y = 600;
}

extern "C" {
#ifdef _WIN32
	__declspec(dllexport) AEntity *buildEngine()
#elif defined (linux)
	AEntity *buildEngine()
#endif
	{
    return new ShipYellow();
}
}