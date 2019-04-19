/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include "MenuSettings.hpp"
#include "ErrorsMenuSettings.hpp"
#include "ButtonsMenuSettings.hpp"
#include "ModelMenuSettings.hpp"
#include "../../Constants/Sounds.hpp"

MenuSettings::MenuSettings(SFMLHandler const &sfmlHandler, std::string &userName, std::string &serverName, CommunicationTCPClient &server)
        : AMenu(sfmlHandler, userName, serverName), _server(server) {
    initializeAssets();
    initializeButtons();
}

InstanceStatus MenuSettings::launch(enum Event const &event, InstanceStatus const &last) {
    draw();
    return manageEvent(event);
}

void MenuSettings::initializeAssets() {

    validAsset(MenuSettingsModel::name(), MenuSettingsModel::path(),
               Vector2D<unsigned int>(MenuSettingsModel::topX, MenuSettingsModel::topY),
               Vector2D<unsigned int>(MenuSettingsModel::sizeX, MenuSettingsModel::sizeY));

    initializeSoundIcon();
}

void MenuSettings::initializeButtons() {

    initializeSoundUp();
    initializeSoundDown();

    validButton(Vector2D<std::string>(ButtonCloseSettings::name(), ButtonCloseSettings::nameFocus()),
                Vector2D<std::string>(ButtonCloseSettings::path(), ButtonCloseSettings::pathFocus()),
                Vector2D<unsigned int>(ButtonCloseSettings::topX, ButtonCloseSettings::topY),
                Vector2D<unsigned int>(ButtonCloseSettings::sizeX, ButtonCloseSettings::sizeY));
    setButtonInstance(ButtonCloseSettings::name(), PREVIOUS_INSTANCE);

    validButton(Vector2D<std::string>(ExitGameSettings::name(), ExitGameSettings::nameFocus()),
                Vector2D<std::string>(ExitGameSettings::path(), ExitGameSettings::pathFocus()),
                Vector2D<unsigned int>(ExitGameSettings::topX, ExitGameSettings::topY),
                Vector2D<unsigned int>(ExitGameSettings::sizeX, ExitGameSettings::sizeY));
    setButtonInstance(ExitGameSettings::name(), EXIT_INSTANCE);
}

void MenuSettings::initializeSoundIcon() {

    validAsset(SoundIconMusic::name(), SoundIconMusic::path(),
               Vector2D<unsigned int>(SoundIconMusic::topX, SoundIconMusic::topY),
               Vector2D<unsigned int>(SoundIconMusic::sizeX, SoundIconMusic::sizeY));

    validAsset(SoundIconMusic::nameFocus(), SoundIconMusic::pathFocus(),
               Vector2D<unsigned int>(SoundIconMusic::topX, SoundIconMusic::topY),
               Vector2D<unsigned int>(SoundIconMusic::sizeX, SoundIconMusic::sizeY));

    setTextsVolume(TextVolumeMusic::name(), MUSIC_GAME());

    validAsset(SoundIconMenus::name(), SoundIconMenus::path(),
               Vector2D<unsigned int>(SoundIconMenus::topX, SoundIconMenus::topY),
               Vector2D<unsigned int>(SoundIconMenus::sizeX, SoundIconMenus::sizeY));

    validAsset(SoundIconMenus::nameFocus(), SoundIconMenus::pathFocus(),
               Vector2D<unsigned int>(SoundIconMenus::topX, SoundIconMenus::topY),
               Vector2D<unsigned int>(SoundIconMenus::sizeX, SoundIconMenus::sizeY));

    setTextsVolume(TextVolumeMenus::name(), CONFIRM_SOUND());

    validAsset(SoundIconGame::name(), SoundIconGame::path(),
               Vector2D<unsigned int>(SoundIconGame::topX, SoundIconGame::topY),
               Vector2D<unsigned int>(SoundIconGame::sizeX, SoundIconGame::sizeY));

    validAsset(SoundIconGame::nameFocus(), SoundIconGame::pathFocus(),
               Vector2D<unsigned int>(SoundIconGame::topX, SoundIconGame::topY),
               Vector2D<unsigned int>(SoundIconGame::sizeX, SoundIconGame::sizeY));

    setTextsVolume(TextVolumeGame::name(), POWER_UP_SOUND());
}

