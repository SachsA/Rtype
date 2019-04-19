/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include "MenuRooms.hpp"
#include "ErrorsMenuRooms.hpp"
#include "ButtonsMenuRooms.hpp"
#include "ModelMenuRooms.hpp"
#include "../../Constants/Sounds.hpp"

MenuRooms::MenuRooms(SFMLHandler const &sfmlHandler, std::string &userName, std::string &serverName,
                     CommunicationTCPClient &server, std::vector<std::string> &listServer,
                     CommunicationTCPClient &lobbyTCP, CommunicationUDPClient &lobbyUDP)
        : AMenu(sfmlHandler, userName, serverName), _server(server), _listServer(listServer),
        _lobbyTCP(lobbyTCP), _lobbyUDP(lobbyUDP) {
    initializeAssets();
    initializeButtons();
}

InstanceStatus MenuRooms::launch(enum Event const &event, InstanceStatus const &last) {
    draw();
    return manageEvent(event);
}

void MenuRooms::initializeAssets() {
    validAsset(MenuRoomsModel::name(), MenuRoomsModel::path(),
               Vector2D<unsigned int>(MenuRoomsModel::topX, MenuRoomsModel::topY),
               Vector2D<unsigned int>(MenuRoomsModel::sizeX, MenuRoomsModel::sizeY));
}

void MenuRooms::initializeButtons() {

    validButton(Vector2D<std::string>(ItemServerOne::name(), ItemServerOne::nameFocus()),
                Vector2D<std::string>(ItemServerOne::path(), ItemServerOne::pathFocus()),
                Vector2D<unsigned int>(ItemServerOne::topX, ItemServerOne::topY),
                Vector2D<unsigned int>(ItemServerOne::sizeX, ItemServerOne::sizeY));
    setButtonInstance(ItemServerOne::name(), LOBBY_INSTANCE);

    validButton(Vector2D<std::string>(ItemServerTwo::name(), ItemServerTwo::nameFocus()),
                Vector2D<std::string>(ItemServerTwo::path(), ItemServerTwo::pathFocus()),
                Vector2D<unsigned int>(ItemServerTwo::topX, ItemServerTwo::topY),
                Vector2D<unsigned int>(ItemServerTwo::sizeX, ItemServerTwo::sizeY));
    setButtonInstance(ItemServerTwo::name(), LOBBY_INSTANCE);

    validButton(Vector2D<std::string>(ItemServerThree::name(), ItemServerThree::nameFocus()),
                Vector2D<std::string>(ItemServerThree::path(), ItemServerThree::pathFocus()),
                Vector2D<unsigned int>(ItemServerThree::topX, ItemServerThree::topY),
                Vector2D<unsigned int>(ItemServerThree::sizeX, ItemServerThree::sizeY));
    setButtonInstance(ItemServerThree::name(), LOBBY_INSTANCE);

    validButton(Vector2D<std::string>(ItemServerFour::name(), ItemServerFour::nameFocus()),
                Vector2D<std::string>(ItemServerFour::path(), ItemServerFour::pathFocus()),
                Vector2D<unsigned int>(ItemServerFour::topX, ItemServerFour::topY),
                Vector2D<unsigned int>(ItemServerFour::sizeX, ItemServerFour::sizeY));
    setButtonInstance(ItemServerFour::name(), LOBBY_INSTANCE);

    validButton(Vector2D<std::string>(ItemServerFive::name(), ItemServerFive::nameFocus()),
                Vector2D<std::string>(ItemServerFive::path(), ItemServerFive::pathFocus()),
                Vector2D<unsigned int>(ItemServerFive::topX, ItemServerFive::topY),
                Vector2D<unsigned int>(ItemServerFive::sizeX, ItemServerFive::sizeY));
    setButtonInstance(ItemServerFive::name(), LOBBY_INSTANCE);

    validButton(Vector2D<std::string>(ItemServerSix::name(), ItemServerSix::nameFocus()),
                Vector2D<std::string>(ItemServerSix::path(), ItemServerSix::pathFocus()),
                Vector2D<unsigned int>(ItemServerSix::topX, ItemServerSix::topY),
                Vector2D<unsigned int>(ItemServerSix::sizeX, ItemServerSix::sizeY));
    setButtonInstance(ItemServerSix::name(), LOBBY_INSTANCE);

    validButton(Vector2D<std::string>(ItemServerSeven::name(), ItemServerSeven::nameFocus()),
                Vector2D<std::string>(ItemServerSeven::path(), ItemServerSeven::pathFocus()),
                Vector2D<unsigned int>(ItemServerSeven::topX, ItemServerSeven::topY),
                Vector2D<unsigned int>(ItemServerSeven::sizeX, ItemServerSeven::sizeY));
    setButtonInstance(ItemServerSeven::name(), LOBBY_INSTANCE);

    validButton(Vector2D<std::string>(ItemServerHeight::name(), ItemServerHeight::nameFocus()),
                Vector2D<std::string>(ItemServerHeight::path(), ItemServerHeight::pathFocus()),
                Vector2D<unsigned int>(ItemServerHeight::topX, ItemServerHeight::topY),
                Vector2D<unsigned int>(ItemServerHeight::sizeX, ItemServerHeight::sizeY));
    setButtonInstance(ItemServerHeight::name(), LOBBY_INSTANCE);

    validButton(Vector2D<std::string>(ButtonCloseRooms::name(), ButtonCloseRooms::nameFocus()),
                Vector2D<std::string>(ButtonCloseRooms::path(), ButtonCloseRooms::pathFocus()),
                Vector2D<unsigned int>(ButtonCloseRooms::topX, ButtonCloseRooms::topY),
                Vector2D<unsigned int>(ButtonCloseRooms::sizeX, ButtonCloseRooms::sizeY));
    setButtonInstance(ButtonCloseRooms::name(), PRINCIPAL_INSTANCE);

    validButton(Vector2D<std::string>(ExitGameRooms::name(), ExitGameRooms::nameFocus()),
                Vector2D<std::string>(ExitGameRooms::path(), ExitGameRooms::pathFocus()),
                Vector2D<unsigned int>(ExitGameRooms::topX, ExitGameRooms::topY),
                Vector2D<unsigned int>(ExitGameRooms::sizeX, ExitGameRooms::sizeY));
    setButtonInstance(ExitGameRooms::name(), EXIT_INSTANCE);
}

