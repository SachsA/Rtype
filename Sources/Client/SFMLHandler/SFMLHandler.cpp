/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include "SFMLHandler.hpp"

SFMLHandler::SFMLHandler() {
    _window = std::make_shared<sf::RenderWindow>();
    _event = std::make_shared<sf::Event>();
    _font = std::make_shared<sf::Font>();
    _musics = std::make_shared<std::unordered_map<std::string, std::unique_ptr<sf::Music>>>();
}

SFMLHandler::SFMLHandler(SFMLHandler const &sfmlHandler) {
    _window = sfmlHandler.getWindow();
    _event = sfmlHandler.getEvent();
    _font = sfmlHandler.getFont();
    _musics = sfmlHandler.getMusics();
}

SFMLHandler &SFMLHandler::operator=(SFMLHandler const &sfmlHandler) {
    _window = sfmlHandler.getWindow();
    _event = sfmlHandler.getEvent();
    _font = sfmlHandler.getFont();
    _musics = sfmlHandler.getMusics();
    return *this;
}

bool SFMLHandler::validColorValue(unsigned int value) {
    return (value >= 0 && value < 256);
}