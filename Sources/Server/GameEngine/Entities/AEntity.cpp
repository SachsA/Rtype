/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#include <iostream>
#include "AEntity.hpp"

AEntity::AEntity(std::string const &typeName, int const &newHP, float const &newFireRate, float const &newMovementSpeed)
    : _type(typeName), _HP(newHP), fireRate(newFireRate), _movementSpeed(newMovementSpeed) {
    _creationDate = std::chrono::system_clock::now();
    _creationPosition.x = 0;
    position.x = 0;
    _creationPosition.y = 500;
    position.y = 500;

}

AEntity::AEntity()
    : _type(""), _HP(1), fireRate(1.0), _movementSpeed(1.0) {
}

HitBox const &AEntity::getHitBox() const {
    return hitBox;
}

Vector2D<double> const &AEntity::getPosition() const {
    return position;
}

int AEntity::getHP() const {
    return _HP;
}

float AEntity::getMovementSpeed() const {
    return _movementSpeed;
}

std::string const& AEntity::getType() const {
    return _type;
}

void AEntity::setCreationDate(std::chrono::time_point<std::chrono::system_clock> const &newDate)
{
    _creationDate = newDate;
}

void AEntity::setCreationPosition(Vector2D<double> const &newPosition)
{
    _creationPosition.x = newPosition.x;
    _creationPosition.y = newPosition.y;
}

void AEntity::setPosition(Vector2D<double> const &newPosition)
{
    position.x = newPosition.x;
    position.y = newPosition.y;
}
