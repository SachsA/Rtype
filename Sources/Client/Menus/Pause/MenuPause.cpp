/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include "MenuPause.hpp"
#include "ErrorsMenuPause.hpp"
#include "ButtonsMenuPause.hpp"
#include "ModelMenuPause.hpp"
#include "../../Constants/Sounds.hpp"

MenuPause::MenuPause(SFMLHandler const &sfmlHandler, std::string &userName, std::string &serverName,
        CommunicationTCPClient &server)
        : AMenu(sfmlHandler, userName, serverName), _server(server) {
    initializeAssets();
    initializeButtons();
}

InstanceStatus MenuPause::launch(enum Event const &event, InstanceStatus const &last) {
    draw();
    return manageEvent(event);
}

void MenuPause::initializeAssets() {
    validAsset(MenuPauseModel::name(), MenuPauseModel::path(),
               Vector2D<unsigned int>(MenuPauseModel::topX, MenuPauseModel::topY),
               Vector2D<unsigned int>(MenuPauseModel::sizeX, MenuPauseModel::sizeY));
}

void MenuPause::initializeButtons() {

    validButton(Vector2D<std::string>(ButtonResumePause::name(), ButtonResumePause::nameFocus()),
                Vector2D<std::string>(ButtonResumePause::path(), ButtonResumePause::pathFocus()),
                Vector2D<unsigned int>(ButtonResumePause::topX, ButtonResumePause::topY),
                Vector2D<unsigned int>(ButtonResumePause::sizeX, ButtonResumePause::sizeY));
    setButtonInstance(ButtonResumePause::name(), UNDEFINED_INSTANCE);
    validButton(Vector2D<std::string>(ButtonLeavePause::name(), ButtonLeavePause::nameFocus()),
                Vector2D<std::string>(ButtonLeavePause::path(), ButtonLeavePause::pathFocus()),
                Vector2D<unsigned int>(ButtonLeavePause::topX, ButtonLeavePause::topY),
                Vector2D<unsigned int>(ButtonLeavePause::sizeX, ButtonLeavePause::sizeY));
    setButtonInstance(ButtonLeavePause::name(), UNDEFINED_INSTANCE);
    validButton(Vector2D<std::string>(ButtonSettingsPause::name(), ButtonSettingsPause::nameFocus()),
                Vector2D<std::string>(ButtonSettingsPause::path(), ButtonSettingsPause::pathFocus()),
                Vector2D<unsigned int>(ButtonSettingsPause::topX, ButtonSettingsPause::topY),
                Vector2D<unsigned int>(ButtonSettingsPause::sizeX, ButtonSettingsPause::sizeY));
    setButtonInstance(ButtonSettingsPause::name(), SETTINGS_INSTANCE);
}

void MenuPause::validAsset(std::string const &name, std::string const &path, Vector2D<unsigned int> const &postion,
                           Vector2D<unsigned int> const &size) {
    std::ifstream infile(path);

    if (!infile.good())
        throw ErrorsMenuPause(std::cerr, "This file '" + path + "' does not exist");
    else {
        _sfmlHandler.createTextureFromFile(name, path, size.x, size.y);
        _sfmlHandler.createSprite(name, postion, size);
        infile.clear();
    }
}

void MenuPause::validButton(Vector2D<std::string> const &names, Vector2D<std::string> const &paths,
                            Vector2D<unsigned int> const &position, Vector2D<unsigned int> const &size) {
    std::ifstream infileFirst(paths.x);
    std::ifstream infileSecond(paths.y);

    if (!infileFirst.good())
        throw ErrorsMenuPause(std::cerr, "This file '" + paths.x + "' does not exist");
    else if (!infileSecond.good())
        throw ErrorsMenuPause(std::cerr, "This file '" + paths.y + "' does not exist");
    else {
        createButton(names, paths, position, size);
        infileFirst.clear();
        infileSecond.clear();
    }
}

void MenuPause::createButton(Vector2D<std::string> const &names, Vector2D<std::string> const &paths,
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

void MenuPause::setButtonInstance(std::string const &name, InstanceStatus const &status) {
    if (_buttons.find(name) != _buttons.end())
        _buttons[name].setInstance(status);
    else
        throw ErrorsMenuPause(std::cerr, "Button '" + name + "' not found");
}

void MenuPause::draw() {
    _sfmlHandler.drawSprite(MenuPauseModel::name());
    _sfmlHandler.drawSprite(ButtonResumePause::name());
    _sfmlHandler.drawSprite(ButtonLeavePause::name());
    _sfmlHandler.drawSprite(ButtonSettingsPause::name());
}

InstanceStatus MenuPause::manageEvent(enum Event const &event) {
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

InstanceStatus MenuPause::buttonPressed(Vector2D<int> const &position) {
    for (auto &_button : _buttons) {
        if (_button.second.isSelected(position)) {
            _sfmlHandler.drawSprite(_button.second.getNameFocus());
            return UNDEFINED_INSTANCE;
        }
    }
    return UNDEFINED_INSTANCE;
}

InstanceStatus MenuPause::buttonReleased(Vector2D<int> const &position) {
    _sfmlHandler.setMousePosition(Vector2D<int>(-1, -1));

    for (auto &_button : _buttons) {
        if (_button.second.isSelected(position))
            _sfmlHandler.playMusic(CONFIRM_SOUND());
            return _button.second.getInstance();
    }
    return UNDEFINED_INSTANCE;;
}