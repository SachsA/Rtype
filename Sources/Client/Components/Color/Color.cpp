/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include "Color.hpp"

Color::Color(unsigned int const &red, unsigned int const &green, unsigned int const &blue, unsigned int const &alpha)
        : _red(red), _green(green), _blue(blue), _alpha(alpha) {}

void Color::setRed(unsigned int const &red) {
    _red = red;
}

void Color::setGreen(unsigned int const &green) {
    _green = green;
}

void Color::setBlue(unsigned int const &blue) {
    _blue = blue;
}

void Color::setAlpha(unsigned int const &alpha) {
    _alpha = alpha;
}

unsigned int const &Color::getRed() const {
    return _red;
}

unsigned int const &Color::getGreen() const {
    return _green;
}

unsigned int const &Color::getBlue() const {
    return _blue;
}

unsigned int const &Color::getAlpha() const {
    return _alpha;
}