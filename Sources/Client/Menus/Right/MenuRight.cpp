/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "MenuRight.hpp"
#include "ErrorsMenuRight.hpp"
#include "ButtonsMenuRight.hpp"
#include "ModelMenuRight.hpp"
#include "../../Constants/Sounds.hpp"

MenuRight::MenuRight(SFMLHandler const &sfmlHandler, std::string &userName, std::string &serverName,
                     CommunicationTCPClient &server, CommunicationTCPClient &lobbyTCP,
                     CommunicationUDPClient &lobbyUDP)
        : AMenu(sfmlHandler, userName, serverName), _server(server), _lobbyTCP(lobbyTCP), _lobbyUDP(lobbyUDP) {
    initializeAssets();
    initializeButtons();
    initializeServerInfos();
    initializeServerName();
}

InstanceStatus MenuRight::launch(enum Event const &event, InstanceStatus const &last) {
    draw();
    return manageEvent(event);
}

void MenuRight::initializeAssets() {

    validAsset(MenuRightModel::name(), MenuRightModel::path(),
               Vector2D<unsigned int>(MenuRightModel::topX, MenuRightModel::topY),
               Vector2D<unsigned int>(MenuRightModel::sizeX, MenuRightModel::sizeY));

    validAsset(TextServerName::name(), TextServerName::path(),
               Vector2D<unsigned int>(TextServerName::topX, TextServerName::topY),
               Vector2D<unsigned int>(TextServerName::sizeX, TextServerName::sizeY));

    validAsset(TextServerName::nameFocus(), TextServerName::pathFocus(),
               Vector2D<unsigned int>(TextServerName::topX, TextServerName::topY),
               Vector2D<unsigned int>(TextServerName::sizeX, TextServerName::sizeY));
}

void MenuRight::initializeButtons() {

    validButton(Vector2D<std::string>(ButtonPublicRight::name(), ButtonPublicRight::nameFocus()),
                Vector2D<std::string>(ButtonPublicRight::path(), ButtonPublicRight::pathFocus()),
                Vector2D<unsigned int>(ButtonPublicRight::topX, ButtonPublicRight::topY),
                Vector2D<unsigned int>(ButtonPublicRight::sizeX, ButtonPublicRight::sizeY));
    setButtonInstance(ButtonPublicRight::name(), LOBBY_INSTANCE);

    validButton(Vector2D<std::string>(ButtonPrivateRight::name(), ButtonPrivateRight::nameFocus()),
                Vector2D<std::string>(ButtonPrivateRight::path(), ButtonPrivateRight::pathFocus()),
                Vector2D<unsigned int>(ButtonPrivateRight::topX, ButtonPrivateRight::topY),
                Vector2D<unsigned int>(ButtonPrivateRight::sizeX, ButtonPrivateRight::sizeY));
    setButtonInstance(ButtonPrivateRight::name(), LOBBY_INSTANCE);

    validButton(Vector2D<std::string>(ButtonSettingsRight::name(), ButtonSettingsRight::nameFocus()),
                Vector2D<std::string>(ButtonSettingsRight::path(), ButtonSettingsRight::pathFocus()),
                Vector2D<unsigned int>(ButtonSettingsRight::topX, ButtonSettingsRight::topY),
                Vector2D<unsigned int>(ButtonSettingsRight::sizeX, ButtonSettingsRight::sizeY));
    setButtonInstance(ButtonSettingsRight::name(), SETTINGS_INSTANCE);

    validButton(Vector2D<std::string>(ButtonCloseRight::name(), ButtonCloseRight::nameFocus()),
                Vector2D<std::string>(ButtonCloseRight::path(), ButtonCloseRight::pathFocus()),
                Vector2D<unsigned int>(ButtonCloseRight::topX, ButtonCloseRight::topY),
                Vector2D<unsigned int>(ButtonCloseRight::sizeX, ButtonCloseRight::sizeY));
    setButtonInstance(ButtonCloseRight::name(), PRINCIPAL_INSTANCE);

    validButton(Vector2D<std::string>(ExitGameRight::name(), ExitGameRight::nameFocus()),
                Vector2D<std::string>(ExitGameRight::path(), ExitGameRight::pathFocus()),
                Vector2D<unsigned int>(ExitGameRight::topX, ExitGameRight::topY),
                Vector2D<unsigned int>(ExitGameRight::sizeX, ExitGameRight::sizeY));
    setButtonInstance(ExitGameRight::name(), EXIT_INSTANCE);
}