void MenuSettings::initializeSoundUp() {

    validButton(Vector2D<std::string>(ButtonUpMusic::name(), ButtonUpMusic::nameFocus()),
                Vector2D<std::string>(ButtonUpMusic::path(), ButtonUpMusic::pathFocus()),
                Vector2D<unsigned int>(ButtonUpMusic::topX, ButtonUpMusic::topY),
                Vector2D<unsigned int>(ButtonUpMusic::sizeX, ButtonUpMusic::sizeY));
    setButtonInstance(ButtonUpMusic::name(), UNDEFINED_INSTANCE);

    validButton(Vector2D<std::string>(ButtonUpMenus::name(), ButtonUpMenus::nameFocus()),
                Vector2D<std::string>(ButtonUpMenus::path(), ButtonUpMenus::pathFocus()),
                Vector2D<unsigned int>(ButtonUpMenus::topX, ButtonUpMenus::topY),
                Vector2D<unsigned int>(ButtonUpMenus::sizeX, ButtonUpMenus::sizeY));
    setButtonInstance(ButtonUpMenus::name(), UNDEFINED_INSTANCE);

    validButton(Vector2D<std::string>(ButtonUpGame::name(), ButtonUpGame::nameFocus()),
                Vector2D<std::string>(ButtonUpGame::path(), ButtonUpGame::pathFocus()),
                Vector2D<unsigned int>(ButtonUpGame::topX, ButtonUpGame::topY),
                Vector2D<unsigned int>(ButtonUpGame::sizeX, ButtonUpGame::sizeY));
    setButtonInstance(ButtonUpGame::name(), UNDEFINED_INSTANCE);
}

void MenuSettings::initializeSoundDown() {

    validButton(Vector2D<std::string>(ButtonDownMusic::name(), ButtonDownMusic::nameFocus()),
                Vector2D<std::string>(ButtonDownMusic::path(), ButtonDownMusic::pathFocus()),
                Vector2D<unsigned int>(ButtonDownMusic::topX, ButtonDownMusic::topY),
                Vector2D<unsigned int>(ButtonDownMusic::sizeX, ButtonDownMusic::sizeY));
    setButtonInstance(ButtonDownMusic::name(), UNDEFINED_INSTANCE);

    validButton(Vector2D<std::string>(ButtonDownMenus::name(), ButtonDownMenus::nameFocus()),
                Vector2D<std::string>(ButtonDownMenus::path(), ButtonDownMenus::pathFocus()),
                Vector2D<unsigned int>(ButtonDownMenus::topX, ButtonDownMenus::topY),
                Vector2D<unsigned int>(ButtonDownMenus::sizeX, ButtonDownMenus::sizeY));
    setButtonInstance(ButtonDownMenus::name(), UNDEFINED_INSTANCE);

    validButton(Vector2D<std::string>(ButtonDownGame::name(), ButtonDownGame::nameFocus()),
                Vector2D<std::string>(ButtonDownGame::path(), ButtonDownGame::pathFocus()),
                Vector2D<unsigned int>(ButtonDownGame::topX, ButtonDownGame::topY),
                Vector2D<unsigned int>(ButtonDownGame::sizeX, ButtonDownGame::sizeY));
    setButtonInstance(ButtonDownGame::name(), UNDEFINED_INSTANCE);
}

void MenuSettings::setTextsVolume(std::string const &name, std::string const &volume) {
    std::ostringstream ss;

    ss << _sfmlHandler.getMusicVolume(volume);
    _sfmlHandler.createText(name);
    _sfmlHandler.setTextString(name, ss.str());
    _sfmlHandler.setTextFillColor(name, Color(255, 255, 255, 255));
    _sfmlHandler.setTextCharacterSize(name, 35);
}

void MenuSettings::validAsset(std::string const &name, std::string const &path, Vector2D<unsigned int> const &postion,
                              Vector2D<unsigned int> const &size) {
    std::ifstream infile(path);

    if (!infile.good())
        throw ErrorsMenuSettings(std::cerr, "This file '" + path + "' does not exist");
    else {
        _sfmlHandler.createTextureFromFile(name, path, size.x, size.y);
        _sfmlHandler.createSprite(name, postion, size);
        infile.clear();
    }
}

