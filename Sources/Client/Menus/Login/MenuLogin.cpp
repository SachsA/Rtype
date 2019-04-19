/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/


#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "MenuLogin.hpp"
#include "ErrorsMenuLogin.hpp"
#include "ButtonsMenuLogin.hpp"
#include "ModelMenuLogin.hpp"
#include "../../Constants/Sounds.hpp"


MenuLogin::MenuLogin(SFMLHandler const &sfmlHandler, std::string &userName, std::string &serverName,
                     CommunicationTCPClient &server)
        : AMenu(sfmlHandler, userName, serverName), _focusInput(false), _server(server) {
    initializeAssets();
    initializeButtons();
    initializeInfoText();
    initializeUsernameText();
}

InstanceStatus MenuLogin::launch(enum Event const &event, InstanceStatus const &last) {
    draw();
    return manageEvent(event);
}

void MenuLogin::initializeAssets() {

    validAsset(MenuLoginModel::name(), MenuLoginModel::path(),
               Vector2D<unsigned int>(MenuLoginModel::topX, MenuLoginModel::topY),
               Vector2D<unsigned int>(MenuLoginModel::sizeX, MenuLoginModel::sizeY));

    validAsset(TextUsernameLogin::name(), TextUsernameLogin::path(),
               Vector2D<unsigned int>(TextUsernameLogin::topX, TextUsernameLogin::topY),
               Vector2D<unsigned int>(TextUsernameLogin::sizeX, TextUsernameLogin::sizeY));
    validAsset(TextUsernameLogin::nameFocus(), TextUsernameLogin::pathFocus(),
               Vector2D<unsigned int>(TextUsernameLogin::topX, TextUsernameLogin::topY),
               Vector2D<unsigned int>(TextUsernameLogin::sizeX, TextUsernameLogin::sizeY));

}

void MenuLogin::initializeButtons() {

    validButton(Vector2D<std::string>(ButtonLogin::name(), ButtonLogin::nameFocus()),
                Vector2D<std::string>(ButtonLogin::path(), ButtonLogin::pathFocus()),
                Vector2D<unsigned int>(ButtonLogin::topX, ButtonLogin::topY),
                Vector2D<unsigned int>(ButtonLogin::sizeX, ButtonLogin::sizeY));
    setButtonInstance(ButtonLogin::name(), PRINCIPAL_INSTANCE);

    validButton(Vector2D<std::string>(ExitGameLogin::name(), ExitGameLogin::nameFocus()),
                Vector2D<std::string>(ExitGameLogin::path(), ExitGameLogin::pathFocus()),
                Vector2D<unsigned int>(ExitGameLogin::topX, ExitGameLogin::topY),
                Vector2D<unsigned int>(ExitGameLogin::sizeX, ExitGameLogin::sizeY));
    setButtonInstance(ExitGameLogin::name(), EXIT_INSTANCE);
}

void MenuLogin::initializeInfoText() {
    _sfmlHandler.createText(TextInfosLogin::name());
    _sfmlHandler.setTextString(TextInfosLogin::name(), INFO_LOGIN());
    _sfmlHandler.setTextFillColor(TextInfosLogin::name(), Color(255, 255, 255, 255));
    _sfmlHandler.setTextCharacterSize(TextInfosLogin::name(), 35);
}

void MenuLogin::initializeUsernameText() {
    _sfmlHandler.createText(TextUsernameLogin::name());
    _sfmlHandler.setTextString(TextUsernameLogin::name(), "");
    _sfmlHandler.setTextFillColor(TextUsernameLogin::name(), Color(255, 255, 255, 255));
    _sfmlHandler.setTextCharacterSize(TextUsernameLogin::name(), 30);
}

void MenuLogin::validAsset(std::string const &name, std::string const &path, Vector2D<unsigned int> const &position,
                           Vector2D<unsigned int> const &size) {
    std::ifstream infile(path);

    if (!infile.good())
        throw ErrorsMenuLogin(std::cerr, "This file '" + path + "' does not exist");
    else {
        _sfmlHandler.createTextureFromFile(name, path, size.x, size.y);
        _sfmlHandler.createSprite(name, position, size);
        infile.clear();
    }
}

void MenuLogin::validButton(Vector2D<std::string> const &names, Vector2D<std::string> const &paths,
                            Vector2D<unsigned int> const &position, Vector2D<unsigned int> const &size) {
    std::ifstream infileFirst(paths.x);
    std::ifstream infileSecond(paths.y);

    if (!infileFirst.good())
        throw ErrorsMenuLogin(std::cerr, "This file '" + paths.x + "' does not exist");
    else if (!infileSecond.good())
        throw ErrorsMenuLogin(std::cerr, "This file '" + paths.y + "' does not exist");
    else {
        createButton(names, paths, position, size);
        infileFirst.clear();
        infileSecond.clear();
    }
}

void MenuLogin::createButton(Vector2D<std::string> const &names, Vector2D<std::string> const &paths,
                             Vector2D<unsigned int> const &position, Vector2D<unsigned int> const &size) {
    _buttons.emplace(names.x, Button(names, position, size));
    _buttons[names.x].setPaths(paths);

    _sfmlHandler.createTextureFromFile(names.x, paths.x, size.x, size.y);
    _sfmlHandler.createSprite(names.x, position, size);
    if (!names.y.empty() && !paths.y.empty()) {
        _sfmlHandler.createTextureFromFile(names.y, paths.y, size.x, size.y);
        _sfmlHandler.createSprite(names.y, position, size);
    }
}