void MenuRooms::setItemText(std::string const &name, int const &index) {

    if (index < _listServer.size()) {
        _sfmlHandler.createText(name);
        _sfmlHandler.setTextString(name, _listServer[index]);
        _sfmlHandler.setTextFillColor(name, Color(255, 255, 255, 255));
        _sfmlHandler.setTextCharacterSize(name, 30);
    }
}

void MenuRooms::validAsset(std::string const &name, std::string const &path, Vector2D<unsigned int> const &postion,
                           Vector2D<unsigned int> const &size) {
    std::ifstream infile(path);

    if (!infile.good())
        throw ErrorsMenuRooms(std::cerr, "This file '" + path + "' does not exist");
    else {
        _sfmlHandler.createTextureFromFile(name, path, size.x, size.y);
        _sfmlHandler.createSprite(name, postion, size);
        infile.clear();
    }
}

void MenuRooms::validButton(Vector2D<std::string> const &names, Vector2D<std::string> const &paths,
                            Vector2D<unsigned int> const &position, Vector2D<unsigned int> const &size) {
    std::ifstream infileFirst(paths.x);
    std::ifstream infileSecond(paths.y);

    if (!infileFirst.good())
        throw ErrorsMenuRooms(std::cerr, "This file '" + paths.x + "' does not exist");
    else if (!infileSecond.good())
        throw ErrorsMenuRooms(std::cerr, "This file '" + paths.y + "' does not exist");
    else {
        createButton(names, paths, position, size);
        infileFirst.clear();
        infileSecond.clear();
    }
}

