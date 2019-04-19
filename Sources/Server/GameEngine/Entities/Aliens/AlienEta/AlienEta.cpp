/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#include <math.h>
#include <iostream>
#include <random>
#include "AlienEta.hpp"

AlienEta::AlienEta() : AEntity("alienEtaServer", 1, 1.0, 1.0) {
    _creationDate = std::chrono::system_clock::now();

    std::random_device r;
    std::default_random_engine randomEngine(r());
    std::uniform_int_distribution<int> distribution(100, 1000);
    _creationPosition.y = distribution(randomEngine);
    _creationPosition.x = 0;
    position = _creationPosition;
}


void AlienEta::setUpdate(ACommand const &)
{

}

std::vector<std::shared_ptr<ACommand>> AlienEta::getUpdate()
{
    _commands.clear();
    auto timeNow = std::chrono::system_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(timeNow - _creationDate);
    moving(diff.count());

    return _commands;
}

int const AlienEta::takeDamage(AEntity const &opponent)
{
    if (opponent.getType().substr(0, 1) == "ship" || opponent.getType().substr(0, 11) == "bulletsShip")
        _HP = 0;

    return _HP;
}


void AlienEta::moving(double dist)
{
    position.y = _creationPosition.y + sin(dist / 5) * 100;
    position.x = _creationPosition.x + dist / 10;
}

extern "C" {
#ifdef _WIN32
__declspec(dllexport) AEntity *buildEngine()
#elif defined (linux)
AEntity *buildEngine()
#endif
{
    return new AlienEta();
}
}