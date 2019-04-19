/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#ifndef CPP_RTYPE_2018_BULLETSSHIPSD_HPP
#define CPP_RTYPE_2018_BULLETSSHIPSD_HPP

#include <string>
#include <memory>
#include <chrono>
#include "../../AEntity.hpp"


class BulletsShipSD : public AEntity {
public:
    BulletsShipSD();
    ~BulletsShipSD() = default;


    int const takeDamage(AEntity const &opponent) override;
    std::vector<std::shared_ptr<ACommand>> getUpdate() override;
    void setUpdate(ACommand const &) override;

private:
    void moving(double x);

    time_t lastAttack;
    std::vector<std::shared_ptr<ACommand>> _commands;
};


#endif //CPP_RTYPE_2018_BULLETSSHIPSD_HPP