void MenuRooms::createButton(Vector2D<std::string> const &names, Vector2D<std::string> const &paths,
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

void MenuRooms::setButtonInstance(std::string const &name, InstanceStatus const &status) {
    if (_buttons.find(name) != _buttons.end())
        _buttons[name].setInstance(status);
    else
        throw ErrorsMenuRooms(std::cerr, "Button '" + name + "' not found");
}

void MenuRooms::draw() {
    _sfmlHandler.drawSprite(MenuRoomsModel::name());
    _sfmlHandler.drawSprite(ButtonCloseRooms::name());
    _sfmlHandler.drawSprite(ExitGameRooms::name());

    drawItems(ItemServerOne::name(),
              Vector2D<unsigned int>(ItemServerOne::topX, ItemServerOne::topY),
              Vector2D<unsigned int>(ItemServerOne::sizeX, ItemServerOne::sizeY), 0);

    drawItems(ItemServerTwo::name(),
              Vector2D<unsigned int>(ItemServerTwo::topX, ItemServerTwo::topY),
              Vector2D<unsigned int>(ItemServerTwo::sizeX, ItemServerTwo::sizeY), 1);

    drawItems(ItemServerThree::name(),
              Vector2D<unsigned int>(ItemServerThree::topX, ItemServerThree::topY),
              Vector2D<unsigned int>(ItemServerThree::sizeX, ItemServerThree::sizeY), 2);

    drawItems(ItemServerFour::name(),
              Vector2D<unsigned int>(ItemServerFour::topX, ItemServerFour::topY),
              Vector2D<unsigned int>(ItemServerFour::sizeX, ItemServerFour::sizeY), 3);

    drawItems(ItemServerFive::name(),
              Vector2D<unsigned int>(ItemServerFive::topX, ItemServerFive::topY),
              Vector2D<unsigned int>(ItemServerFive::sizeX, ItemServerFive::sizeY), 4);

    drawItems(ItemServerSix::name(),
              Vector2D<unsigned int>(ItemServerSix::topX, ItemServerSix::topY),
              Vector2D<unsigned int>(ItemServerSix::sizeX, ItemServerSix::sizeY), 5);

    drawItems(ItemServerSeven::name(),
              Vector2D<unsigned int>(ItemServerSeven::topX, ItemServerSeven::topY),
              Vector2D<unsigned int>(ItemServerSeven::sizeX, ItemServerSeven::sizeY), 6);

    drawItems(ItemServerHeight::name(),
              Vector2D<unsigned int>(ItemServerHeight::topX, ItemServerHeight::topY),
              Vector2D<unsigned int>(ItemServerHeight::sizeX, ItemServerHeight::sizeY), 7);
}

void MenuRooms::drawItems(std::string const &name, Vector2D<unsigned int> const &position,
                          Vector2D<unsigned int> const &size, int const &index) {

    setItemText(name, index);
    if (!_sfmlHandler.getTextString(name).empty()) {
        _sfmlHandler.drawSprite(name);
        _sfmlHandler.drawText(name, position, size);
    }
}

InstanceStatus MenuRooms::manageEvent(enum Event const &event) {
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

InstanceStatus MenuRooms::buttonPressed(Vector2D<int> const &position) {
    for (auto &_button : _buttons) {
        if (_button.second.isSelected(position) && validItems(_button.second.getName())) {
            if (_button.second.getName() != ButtonCloseRooms::name()) {
                _sfmlHandler.drawSprite(_button.second.getNameFocus());
                _sfmlHandler.setTextFillColor(_button.second.getName(), Color(4, 16, 18, 255));
                _sfmlHandler.drawText(_button.second.getName(), _button.second.getPosition(), _button.second.getSize());
            } else
                _sfmlHandler.drawSprite(_button.second.getNameFocus());
            return UNDEFINED_INSTANCE;
        }
    }
    return UNDEFINED_INSTANCE;
}

InstanceStatus MenuRooms::buttonReleased(Vector2D<int> const &position) {
    _sfmlHandler.setMousePosition(Vector2D<int>(-1, -1));

    for (auto &_button : _buttons) {
        if (_button.second.isSelected(position) && validItems(_button.second.getName())) {
            if (_button.second.getName() != ButtonCloseRooms::name() && _button.second.getName() != ExitGameRooms::name()) {
                _sfmlHandler.setTextFillColor(_button.second.getName(), Color(255, 255, 255, 255));
                _sfmlHandler.drawText(_button.second.getName(), _button.second.getPosition(), _button.second.getSize());
                _sfmlHandler.playMusic(CONFIRM_SOUND());
				if (sendJoinInstance(_button.second.getName()) == LOGIN_INSTANCE)
					return LOGIN_INSTANCE;
			} else if (_button.second.getName() == ButtonCloseRooms::name())
				_sfmlHandler.playMusic(RETURN_SOUND());
            else
                return sendLeaveServer();
            _listServer.clear();
			resetItems();
            return _button.second.getInstance();
        }
    }
    return UNDEFINED_INSTANCE;
}

bool MenuRooms::validItems(std::string const &name) {
    return !(_sfmlHandler.getTextString(name).empty() && name != ButtonCloseRooms::name() && name != ExitGameRooms::name());
}

InstanceStatus MenuRooms::returnToLogin() {
	_server.decoClient();
	_userName.clear();
	_serverName.clear();
	_listServer.clear();
	resetItems();
	return LOGIN_INSTANCE;
}

InstanceStatus MenuRooms::sendJoinInstance(std::string const &server) {
    std::string temp = "JOIN_INSTANCE;" + _userName + ";" + _sfmlHandler.getTextString(server);

    if (!_server.send(temp))
		return returnToLogin();

    auto vectorCmd = _server.receive();
	if (!vectorCmd.empty() && vectorCmd.front().get()->commandType == DISCONNECT_SERVER)
		return returnToLogin();

    if (!vectorCmd.empty() && vectorCmd.front().get()->commandType == JOIN_INSTANCE_RESPONSE) {
        auto cmd = static_cast<JoinInstanceResponseCommand *>(&(*vectorCmd.front()));
        _lobbyTCP.initialisation(IP_ADDRESS(), cmd->serverPort + "0");
        _lobbyTCP.send(_userName);
        _lobbyTCP.receive();
        _lobbyUDP.initialisation(IP_ADDRESS(), cmd->serverPort + "1");
    }
	return UNDEFINED_INSTANCE;
}

void MenuRooms::resetItems() {
    _sfmlHandler.setTextString(ItemServerOne::name(), "");
    _sfmlHandler.setTextString(ItemServerTwo::name(), "");
    _sfmlHandler.setTextString(ItemServerThree::name(), "");
    _sfmlHandler.setTextString(ItemServerFour::name(), "");
    _sfmlHandler.setTextString(ItemServerFive::name(), "");
    _sfmlHandler.setTextString(ItemServerSix::name(), "");
    _sfmlHandler.setTextString(ItemServerSeven::name(), "");
    _sfmlHandler.setTextString(ItemServerHeight::name(), "");
}

InstanceStatus MenuRooms::sendLeaveServer() {

    if (!_server.send("LEAVE_SERVER;" + _userName))
        return returnToLogin();

    _listServer.clear();
    _userName.clear();
    _serverName.clear();
    resetItems();
    return EXIT_INSTANCE;
}