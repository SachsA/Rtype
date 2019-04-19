/*
** EPITECH PROJECT, 2021
** Project: CPP_rtype_2018
** File: EventHandler.cpp
** File description:
** Handler for event : split SFMLHandler
**
** Created by Alexandre Sachs on 20/12/2018 at 17:06
*/

#include "../SFMLHandler.hpp"

enum Event SFMLHandler::manageWindowEvent() {
    switch (_event->type) {
        case sf::Event::TextEntered:
            return (_event->text.unicode == 8 || (_event->text.unicode > 32 && _event->text.unicode < 128)) ? E_TEXT_ENTERED : E_UNDEFINED;
        case sf::Event::KeyPressed:
            return getKeyEvent();
        case sf::Event::KeyReleased:
            return getKeyEvent();
        case sf::Event::MouseButtonPressed:
            return (_event->mouseButton.button == sf::Mouse::Left) ? E_MOUSE_PRESSED : E_UNDEFINED;
        case sf::Event::MouseButtonReleased:
            return (_event->mouseButton.button == sf::Mouse::Left) ? E_MOUSE_RELEASED : E_UNDEFINED;
        default:
            break;
    }
    return E_UNDEFINED;
}

enum Event SFMLHandler::getKeyEvent() {
    switch (_event->key.code) {
        case sf::Keyboard::A:
            return E_KEY_A;
        case sf::Keyboard::E:
            return E_KEY_E;
        case sf::Keyboard::Q:
            return E_KEY_Q;
        case sf::Keyboard::R:
            return E_KEY_R;
        case sf::Keyboard::S:
            return E_KEY_S;
        case sf::Keyboard::Z:
            return E_KEY_Z;
        case sf::Keyboard::Escape:
            return E_KEY_ESCAPE;
        case sf::Keyboard::Space:
            return E_KEY_SPACE;
        case sf::Keyboard::Left:
            return E_KEY_LEFT;
        case sf::Keyboard::Right:
            return E_KEY_RIGHT;
        case sf::Keyboard::Up:
            return E_KEY_UP;
        case sf::Keyboard::Down:
            return E_KEY_DOWN;
        default:
            break;
    }
    return E_UNDEFINED;
}

void SFMLHandler::setMousePosition(Vector2D<int> const &position) {
    _event->mouseButton.x = position.x;
    _event->mouseButton.y = position.y;
}

Vector2D<int> const SFMLHandler::getMousePressedPosition() {
    return Vector2D<int>(_event->mouseButton.x, _event->mouseButton.y);
}

std::shared_ptr<sf::Event> SFMLHandler::getEvent() const {
    return _event;
}

std::string SFMLHandler::getTextEntered() {
    std::string result;

    result += static_cast<char>(_event->text.unicode);
    return result;
}