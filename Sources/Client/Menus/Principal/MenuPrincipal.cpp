/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include "MenuPrincipal.hpp"
#include "ErrorsMenuPrincipal.hpp"
#include "ButtonsMenuPrincipal.hpp"
#include "ModelMenuPrincipal.hpp"
#include "../../Constants/Sounds.hpp"

MenuPrincipal::MenuPrincipal(SFMLHandler const &sfmlHandler, std::string &userName, std::string &serverName,
                             CommunicationTCPClient &server, std::vector<std::string> &listServer)
        : AMenu(sfmlHandler, userName, serverName), _server(server), _listServer(listServer) {
    initializeAssets();
    initializeButtons();
}

InstanceStatus MenuPrincipal::launch(enum Event const &event, InstanceStatus const &last) {
    draw();
    return manageEvent(event);
}

void MenuPrincipal::initializeAssets() {

    validAsset(MenuPrincipalModel::name(), MenuPrincipalModel::path(),
               Vector2D<unsigned int>(MenuPrincipalModel::topX, MenuPrincipalModel::topY),
               Vector2D<unsigned int>(MenuPrincipalModel::sizeX, MenuPrincipalModel::sizeY));
}

void MenuPrincipal::initializeButtons() {

    validButton(Vector2D<std::string>(ButtonCreatePrincipal::name(), ButtonCreatePrincipal::nameFocus()),
                Vector2D<std::string>(ButtonCreatePrincipal::path(), ButtonCreatePrincipal::pathFocus()),
                Vector2D<unsigned int>(ButtonCreatePrincipal::topX, ButtonCreatePrincipal::topY),
                Vector2D<unsigned int>(ButtonCreatePrincipal::sizeX, ButtonCreatePrincipal::sizeY));
    setButtonInstance(ButtonCreatePrincipal::name(), RIGHT_INSTANCE);

    validButton(Vector2D<std::string>(ButtonJoinPrincipal::name(), ButtonJoinPrincipal::nameFocus()),
                Vector2D<std::string>(ButtonJoinPrincipal::path(), ButtonJoinPrincipal::pathFocus()),
                Vector2D<unsigned int>(ButtonJoinPrincipal::topX, ButtonJoinPrincipal::topY),
                Vector2D<unsigned int>(ButtonJoinPrincipal::sizeX, ButtonJoinPrincipal::sizeY));
    setButtonInstance(ButtonJoinPrincipal::name(), ROOMS_INSTANCE);

    validButton(Vector2D<std::string>(ButtonSettingsPrincipal::name(), ButtonSettingsPrincipal::nameFocus()),
                Vector2D<std::string>(ButtonSettingsPrincipal::path(), ButtonSettingsPrincipal::pathFocus()),
                Vector2D<unsigned int>(ButtonSettingsPrincipal::topX, ButtonSettingsPrincipal::topY),
                Vector2D<unsigned int>(ButtonSettingsPrincipal::sizeX, ButtonSettingsPrincipal::sizeY));
    setButtonInstance(ButtonSettingsPrincipal::name(), SETTINGS_INSTANCE);

    validButton(Vector2D<std::string>(ButtonClosePrincipal::name(), ButtonClosePrincipal::nameFocus()),
                Vector2D<std::string>(ButtonClosePrincipal::path(), ButtonClosePrincipal::pathFocus()),
                Vector2D<unsigned int>(ButtonClosePrincipal::topX, ButtonClosePrincipal::topY),
                Vector2D<unsigned int>(ButtonClosePrincipal::sizeX, ButtonClosePrincipal::sizeY));
    setButtonInstance(ButtonClosePrincipal::name(), LOGIN_INSTANCE);

    validButton(Vector2D<std::string>(ExitGamePrincipal::name(), ExitGamePrincipal::nameFocus()),
                Vector2D<std::string>(ExitGamePrincipal::path(), ExitGamePrincipal::pathFocus()),
                Vector2D<unsigned int>(ExitGamePrincipal::topX, ExitGamePrincipal::topY),
                Vector2D<unsigned int>(ExitGamePrincipal::sizeX, ExitGamePrincipal::sizeY));
    setButtonInstance(ExitGamePrincipal::name(), EXIT_INSTANCE);
}

void MenuPrincipal::validAsset(std::string const &name, std::string const &path, Vector2D<unsigned int> const &position,
                               Vector2D<unsigned int> const &size) {
    std::ifstream infile(path);

    if (!infile.good())
        throw ErrorsMenuPrincipal(std::cerr, "This file '" + path + "' does not exist");
    else {
        _sfmlHandler.createTextureFromFile(name, path, size.x, size.y);
        _sfmlHandler.createSprite(name, position, size);
        infile.clear();
    }
}