void MenuRight::initializeServerInfos() {
    _sfmlHandler.createText(TextInfosServer::name());
    _sfmlHandler.setTextString(TextInfosServer::name(), INFOS_SERVER());
    _sfmlHandler.setTextFillColor(TextInfosServer::name(), Color(255, 255, 255, 255));
    _sfmlHandler.setTextCharacterSize(TextInfosServer::name(), 35);
}

void MenuRight::initializeServerName() {
    _sfmlHandler.createText(TextServerName::name());
    _sfmlHandler.setTextString(TextServerName::name(), "");
    _sfmlHandler.setTextFillColor(TextServerName::name(), Color(255, 255, 255, 255));
    _sfmlHandler.setTextCharacterSize(TextServerName::name(), 30);
}

void MenuRight::validAsset(std::string const &name, std::string const &path, Vector2D<unsigned int> const &postion,
                           Vector2D<unsigned int> const &size) {
    std::ifstream infile(path);

    if (!infile.good())
        throw ErrorsMenuRight(std::cerr, "This file '" + path + "' does not exist");
    else {
        _sfmlHandler.createTextureFromFile(name, path, size.x, size.y);
        _sfmlHandler.createSprite(name, postion, size);
        infile.clear();
    }
}

void MenuRight::validButton(Vector2D<std::string> const &names, Vector2D<std::string> const &paths,
                            Vector2D<unsigned int> const &position, Vector2D<unsigned int> const &size) {
    std::ifstream infileFirst(paths.x);
    std::ifstream infileSecond(paths.y);

    if (!infileFirst.good())
        throw ErrorsMenuRight(std::cerr, "This file '" + paths.x + "' does not exist");
    else if (!infileSecond.good())
        throw ErrorsMenuRight(std::cerr, "This file '" + paths.y + "' does not exist");
    else {
        createButton(names, paths, position, size);
        infileFirst.clear();
        infileSecond.clear();
    }
}

