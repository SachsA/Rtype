/*
** EPITECH PROJECT, 2021
** Project: CPP_rtype_2018
** File: FontHandler.cpp
** File description:
** Handler for font : split SFMLHandler
**
** Created by Alexandre Sachs on 20/12/2018 at 16:59
*/

#include "../SFMLHandler.hpp"

void SFMLHandler::createFontFromFile(std::string const &filename) {
    _font->loadFromFile(filename);
}

float SFMLHandler::getFontLineSpacing(unsigned int characterSize) const {
    return _font->getLineSpacing(characterSize);
}

float SFMLHandler::getFontUnderlinePosition(unsigned int characterSize) const {
    return _font->getUnderlinePosition(characterSize);
}

float SFMLHandler::getFontUnderlineThickness(unsigned int characterSize) const {
    return _font->getUnderlineThickness(characterSize);
}

std::shared_ptr<sf::Font> SFMLHandler::getFont() const {
    return _font;
}