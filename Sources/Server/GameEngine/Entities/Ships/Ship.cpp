/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#include <iostream>

#include "../../../../Commands/GameCommands/GameCommands.hpp"
#include "Ship.hpp"

Ship::Ship(std::string const &type) : AEntity(type, 1, 1.0, 1.0), _attack(false)
{
    hitBox.botRightCorner.y = 150;
    hitBox.botRightCorner.x = 250;
    _lastAttack = std::chrono::system_clock::now();
}


int const Ship::takeDamage(AEntity const &opponent)
{
    if (opponent.getType().substr(0, 4) != "ship" && opponent.getType() != "bulletsShipsSD") {
        _HP = 0;
        position.x = -400;
        position.y = -400;
    }
    return _HP;
}


std::vector<std::shared_ptr<ACommand>> Ship::getUpdate()
{
    _commands.clear();
    if (!_attack)
        return _commands;
    auto timeNow = std::chrono::system_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(timeNow - _lastAttack);

    if (diff.count() > fireRate * 1000) {
        auto bulletPosition = position;

        bulletPosition.y = position.y + 43;
        bulletPosition.x = position.x + 200;

        _commands.emplace_back(std::make_shared<CreateLibraryCommand>("bulletsShipsSD", bulletPosition, timeNow));
        _lastAttack = timeNow;
        _attack = false;
    }
    return _commands;
}

void Ship::setUpdate(ACommand const &cmd)
{
    if (_HP <= 0) {
        return;
    }
    if (cmd.commandType == GAME_MOVE_UP) {
        if (position.y - 10 < 10)
            position.y = 10;
        else
            position.y -= 10;
    } else if (cmd.commandType == GAME_MOVE_DOWN) {
        if (position.y + 10 > 875)
            position.y = 875;
        else
            position.y += 10;
    } else if (cmd.commandType == GAME_MOVE_LEFT) {
        if (position.x - 10 < 10)
            position.x = 10;
        else
            position.x -= 10;
    } else if (cmd.commandType == GAME_MOVE_RIGHT) {
        if (position.x  + 10 > 1705)
            position.x = 1705;
        else
            position.x += 10;
    } else if (cmd.commandType == GAME_ATTACK) {
        _attack = true;
    }
}

ACommand Ship::attack(time_t timeAttack)
{
    return CreateLibraryCommand("bulletsShipsSD", position, _lastAttack);
}
