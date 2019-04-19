/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#include <math.h>
#include <iostream>
#include <random>

#include "BulletsShipSD.hpp"

BulletsShipSD::BulletsShipSD() : AEntity("bulletsShipsSD", 1, 1.0, 1.0)
{
    hitBox.botRightCorner.x = 40;
    hitBox.botRightCorner.y = 40;
}

void BulletsShipSD::setUpdate(ACommand const &)
{

}

std::vector<std::shared_ptr<ACommand>> BulletsShipSD::getUpdate()
{
    _commands.clear();
    
    if (_HP <= 0) {
        return _commands;
    }
    auto timeNow = std::chrono::system_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(timeNow - _creationDate);
    moving(diff.count());

    return _commands;
}

int const BulletsShipSD::takeDamage(AEntity const &opponent)
{
    if (opponent.getType().substr(0, 4) != "ship") {
        _HP = 0;
        position.x = -400;
        position.y = -400;
    }

    return _HP;
}


void BulletsShipSD::moving(double dist)
{
    position.x = _creationPosition.x + dist / 3;
    position.y = _creationPosition.y;
}

extern "C" {
#ifdef _WIN32
__declspec(dllexport) AEntity *buildEngine()
#elif defined (linux)
AEntity *buildEngine()
#endif
{
    return new BulletsShipSD();
}
}