void MenuPrincipal::validButton(Vector2D<std::string> const &names, Vector2D<std::string> const &paths,
                                Vector2D<unsigned int> const &position, Vector2D<unsigned int> const &size) {
    std::ifstream infileFirst(paths.x);
    std::ifstream infileSecond(paths.y);

    if (!infileFirst.good())
        throw ErrorsMenuPrincipal(std::cerr, "This file '" + paths.x + "' does not exist");
    else if (!infileSecond.good())
        throw ErrorsMenuPrincipal(std::cerr, "This file '" + paths.y + "' does not exist");
    else {
        createButton(names, paths, position, size);
        infileFirst.clear();
        infileSecond.clear();
    }
}

void MenuPrincipal::createButton(Vector2D<std::string> const &names, Vector2D<std::string> const &paths,
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

void MenuPrincipal::setButtonInstance(std::string const &name, InstanceStatus const &status) {
    if (_buttons.find(name) != _buttons.end())
        _buttons[name].setInstance(status);
    else
        throw ErrorsMenuPrincipal(std::cerr, "Button '" + name + "' not found");
}

void MenuPrincipal::draw() {
    _sfmlHandler.drawSprite(MenuPrincipalModel::name());
    _sfmlHandler.drawSprite(ButtonClosePrincipal::name());
    _sfmlHandler.drawSprite(ExitGamePrincipal::name());
    _sfmlHandler.drawSprite(ButtonCreatePrincipal::name());
    _sfmlHandler.drawSprite(ButtonJoinPrincipal::name());
    _sfmlHandler.drawSprite(ButtonSettingsPrincipal::name());
}

InstanceStatus MenuPrincipal::manageEvent(enum Event const &event) {
    switch (event) {
        case E_MOUSE_PRESSED:
            return buttonPressed(_sfmlHandler.getMousePressedPosition());
        case E_MOUSE_RELEASED:
            return buttonReleased(_sfmlHandler.getMousePressedPosition());
        default:
            break;
    }
    return UNDEFINED_INSTANCE;
}

InstanceStatus MenuPrincipal::buttonPressed(Vector2D<int> const &position) {
    for (auto &_button : _buttons) {
        if (_button.second.isSelected(position)) {
            _sfmlHandler.drawSprite(_button.second.getNameFocus());
            return UNDEFINED_INSTANCE;
        }
    }
    return UNDEFINED_INSTANCE;
}

InstanceStatus MenuPrincipal::buttonReleased(Vector2D<int> const &position) {
    _sfmlHandler.setMousePosition(Vector2D<int>(-1, -1));

    for (auto &_button : _buttons) {
        if (_button.second.isSelected(position)) {
            switch (_button.second.getInstance()) {
                case LOGIN_INSTANCE:
					return sendLeaveServer();
                case ROOMS_INSTANCE:
					if (sendJoinServer() == LOGIN_INSTANCE)
						return LOGIN_INSTANCE;
                default:
                    break;
            }
            _sfmlHandler.playMusic((_button.second.getName() != ButtonClosePrincipal::name() ? CONFIRM_SOUND : RETURN_SOUND)());
			if (_button.second.getName() == ExitGamePrincipal::name())
                sendLeaveServer();
            return _button.second.getInstance();
        }
    }
    return UNDEFINED_INSTANCE;
}

InstanceStatus MenuPrincipal::returnToLogin() {
	_server.decoClient();
	_userName.clear();
	_serverName.clear();
	_listServer.clear();
	return LOGIN_INSTANCE;
}

InstanceStatus MenuPrincipal::sendJoinServer() {
    std::string str;
    std::istringstream stream;

	if (!_server.send("LIST_INSTANCES;" + _userName))
		return returnToLogin();

    auto commandVector = _server.receive();
	if (!commandVector.empty() && commandVector.front().get()->commandType == DISCONNECT_SERVER)
		return returnToLogin();
	
	if (!commandVector.empty() && commandVector.front().get()->commandType == LIST_INSTANCES_RESPONSE) {

        auto cmd = static_cast<InstancesListResponseCommand *>(&(*commandVector.front()));

        if (cmd->instanceList != "EMPTY") {
            stream = std::istringstream(cmd->instanceList);
            while (getline(stream, str, ':')) {
                _listServer.push_back(str);
            }
        }
    }
	return UNDEFINED_INSTANCE;
}

InstanceStatus MenuPrincipal::sendLeaveServer() {
    if (!_server.send("LEAVE_SERVER;" + _userName))
        return returnToLogin();
    return returnToLogin();
}