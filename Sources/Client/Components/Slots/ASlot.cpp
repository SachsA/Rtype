/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include <sstream>
#include "ASlot.hpp"
#include "../../../Communication/CommunicationTCP/CommunicationTCPClient/CommunicationTCPClient.hpp"

ASlot::ASlot(SFMLHandler const &sfmlHandler) : _isOccuped(false), _isReady(false), _isLocked(false) {
    _sfmlHandler = sfmlHandler;
}

Button const &ASlot::getButtonReady() const {
    return _ready;
}

Button const &ASlot::getButtonCancel() const {
    return _cancel;
}

Button const &ASlot::getButtonPlus() const {
    return _plus;
}

std::string const &ASlot::getPlayerText() const {
    return _playerText;
}

std::string const &ASlot::getPlayerName() const {
    return _playerName;
}

std::string const &ASlot::getShip() const {
    return _ship;
}

Vector2D<unsigned int> const &ASlot::getPlayerPosition() const {
    return _playerPos;
}

Vector2D<unsigned int> const &ASlot::getPlayerSize() const {
    return _playerSize;
}

bool const &ASlot::getisReady() const {
    return _isReady;
}

bool const &ASlot::getisOccuped() const {
    return _isOccuped;
}

bool const &ASlot::getisLocked() const {
    return _isLocked;
}

unsigned int const &ASlot::getState() const {
    return _state;
}

void ASlot::setShip(std::string const &ship) {
    _ship = ship;
}

void ASlot::setPlayerText(std::string const &text) {
    _sfmlHandler.setTextString(_playerText, text);
}

void ASlot::setPlayerName(std::string const &name) {
    _playerName = name;
}

void ASlot::setisReady(bool const &isReady) {
    _isReady = isReady;
}

void ASlot::setisOccuped(bool const &isOccuped) {
    _isOccuped = isOccuped;
}

void ASlot::setisLocked(bool const &isLocked){
    _isLocked = isLocked;
}

void ASlot::drawReady() {
    if (!_isReady)
        _sfmlHandler.drawSprite(_ready.getName());
    else
        _sfmlHandler.drawSprite(_ready.getNameActivated());
}

void ASlot::drawCancel() {
    if (_isOccuped)
        _sfmlHandler.drawSprite(_cancel.getName());
}

void ASlot::drawPlus() {
    if (!_isOccuped)
        _sfmlHandler.drawSprite(_plus.getName());
    else
        _sfmlHandler.drawSprite(_ship);
}

void ASlot::drawPlayerName() {
    _sfmlHandler.drawText(_playerText, _playerPos, _playerSize);
}

void ASlot::isPressed(Vector2D<int> const &position) {
    if (isReadySelected(position) && _isOccuped) {
        _sfmlHandler.drawSprite(_ready.getNameFocus());
    }
    else if (isPlusSelected(position) && !_isOccuped) {
        _sfmlHandler.drawSprite(_plus.getNameFocus());
    }
    else if (isCancelSelected(position) && _isOccuped) {
        _sfmlHandler.drawSprite(_cancel.getNameFocus());
    }
}

bool ASlot::isReleased(Vector2D<int> const &position) {
    if (isReadySelected(position))
        return true;
    else if (isPlusSelected(position))
        return true;
    else if (isCancelSelected(position))
        return true;
    return false;
}

CommandType ASlot::commandReleased(Vector2D<int> const &position) {
    if (isReadySelected(position) && _isOccuped)
        return PLAYER_READY;
    else if (isPlusSelected(position) && !_isOccuped)
        return JOIN_SLOT;
    else if (isCancelSelected(position) && _isOccuped)
        return LEAVE_SLOT;
    return UNDEFINED_CMD;
}


InstanceStatus ASlot::getReleased(Vector2D<int> const &position) {
    if (isReadySelected(position) && _isOccuped) {
        _isReady = !_isReady;
        return _ready.getInstance();
    }
    else if (isPlusSelected(position) && !_isOccuped) {
        _isOccuped = true;
        return _plus.getInstance();
    }
    else if (isCancelSelected(position) && _isOccuped) {
        _isReady = false;
        _isOccuped = false;
        return _cancel.getInstance();
    }
    return UNDEFINED_INSTANCE;
}

bool ASlot::isReadySelected(Vector2D<int> const &position) {
    return ((position.x >= _ready.getPosition().x && position.x <= _ready.getPosition().x + _ready.getSize().x) &&
            (position.y >= _ready.getPosition().y && position.y <= _ready.getPosition().y + _ready.getSize().y));
}

bool ASlot::isPlusSelected(Vector2D<int> const &position) {
    return ((position.x >= _plus.getPosition().x && position.x <= _plus.getPosition().x + _plus.getSize().x) &&
            (position.y >= _plus.getPosition().y && position.y <= _plus.getPosition().y + _plus.getSize().y));
}

bool ASlot::isCancelSelected(Vector2D<int> const &position) {
    return ((position.x >= _cancel.getPosition().x && position.x <= _cancel.getPosition().x + _cancel.getSize().x) &&
            (position.y >= _cancel.getPosition().y && position.y <= _cancel.getPosition().y + _cancel.getSize().y));
}