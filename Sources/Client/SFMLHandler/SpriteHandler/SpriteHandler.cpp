/*
** EPITECH PROJECT, 2021
** Project: CPP_rtype_2018
** File: SpriteHandler.cpp
** File description:
** Handler for sprite : split SFMLHandler
**
** Created by Alexandre Sachs on 20/12/2018 at 16:56
*/

#include "../SFMLHandler.hpp"

void SFMLHandler::createSprite(std::string const &key) {
    if (_textures.find(key) != _textures.end()) {
        if (_sprites.find(key) == _sprites.end()) {
            _sprites.emplace(key, sf::Sprite(_textures[key]));
        }
    }
}

void SFMLHandler::createSprite(std::string const &key, Vector2D<unsigned int> const &position,
                               Vector2D<unsigned int> const &size) {
    if (_textures.find(key) != _textures.end()) {
        if (_sprites.find(key) == _sprites.end()) {
            _sprites.emplace(key, sf::Sprite(_textures[key], sf::IntRect(0, 0, size.x, size.y)));
            setSpritePosition(key, position.x, position.y);
        }
    }
}

void SFMLHandler::setTexturetoSprite(std::string const &keyS, std::string const &keyT) {
    if (_textures.find(keyT) != _textures.end()) {
        if (_sprites.find(keyS) != _sprites.end()) {
            _sprites[keyS].setTexture(_textures[keyT]);
        }
    }
}

void SFMLHandler::setSpritePosition(std::string const &key, float x, float y) {
    if (_sprites.find(key) != _sprites.end()) {
        _sprites[key].setPosition(sf::Vector2f(x, y));
    }
}

void SFMLHandler::setSpriteColor(std::string const &key, Color const &color) {
    if (validColorValue(color.getRed()) && validColorValue(color.getGreen()) && validColorValue(color.getBlue()) && validColorValue(color.getAlpha())) {
        if (_sprites.find(key) != _sprites.end()) {
            _sprites[key].setColor(sf::Color(sf::Uint8(color.getRed()), sf::Uint8(color.getGreen()), sf::Uint8(color.getBlue()), sf::Uint8(color.getAlpha())));
        }
    }
}

void SFMLHandler::setSpriteRotation(std::string const &key, float angle) {
    if (_sprites.find(key) != _sprites.end()) {
        _sprites[key].setRotation(angle);
    }
}

void SFMLHandler::setSpriteScale(std::string const &key, float factorX, float factorY) {
    if (_sprites.find(key) != _sprites.end()) {
        _sprites[key].setScale(sf::Vector2f(factorX, factorY));
    }
}

void SFMLHandler::setSpriteOrigin(std::string const &key, float x, float y) {
    if (_sprites.find(key) != _sprites.end()) {
        _sprites[key].setOrigin(x, y);
    }
}

void SFMLHandler::moveSprite(std::string const &key, float offsetX, float offsetY) {
    if (_sprites.find(key) != _sprites.end()) {
        _sprites[key].move(sf::Vector2f(offsetX, offsetY));
    }
}

void SFMLHandler::rotateSprite(std::string const &key, float angle) {
    if (_sprites.find(key) != _sprites.end()) {
        _sprites[key].rotate(angle);
    }
}

void SFMLHandler::scaleSprite(std::string const &key, float factorX, float factorY) {
    if (_sprites.find(key) != _sprites.end()) {
        _sprites[key].scale(sf::Vector2f(factorX, factorY));
    }
}

void SFMLHandler::drawSprite(std::string const &key) {
    if (_sprites.find(key) != _sprites.end()) {
        _window->draw(_sprites[key]);
    }
}

void SFMLHandler::drawSpriteWithShader(std::string const &key) {
    if (_sprites.find(key) != _sprites.end()) {
        _window->draw(_sprites[key], &_shader);
    }
}

void SFMLHandler::loadShaderFromMemory(std::string const &vertexShader) {
    _shader.loadFromMemory(vertexShader, sf::Shader::Vertex);
}

void SFMLHandler::setShaderUniform(std::string const &params, float const &time) {
    _shader.setUniform(params, time);
}

float SFMLHandler::getClockElapsedTime() {
    return _clock.getElapsedTime().asSeconds();
}

void SFMLHandler::resetClock() {
    _clock.restart();
}

std::unordered_map<std::string, sf::Sprite> SFMLHandler::getSprites() const {
    return _sprites;
}