void MenuRight::createButton(Vector2D<std::string> const &names, Vector2D<std::string> const &paths,
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

void MenuRight::setButtonInstance(std::string const &name, InstanceStatus const &status) {
    if (_buttons.find(name) != _buttons.end())
        _buttons[name].setInstance(status);
    else
        throw ErrorsMenuRight(std::cerr, "Button '" + name + "' not found");
}


void MenuRight::draw() {
    _sfmlHandler.drawSprite(MenuRightModel::name());
    _sfmlHandler.drawSprite(ExitGameRight::name());
    _sfmlHandler.drawSprite(TextServerName::name());
    _sfmlHandler.drawSprite(ButtonPublicRight::name());
    _sfmlHandler.drawSprite(ButtonPrivateRight::name());
    _sfmlHandler.drawSprite(ButtonSettingsRight::name());
    _sfmlHandler.drawSprite(ButtonCloseRight::name());
    _sfmlHandler.drawText(TextInfosServer::name(),
                          Vector2D<unsigned int>(TextInfosServer::topX, TextInfosServer::topY),
                          Vector2D<unsigned int>(TextInfosServer::sizeX, TextInfosServer::sizeY));
    if (_serverName.empty()) {
        _sfmlHandler.setTextFillColor(TextServerName::name(), Color(255, 255, 255, 255));
        _sfmlHandler.drawSprite(TextServerName::name());
    } else {
        _sfmlHandler.setTextFillColor(TextServerName::name(), Color(4, 16, 28, 255));
        _sfmlHandler.drawSprite(TextServerName::nameFocus());
    }
    _sfmlHandler.drawText(TextServerName::name(),
                          Vector2D<unsigned int>(TextServerName::topX, TextServerName::topY),
                          Vector2D<unsigned int>(TextServerName::sizeX, TextServerName::sizeY));
}

InstanceStatus MenuRight::manageEvent(enum Event const &event) {
    switch (event) {
        case E_MOUSE_PRESSED:
            return buttonPressed(_sfmlHandler.getMousePressedPosition());
        case E_MOUSE_RELEASED:
            return buttonReleased(_sfmlHandler.getMousePressedPosition());
        case E_TEXT_ENTERED:
            _sfmlHandler.setTextString(TextInfosServer::name(), INFOS_SERVER());
            _sfmlHandler.setTextFillColor(TextInfosServer::name(), Color(255, 255, 255, 255));
            return textEntered(_sfmlHandler.getTextEntered());
        default:
            break;
    }
    return UNDEFINED_INSTANCE;
}

InstanceStatus MenuRight::buttonPressed(Vector2D<int> const &position) {
    for (auto &_button : _buttons) {
        if (_button.second.isSelected(position)) {
            if (_button.second.getName() != ButtonPrivateRight::name() &&
                _button.second.getName() != ButtonPublicRight::name())
                _sfmlHandler.drawSprite(_button.second.getNameFocus());
            else if (!_serverName.empty())
                _sfmlHandler.drawSprite(_button.second.getNameFocus());
            return UNDEFINED_INSTANCE;
        }
    }
    return UNDEFINED_INSTANCE;
}

InstanceStatus MenuRight::buttonReleased(Vector2D<int> const &position) {
    _sfmlHandler.setMousePosition(Vector2D<int>(-1, -1));

    for (auto &_button : _buttons) {
        if (_button.second.isSelected(position)) {
            if (!_serverName.empty() && (_button.second.getName() == ButtonPrivateRight::name() ||
                                         _button.second.getName() == ButtonPublicRight::name()))
                return sendCreateInstance(_button.second.getName(), _button.second.getInstance());
            else if (_button.second.getName() != ExitGameRight::name() &&
                       _button.second.getName() != ButtonPrivateRight::name() &&
                       _button.second.getName() != ButtonPublicRight::name())
                return optionsMenu(_button.second.getName());
            else if (_button.second.getName() == ExitGameRight::name()) {
                sendLeaveServer();
                return EXIT_INSTANCE;
            }
        }
    }
    return UNDEFINED_INSTANCE;
}

InstanceStatus MenuRight::textEntered(std::string const &text) {
    std::string temp = text;

    if (text == "\b" && !_serverName.empty()) {
        _serverName.erase(_serverName.size() - 1, 1);
        _sfmlHandler.setTextString(TextServerName::name(), _serverName);
    } else if ((_serverName + temp).size() < 24 && (text != "\b") && (text != ":")) {
        std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        _serverName.append(temp);
        _sfmlHandler.setTextString(TextServerName::name(), _serverName);
    }
    return UNDEFINED_INSTANCE;
}

InstanceStatus MenuRight::optionsMenu(std::string const &key) {
    if (key != ButtonCloseRight::name()) {
        _sfmlHandler.playMusic(CONFIRM_SOUND());
    } else {
        _serverName.clear();
        _sfmlHandler.setTextString(TextServerName::name(), "");
        _sfmlHandler.playMusic(RETURN_SOUND());
    }
    return _buttons[key].getInstance();
}

InstanceStatus MenuRight::returnToLogin() {
    _server.decoClient();
    _userName.clear();
    _serverName.clear();
    return LOGIN_INSTANCE;
}

InstanceStatus MenuRight::sendCreateInstance(std::string const &name, InstanceStatus const &status) {
    std::string temp = "CREATE_INSTANCE;" + _userName + ";" + _serverName + ";";

    if (name == ButtonPublicRight::name())
        temp += "1";
    else
        temp += "0";
    if (!_server.send(temp))
        return returnToLogin();

    auto vectorCmd = _server.receive();

    if (!vectorCmd.empty() && vectorCmd.front().get()->commandType == DISCONNECT_SERVER)
        return returnToLogin();

    if (!vectorCmd.empty() && vectorCmd.front().get()->commandType == CREATE_INSTANCE_RESPONSE) {
        auto cmd = static_cast<CreateInstanceResponseCommand *>(&(*vectorCmd.front()));

        if (cmd->port == "-1") {
            _sfmlHandler.setTextString(TextInfosServer::name(), ERROR_SERVER());
            _sfmlHandler.setTextFillColor(TextInfosServer::name(), Color(255, 0, 0, 255));
            return UNDEFINED_INSTANCE;
        }
        _lobbyTCP.initialisation(IP_ADDRESS(), cmd->port + "0");
        _lobbyTCP.send(_userName);
        _lobbyTCP.receive();
        _lobbyUDP.initialisation(IP_ADDRESS(), cmd->port + "1");
    }
    _sfmlHandler.playMusic(CONFIRM_SOUND());
    _sfmlHandler.setTextString(TextServerName::name(), "");
    return status;
}

void MenuRight::sendLeaveServer() {
    _server.send("LEAVE_SERVER;" + _userName);
    _server.decoClient();
    _userName.clear();
    _serverName.clear();
}