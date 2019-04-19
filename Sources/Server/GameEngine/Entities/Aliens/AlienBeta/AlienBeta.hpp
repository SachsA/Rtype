/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#ifndef ALIENBETA_HPP
#define ALIENBETA_HPP

#include <string>
#include <memory>
#include <chrono>
#include "../../AEntity.hpp"

class AlienBeta : public AEntity {
public:
    AlienBeta();
    ~AlienBeta() = default;

    int const takeDamage(AEntity const &opponent) override;
    std::vector<std::shared_ptr<ACommand>>  getUpdate() override;
    void setUpdate(ACommand const &) override;

private:
    void moving(double x);

    time_t lastAttack;
    std::chrono::time_point<std::chrono::system_clock>  _creationDate;
    Vector2D<double> _creationPosition;
    std::vector<std::shared_ptr<ACommand>> _commands;
};


#endif //ALIENBETA_HPP