void MenuSettings::validButton(Vector2D<std::string> const &names, Vector2D<std::string> const &paths,
                               Vector2D<unsigned int> const &position, Vector2D<unsigned int> const &size) {
    std::ifstream infileFirst(paths.x);
    std::ifstream infileSecond(paths.y);

    if (!infileFirst.good())
        throw ErrorsMenuSettings(std::cerr, "This file '" + paths.x + "' does not exist");
    else if (!infileSecond.good())
        throw ErrorsMenuSettings(std::cerr, "This file '" + paths.y + "' does not exist");
    else {
        createButton(names, paths, position, size);
        infileFirst.clear();
        infileSecond.clear();
    }
}

void MenuSettings::createButton(Vector2D<std::string> const &names, Vector2D<std::string> const &paths,
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

void MenuSettings::setButtonInstance(std::string const &name, InstanceStatus const &status) {
    if (_buttons.find(name) != _buttons.end())
        _buttons[name].setInstance(status);
    else
        throw ErrorsMenuSettings(std::cerr, "Button '" + name + "' not found");
}

void MenuSettings::draw() {
    _sfmlHandler.drawSprite(MenuSettingsModel::name());
    _sfmlHandler.drawSprite(ButtonCloseSettings::name());
    _sfmlHandler.drawSprite(ExitGameSettings::name());
    _sfmlHandler.drawText(TextVolumeMusic::name(),
                          Vector2D<unsigned int>(TextVolumeMusic::topX, TextVolumeMusic::topY),
                          Vector2D<unsigned int>(TextVolumeMusic::sizeX, TextVolumeMusic::sizeY));
    _sfmlHandler.drawText(TextVolumeMenus::name(),
                          Vector2D<unsigned int>(TextVolumeMenus::topX, TextVolumeMenus::topY),
                          Vector2D<unsigned int>(TextVolumeMenus::sizeX, TextVolumeMenus::sizeY));
    _sfmlHandler.drawText(TextVolumeGame::name(),
                          Vector2D<unsigned int>(TextVolumeGame::topX, TextVolumeGame::topY),
                          Vector2D<unsigned int>(TextVolumeGame::sizeX, TextVolumeGame::sizeY));
    drawSoundUp();
    drawSoundDown();
    drawSoundIcon();
}

void MenuSettings::drawSoundUp() {
    _sfmlHandler.drawSprite(ButtonUpMusic::name());
    _sfmlHandler.drawSprite(ButtonUpMenus::name());
    _sfmlHandler.drawSprite(ButtonUpGame::name());
}

void MenuSettings::drawSoundDown() {
    _sfmlHandler.drawSprite(ButtonDownMusic::name());
    _sfmlHandler.drawSprite(ButtonDownMenus::name());
    _sfmlHandler.drawSprite(ButtonDownGame::name());
}

void MenuSettings::drawSoundIcon() {
    _sfmlHandler.drawSprite(SoundIconMusic::name());
    _sfmlHandler.drawSprite(SoundIconMenus::name());
    _sfmlHandler.drawSprite(SoundIconGame::name());
}

InstanceStatus MenuSettings::manageEvent(enum Event const &event) {
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

InstanceStatus MenuSettings::buttonPressed(Vector2D<int> const &position) {
    for (auto &_button : _buttons) {
        if (_button.second.isSelected(position)) {
            _sfmlHandler.drawSprite(_button.second.getNameFocus());
            return UNDEFINED_INSTANCE;
        }
    }
    return UNDEFINED_INSTANCE;
}

InstanceStatus MenuSettings::buttonReleased(Vector2D<int> const &position) {
    _sfmlHandler.setMousePosition(Vector2D<int>(-1, -1));

    for (auto &_button : _buttons) {
        if (_button.second.isSelected(position)) {
            if (_button.second.getName() == ButtonCloseSettings::name())
                _sfmlHandler.playMusic(RETURN_SOUND());
            else if (_button.second.getName() == ExitGameSettings::name())
                sendLeaveServer();
            else {
                _sfmlHandler.playMusic(CLICK_SOUND());
                manageSounds(_button.second.getName());
            }
            return _button.second.getInstance();
        }
    }
    return UNDEFINED_INSTANCE;
}

void MenuSettings::manageSounds(std::string const &sounds) {
    std::string temp = sounds.substr(0, 11);

    if (temp == "BUTTON_DOWN")
        putSoundDown(sounds);
    else
        putSoundUp(sounds);
}

void MenuSettings::putSoundDown(std::string const &sounds) {
    float sound;
    std::ostringstream ss;

    if (sounds == ButtonDownMusic::name()) {

        sound = _sfmlHandler.getMusicVolume(MUSIC_MENU());
        (sound <= 10) ? _sfmlHandler.setMusicVolume(MUSIC_MENU(), 0)
                     : _sfmlHandler.setMusicVolume(MUSIC_MENU(), sound - 10);

        sound = _sfmlHandler.getMusicVolume(MUSIC_GAME());
        (sound <= 10) ? _sfmlHandler.setMusicVolume(MUSIC_GAME(), 0)
                          : _sfmlHandler.setMusicVolume(MUSIC_GAME(), sound - 10);

        ss << roundf(_sfmlHandler.getMusicVolume(MUSIC_GAME()));
        _sfmlHandler.setTextString(TextVolumeMusic::name(), ss.str());

    } else if (sounds == ButtonDownMenus::name()) {

        sound = _sfmlHandler.getMusicVolume(CONFIRM_SOUND());
        (sound <= 10) ? _sfmlHandler.setMusicVolume(CONFIRM_SOUND(), 0)
                     : _sfmlHandler.setMusicVolume(CONFIRM_SOUND(), sound - 10);

        sound = _sfmlHandler.getMusicVolume(CLICK_SOUND());
        (sound <= 10) ? _sfmlHandler.setMusicVolume(CLICK_SOUND(), 0)
                     : _sfmlHandler.setMusicVolume(CLICK_SOUND(), sound - 10);

        sound = _sfmlHandler.getMusicVolume(RETURN_SOUND());
        (sound <= 10) ? _sfmlHandler.setMusicVolume(RETURN_SOUND(), 0)
                     : _sfmlHandler.setMusicVolume(RETURN_SOUND(), sound - 10);

        ss << roundf(_sfmlHandler.getMusicVolume(CONFIRM_SOUND()));
        _sfmlHandler.setTextString(TextVolumeMenus::name(), ss.str());

    } else {
        sound = _sfmlHandler.getMusicVolume(POWER_UP_SOUND());
        (sound <= 10) ? _sfmlHandler.setMusicVolume(POWER_UP_SOUND(), 0)
                     : _sfmlHandler.setMusicVolume(POWER_UP_SOUND(), sound - 10);

        sound = _sfmlHandler.getMusicVolume(ENGINE_SOUND());
        (sound <= 10) ? _sfmlHandler.setMusicVolume(ENGINE_SOUND(), 0)
                     : _sfmlHandler.setMusicVolume(ENGINE_SOUND(), sound - 10);

        sound = _sfmlHandler.getMusicVolume(EXPLOSION_SOUND());
        (sound <= 10) ? _sfmlHandler.setMusicVolume(EXPLOSION_SOUND(), 0)
                     : _sfmlHandler.setMusicVolume(EXPLOSION_SOUND(), sound - 10);

        sound = _sfmlHandler.getMusicVolume(SHOT_ALLY_SOUND());
        (sound <= 10) ? _sfmlHandler.setMusicVolume(SHOT_ALLY_SOUND(), 0)
                     : _sfmlHandler.setMusicVolume(SHOT_ALLY_SOUND(), sound - 10);

        sound = _sfmlHandler.getMusicVolume(SHOT_ENEMY_SOUND());
        (sound <= 10) ? _sfmlHandler.setMusicVolume(SHOT_ENEMY_SOUND(), 0)
                     : _sfmlHandler.setMusicVolume(SHOT_ENEMY_SOUND(), sound - 10);

        ss << roundf(_sfmlHandler.getMusicVolume(POWER_UP_SOUND()));
        _sfmlHandler.setTextString(TextVolumeGame::name(), ss.str());
    }
}

void MenuSettings::putSoundUp(std::string const &sounds) {
    float sound;
    std::ostringstream ss;

    if (sounds == ButtonUpMusic::name()) {

        sound = _sfmlHandler.getMusicVolume(MUSIC_MENU());
        (sound >= 90) ? _sfmlHandler.setMusicVolume(MUSIC_MENU(), 100)
                     : _sfmlHandler.setMusicVolume(MUSIC_MENU(), sound + 10);

        sound = _sfmlHandler.getMusicVolume(MUSIC_GAME());
        (sound >= 90) ? _sfmlHandler.setMusicVolume(MUSIC_GAME(), 100)
                     : _sfmlHandler.setMusicVolume(MUSIC_GAME(), sound + 10);

        ss << roundf(_sfmlHandler.getMusicVolume(MUSIC_GAME()));
        _sfmlHandler.setTextString(TextVolumeMusic::name(), ss.str());

    } else if (sounds == ButtonUpMenus::name()) {

        sound = _sfmlHandler.getMusicVolume(CONFIRM_SOUND());
        (sound >= 90) ? _sfmlHandler.setMusicVolume(CONFIRM_SOUND(), 100)
                     : _sfmlHandler.setMusicVolume(CONFIRM_SOUND(), sound + 10);

        sound = _sfmlHandler.getMusicVolume(CLICK_SOUND());
        (sound >= 90) ? _sfmlHandler.setMusicVolume(CLICK_SOUND(), 100)
                     : _sfmlHandler.setMusicVolume(CLICK_SOUND(), sound + 10);

        sound = _sfmlHandler.getMusicVolume(RETURN_SOUND());
        (sound >= 90) ? _sfmlHandler.setMusicVolume(RETURN_SOUND(), 100)
                     : _sfmlHandler.setMusicVolume(RETURN_SOUND(), sound + 10);

        ss << roundf(_sfmlHandler.getMusicVolume(CONFIRM_SOUND()));
        _sfmlHandler.setTextString(TextVolumeMenus::name(), ss.str());

    } else {
        sound = _sfmlHandler.getMusicVolume(POWER_UP_SOUND());
        (sound >= 90) ? _sfmlHandler.setMusicVolume(POWER_UP_SOUND(), 100)
                     : _sfmlHandler.setMusicVolume(POWER_UP_SOUND(), sound + 10);

        sound = _sfmlHandler.getMusicVolume(ENGINE_SOUND());
        (sound >= 90) ? _sfmlHandler.setMusicVolume(ENGINE_SOUND(), 100)
                     : _sfmlHandler.setMusicVolume(ENGINE_SOUND(), sound + 10);

        sound = _sfmlHandler.getMusicVolume(EXPLOSION_SOUND());
        (sound >= 90) ? _sfmlHandler.setMusicVolume(EXPLOSION_SOUND(), 100)
                     : _sfmlHandler.setMusicVolume(EXPLOSION_SOUND(), sound + 10);

        sound = _sfmlHandler.getMusicVolume(SHOT_ALLY_SOUND());
        (sound >= 90) ? _sfmlHandler.setMusicVolume(SHOT_ALLY_SOUND(), 100)
                     : _sfmlHandler.setMusicVolume(SHOT_ALLY_SOUND(), sound + 10);

        sound = _sfmlHandler.getMusicVolume(SHOT_ENEMY_SOUND());
        (sound >= 90) ? _sfmlHandler.setMusicVolume(SHOT_ENEMY_SOUND(), 100)
                     : _sfmlHandler.setMusicVolume(SHOT_ENEMY_SOUND(), sound + 10);

        ss << roundf(_sfmlHandler.getMusicVolume(POWER_UP_SOUND()));
        _sfmlHandler.setTextString(TextVolumeGame::name(), ss.str());
    }
}

void MenuSettings::sendLeaveServer() {
    _server.send("LEAVE_SERVER;" + _userName);
    _server.decoClient();
    _userName.clear();
    _serverName.clear();
}