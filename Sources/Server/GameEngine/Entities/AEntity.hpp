/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#ifndef AENTITIES_HPP
#define AENTITIES_HPP

#include <vector>
#include <string>
#include <memory>
#include <chrono>

#include "../../../Template/Vector2D/Vector2D.hpp"
#include "../../../Commands/ACommand.hpp"
#include "HitBox.hpp"

class AEntity {
public :
    AEntity(std::string const &typeName, int const &newHP, float const &newFireRate, float const &newMovementSpeed);
    AEntity();
    virtual ~AEntity() = default;

    virtual int const takeDamage(AEntity const &opponent) = 0;
    virtual std::vector<std::shared_ptr<ACommand>>  getUpdate() = 0;
    virtual void setUpdate(ACommand const &) = 0;

    void setCreationDate(std::chrono::time_point<std::chrono::system_clock> const &);
    void setCreationPosition(Vector2D<double> const &);
    void setPosition(Vector2D<double> const &);


    Vector2D<double> const &getPosition() const;
    HitBox const &getHitBox() const;
    int getHP() const;
    float getMovementSpeed() const;
    std::string const &getType() const;

protected:
    std::string _type;
    float fireRate;
    int _HP;
    float _movementSpeed;
    Vector2D<double> position;
    HitBox hitBox;
    std::chrono::time_point<std::chrono::system_clock>  _creationDate;
    Vector2D<double> _creationPosition;

};

#endif //AENTITIES_HPP
