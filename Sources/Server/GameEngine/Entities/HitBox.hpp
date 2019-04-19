/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#ifndef CPP_RTYPE_2018_HITBOX_HPP
#define CPP_RTYPE_2018_HITBOX_HPP

#include "../../../Template/Vector2D/Vector2D.hpp"

struct HitBox {
    Vector2D<float> topLeftCorner;
    Vector2D<float> botRightCorner;
};

#endif //CPP_RTYPE_2018_HITBOX_HPP
