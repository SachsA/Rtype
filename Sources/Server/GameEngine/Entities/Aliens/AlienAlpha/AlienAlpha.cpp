/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#include <math.h>
#include <iostream>
#include <random>
#include "AlienAlpha.hpp"

AlienAlpha::AlienAlpha() : AEntity("alienAlpha", 1, 1.0, 1.0)
{
    _creationDate = std::chrono::system_clock::now();

    std::random_device r;
    std::default_random_engine randomEngine(r());
    std::uniform_int_distribution<int> distribution(100, 850);
    _creationPosition.y = distribution(randomEngine);
    _creationPosition.x = 1800;
    position = _creationPosition;
    hitBox.botRightCorner.y = 150;
    hitBox.botRightCorner.y = 300;
}


void AlienAlpha::setUpdate(ACommand const &)
{

}

std::vector<std::shared_ptr<ACommand>> AlienAlpha::getUpdate()
{
    _commands.clear();
    auto timeNow = std::chrono::system_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(timeNow - _creationDate);
    moving(diff.count());

    return _commands;
}

int const AlienAlpha::takeDamage(AEntity const &opponent)
{
    if (opponent.getType().substr(0, 4) == "ship" || opponent.getType() == "bulletsShipsSD")
        _HP = 0;

    return _HP;
}


void AlienAlpha::moving(double dist)
{
    if (_HP <= 0) {
        position.y = -400;
        position.x = -400;
        return;
    }
    position.y = _creationPosition.y + sin(dist / 500) * 100;
    position.x = _creationPosition.x - dist / 8;
}

extern "C" {
#ifdef _WIN32
__declspec(dllexport) AEntity *buildEngine()
#elif defined (linux)
AEntity *buildEngine()
#endif
{
    return new AlienAlpha();
}
}