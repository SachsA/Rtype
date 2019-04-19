/*
** EPITECH PROJECT, 2021
** Project: CPP_rtype_2018
** File: TextHandler.cpp
** File description:
** Handler for text : split SFMLHandler
**
** Created by Alexandre Sachs on 20/12/2018 at 17:00
*/

#include "../SFMLHandler.hpp"
#include "../../Components/Color/Color.hpp"

void SFMLHandler::createText(std::string const &key) {
    if (_texts.find(key) == _texts.end()) {
        _texts.emplace(key, sf::Text());
        _texts[key].setFont(*_font);
    }
}

void SFMLHandler::setTextRotation(std::string const &key, float angle) {
    if (_texts.find(key) != _texts.end()) {
        _texts[key].setRotation(angle);
    }
}

void SFMLHandler::setTextScale(std::string const &key, float factorX, float factorY) {
    if (_texts.find(key) != _texts.end()) {
        _texts[key].setScale(sf::Vector2f(factorX, factorY));
    }
}

void SFMLHandler::setTextPosition(std::string const &key, float x, float y) {
    if (_texts.find(key) != _texts.end()) {
        _texts[key].setPosition(sf::Vector2f(x, y));
    }
}

void SFMLHandler::setTextOrigin(std::string const &key, float x, float y) {
    if (_texts.find(key) != _texts.end()) {
        _texts[key].setOrigin(sf::Vector2f(x, y));
    }
}

void SFMLHandler::moveText(std::string const &key, float offsetX, float offsetY) {
    if (_texts.find(key) != _texts.end()) {
        _texts[key].move(sf::Vector2f(offsetX, offsetY));
    }
}

void SFMLHandler::rotateText(std::string const &key, float angle) {
    if (_texts.find(key) != _texts.end()) {
        _texts[key].rotate(angle);
    }
}

void SFMLHandler::scaleText(std::string const &key, float factorX, float factorY) {
    if (_texts.find(key) != _texts.end()) {
        _texts[key].scale(sf::Vector2f(factorX, factorY));
    }
}

std::string const SFMLHandler::getTextString(std::string const &key) {
    if (_texts.find(key) != _texts.end()) {
        return _texts[key].getString();
    }
    return "";
}

unsigned int SFMLHandler::getTextCharacterSize(std::string const &key) {
    if (_texts.find(key) != _texts.end()) {
        return _texts[key].getCharacterSize();
    }
    return 0;
}

float SFMLHandler::getTextLetterSpacing(std::string const &key) {
    if (_texts.find(key) != _texts.end()) {
        return _texts[key].getLetterSpacing();
    }
    return 0.0;
}

float SFMLHandler::getTextLineSpacing(std::string const &key) {
    if (_texts.find(key) != _texts.end()) {
        return _texts[key].getLineSpacing();
    }
    return 0.0;
}

float SFMLHandler::getTextOutlineThickness(std::string const &key) {
    if (_texts.find(key) != _texts.end()) {
        return _texts[key].getOutlineThickness();
    }
    return 0.0;
}

Vector2D<float> SFMLHandler::getTextLocalBounds(std::string const &key) {
    if (_texts.find(key) != _texts.end()) {
        return Vector2D<float>(_texts[key].getLocalBounds().width, _texts[key].getLocalBounds().height);
    }
    return Vector2D<float>(0.0, 0.0);
}

void SFMLHandler::setTextString(std::string const &key, std::string const &string) {
    if (_texts.find(key) != _texts.end()) {
        _texts[key].setString(string);
    }
}

void SFMLHandler::setTextCharacterSize(std::string const &key, unsigned int size) {
    if (_texts.find(key) != _texts.end()) {
        _texts[key].setCharacterSize(size);
    }
}

void SFMLHandler::setTextLineSpacing(std::string const &key, float factor) {
    if (_texts.find(key) != _texts.end()) {
        _texts[key].setLineSpacing(factor);
    }
}

void SFMLHandler::setTextLetterSpacing(std::string const &key, float factor) {
    if (_texts.find(key) != _texts.end()) {
        _texts[key].setLetterSpacing(factor);
    }
}

void SFMLHandler::setTextFillColor(std::string const &key, Color const &color) {
    if (_texts.find(key) != _texts.end()) {
        _texts[key].setFillColor(
                sf::Color(sf::Uint8(color.getRed()), sf::Uint8(color.getGreen()), sf::Uint8(color.getBlue()),
                          sf::Uint8(color.getAlpha())));
    }
}

void SFMLHandler::setTextOutlineColor(std::string const &key, Color const &color) {
    if (_texts.find(key) != _texts.end()) {
        _texts[key].setOutlineColor(
                sf::Color(sf::Uint8(color.getRed()), sf::Uint8(color.getGreen()), sf::Uint8(color.getBlue()),
                          sf::Uint8(color.getAlpha())));
    }
}

void SFMLHandler::setTextOutlineThickness(std::string const &key, float thickness) {
    if (_texts.find(key) != _texts.end()) {
        _texts[key].setOutlineThickness(thickness);
    }
}

void SFMLHandler::drawText(std::string const &key, Vector2D<unsigned int> const &position,
                           Vector2D<unsigned int> const &size) {
    auto x = static_cast<float>(size.x);
    auto y = static_cast<float>(size.y);

    if (_texts.find(key) != _texts.end()) {
        setTextPosition(key, position.x + ((x / 2) - (getTextLocalBounds(key).x /2)),
                        position.y + ((y / 2) - getTextLocalBounds(key).y));
        _window->draw(_texts[key]);
    }
}