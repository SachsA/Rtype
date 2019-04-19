/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#ifndef CPP_RTYPE_2018_VECTOR2D_HPP
#define CPP_RTYPE_2018_VECTOR2D_HPP

template<typename T>
struct Vector2D {
    Vector2D() : x(0), y(0) {};
    Vector2D(T const &newX, T const &newY) : x(newX), y(newY) {};
    Vector2D(Vector2D const &original) {
        x = original.x;
        y = original.y;
    };

    Vector2D &operator=(Vector2D const &original) {
        x = original.x;
        y = original.y;

        return *this;
    }

    T x;
    T y;
};

#endif //CPP_RTYPE_2018_VECTOR2D_HPP
