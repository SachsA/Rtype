/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include "Button.hpp"

Button::Button(Vector2D<std::string> const &names, Vector2D<unsigned int> const &position,
               Vector2D<unsigned int> const &size) : _name(names.x), _nameFocus(names.y),
               _position(position), _size(size), _status(UNDEFINED_INSTANCE) {

}

Button::~Button() {}

bool Button::isSelected(Vector2D<int> const &position) {
    return ((position.x >= _position.x && position.x <= _position.x + _size.x) &&
            (position.y >= _position.y && position.y <= _position.y + _size.y));
}

void Button::setPaths(Vector2D<std::string> const &paths) {
    _path = paths.x;
    _pathFocus = paths.y;
}

void Button::setActivated(std::string const &name, std::string const &path) {
    _nameActivated = name;
    _pathActivated = path;
}

void Button::setInstance(InstanceStatus const &status) {
    _status = status;
}

std::string const &Button::getName() const {
    return _name;
}

std::string const &Button::getNameFocus() const {
    return _nameFocus;
}

std::string const &Button::getNameActivated() const {
    return _nameActivated;
}

std::string const &Button::getPath() const {
    return _path;
}

std::string const &Button::getPathFocus() const {
    return _pathFocus;
}

std::string const &Button::getPathActivated() const {
    return _pathActivated;
}

Vector2D<unsigned int> const &Button::getPosition() const {
    return _position;
}

Vector2D<unsigned int> const &Button::getSize() const {
    return _size;
}

InstanceStatus const &Button::getInstance() const {
    return _status;
}

void createButton() {

}

