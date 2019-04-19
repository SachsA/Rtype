/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#ifndef CPP_RTYPE_2018_SHIP_HPP
#define CPP_RTYPE_2018_SHIP_HPP

#include <string>
#include <memory>
#include "../AEntity.hpp"
#include <random>
#include <chrono>

class Ship : public AEntity {
public:
//    explicit Ships(std::string const &typeName);
    explicit Ship(std::string const &);
    ~Ship() = default;

    int const takeDamage(AEntity const &opponent) override;
    std::vector<std::shared_ptr<ACommand>> getUpdate() override;
    void setUpdate(ACommand const &) override;

protected:
    ACommand attack(time_t timeAttack);

private:
    std::chrono::time_point<std::chrono::system_clock>  _lastAttack;
    std::vector<std::shared_ptr<ACommand>> _commands;
    bool _attack;

};

#endif //CPP_RTYPE_2018_SHIP_HPP
