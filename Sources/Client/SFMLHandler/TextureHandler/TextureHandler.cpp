/*
** EPITECH PROJECT, 2021
** Project: CPP_rtype_2018
** File: TextureHandler.cpp
** File description:
** Handler for texture : split SFMLHandler
**
** Created by Alexandre Sachs on 20/12/2018 at 16:54
*/

#include "../SFMLHandler.hpp"

void SFMLHandler::createTexture(std::string const &key, unsigned int width, unsigned int height) {
    sf::Texture texture = sf::Texture();

    texture.create(width, height);
    _textures.emplace(key, texture);
}

void SFMLHandler::createTextureFromFile(const std::string &key, const std::string &filename, unsigned int width,
                                        unsigned int height) {
    if (_textures.find(key) == _textures.end())
        createTexture(key, width, height);
    _textures[key].loadFromFile(filename);
}

void SFMLHandler::updateTexture(std::string const &key) {
    if (_textures.find(key) != _textures.end())
        _textures[key].update(*_window);
}

void SFMLHandler::updateTexture(std::string const &key, unsigned int width, unsigned int height) {
    if (_textures.find(key) != _textures.end())
        _textures[key].update(*_window, width, height);
}

void SFMLHandler::setTextureSmooth(std::string const &key, bool smooth) {
    if (_textures.find(key) != _textures.end())
        _textures[key].setSmooth(smooth);
}

void SFMLHandler::setTextureRepeated(std::string const &key, bool repeated) {
    if (_textures.find(key) != _textures.end())
        _textures[key].setRepeated(repeated);
}

std::unordered_map<std::string, sf::Texture> SFMLHandler::getTextures() const {
    return _textures;
}