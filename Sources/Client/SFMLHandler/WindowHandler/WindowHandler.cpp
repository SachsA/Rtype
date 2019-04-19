/*
** EPITECH PROJECT, 2021
** Project: CPP_rtype_2018
** File: WindowHandler.cpp
** File description:
** Handler for Window : split SFMLHandler
**
** Created by Alexandre Sachs on 20/12/2018 at 16:49
*/

#include "../SFMLHandler.hpp"

void SFMLHandler::createWindow(unsigned int width, unsigned int height, const std::string &title) {
    _window->create(sf::VideoMode(width, height), title, sf::Style::Close);
    _window->setFramerateLimit(60);
	_window->setVerticalSyncEnabled(true);
}

enum Event SFMLHandler::closeEventWindow() {
    _window->close();
    return E_CLOSE;
}

void SFMLHandler::displayWindow() {
    _window->display();
}

void SFMLHandler::clearWindow() {
    _window->clear();
}

bool SFMLHandler::isOpenWindow() {
    return _window->isOpen();
}

bool SFMLHandler::listenEvent() {
    return _window->pollEvent(*_event);
}

void SFMLHandler::manageWindowPosition(unsigned int posX, unsigned int posY) {
    if (_window->getPosition().x != 0 || _window->getPosition().y != 0) {
        setWindowPosition(posX, posY);
    }
}

void SFMLHandler::setWindowPosition(unsigned int posX, unsigned int posY) {
    _window->setPosition(sf::Vector2i(posX, posY));
}

void SFMLHandler::setWindowSize(unsigned int sizeX, unsigned int sizeY) {
    _window->setSize(sf::Vector2u(sizeX, sizeY));
}

void SFMLHandler::setWindowTitle(const std::string &title) {
    _window->setTitle(title);
}

void SFMLHandler::setWindowCursorVisible(bool visible) {
    _window->setMouseCursorVisible(visible);
}

std::shared_ptr<sf::RenderWindow> SFMLHandler::getWindow() const {
    return _window;
}