void MenuLogin::setButtonInstance(std::string const &name, InstanceStatus const &status) {
    if (_buttons.find(name) != _buttons.end())
        _buttons[name].setInstance(status);
    else
        throw ErrorsMenuLogin(std::cerr, "Button '" + name + "' not found");
}

void MenuLogin::draw() {

    _sfmlHandler.drawSprite(MenuLoginModel::name());
    _sfmlHandler.drawSprite(ExitGameLogin::name());
    _sfmlHandler.drawSprite(ButtonLogin::name());
    _sfmlHandler.drawText(TextInfosLogin::name(),
                          Vector2D<unsigned int>(TextInfosLogin::topX, TextInfosLogin::topY),
                          Vector2D<unsigned int>(TextInfosLogin::sizeX, TextInfosLogin::sizeY));
    if (_userName.empty()) {
        _sfmlHandler.setTextFillColor(TextUsernameLogin::name(), Color(255, 255, 255, 255));
        _sfmlHandler.drawSprite(TextUsernameLogin::name());
    } else {
        _sfmlHandler.setTextFillColor(TextUsernameLogin::name(), Color(4, 16, 28, 255));
        _sfmlHandler.drawSprite(TextUsernameLogin::nameFocus());
    }
    _sfmlHandler.drawText(TextUsernameLogin::name(),
                          Vector2D<unsigned int>(TextUsernameLogin::topX, TextUsernameLogin::topY),
                          Vector2D<unsigned int>(TextUsernameLogin::sizeX, TextUsernameLogin::sizeY));
}

InstanceStatus MenuLogin::manageEvent(enum Event const &event) {
    switch (event) {
        case E_MOUSE_PRESSED:
            return buttonPressed(_sfmlHandler.getMousePressedPosition());
        case E_MOUSE_RELEASED:
            return buttonReleased(_sfmlHandler.getMousePressedPosition());
        case E_TEXT_ENTERED:
            _sfmlHandler.setTextString(TextInfosLogin::name(), INFO_LOGIN());
            _sfmlHandler.setTextFillColor(TextInfosLogin::name(), Color(255, 255, 255, 255));
            return textEntered(_sfmlHandler.getTextEntered());
        default:
            break;
    }
    return UNDEFINED_INSTANCE;
}

InstanceStatus MenuLogin::buttonPressed(Vector2D<int> const &position) {
    for (auto &_button : _buttons) {
        if (_button.second.isSelected(position)) {
            if (_button.second.getName() != ButtonLogin::name())
                _sfmlHandler.drawSprite(_button.second.getNameFocus());
            else if (!_userName.empty())
                _sfmlHandler.drawSprite(_button.second.getNameFocus());
            return UNDEFINED_INSTANCE;
        }
    }
    return UNDEFINED_INSTANCE;
}


InstanceStatus MenuLogin::buttonReleased(Vector2D<int> const &position) {
    _sfmlHandler.setMousePosition(Vector2D<int>(-1, -1));

    for (auto &_button : _buttons) {
        if (_button.second.isSelected(position) && !_userName.empty() &&
            _button.second.getName() == ButtonLogin::name()) {
			return sendUserName(_button.second.getName());
        } else if (_button.second.isSelected(position) && _button.second.getName() != ButtonLogin::name())
            return _button.second.getInstance();
    }
    return UNDEFINED_INSTANCE;
}

InstanceStatus MenuLogin::returnToLogin() {
	_server.decoClient();
	_userName.clear();
	_serverName.clear();
	_sfmlHandler.setTextString(TextUsernameLogin::name(), "");
	return LOGIN_INSTANCE;
}

InstanceStatus MenuLogin::sendUserName(std::string const &name) {
	if (!_server.initialisation(IP_ADDRESS(), "6000") || !_server.send(_userName))
		return returnToLogin();
    auto commandVector = _server.receive();
	if (!commandVector.empty() && commandVector.front().get()->commandType == DISCONNECT_SERVER)
		return returnToLogin();
    if (!commandVector.empty() && commandVector.front().get()->commandType == VALID_USER) {
        auto cmd = static_cast<ValidUserCommand *>(&(*commandVector.front()));
		if (cmd->accept) {
			_sfmlHandler.setTextString(TextUsernameLogin::name(), "");
            _sfmlHandler.playMusic(CONFIRM_SOUND());
            return _buttons[name].getInstance();
		} else {
            _sfmlHandler.setTextString(TextInfosLogin::name(), ERROR_LOGIN());
            _sfmlHandler.setTextFillColor(TextInfosLogin::name(), Color(255, 0, 0, 255));
		}
    }
    return UNDEFINED_INSTANCE;
}

InstanceStatus MenuLogin::textEntered(std::string const &text) {
    std::string temp = text;

    if (text != "\b" || _userName.empty()) {
        if ((_userName + temp).size() < 16 && (text != "\b") && (text != ":") && (text != "/")) {
            std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
            _userName.append(temp);
            _sfmlHandler.setTextString(TextUsernameLogin::name(), _userName);
        }
    } else {
        _userName.erase(_userName.size() - 1, 1);
        _sfmlHandler.setTextString(TextUsernameLogin::name(), _userName);
    }
    return UNDEFINED_INSTANCE;
}