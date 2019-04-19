/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include <fstream>
#include "SlotYellow.hpp"
#include "ErrorsSlotYellow.hpp"

SlotYellow::SlotYellow(SFMLHandler const &sfmlHandler) : ASlot(sfmlHandler) {
    _state = 2;
    createButtonReady();
    createButtonPlus();
    createButtonCancel();
    createSlotUsername();
    createShipSection();
}

void SlotYellow::createButtonReady() {

    static const std::string name = "BUTTON_READY_YELLOW";
    static const std::string nameFocus = "BUTTON_READY_YELLOW_FOCUS";
    static const std::string nameActivated = "BUTTON_READY_YELLOW_ACTIVATED";
    static const std::string path = "../Ressources/Menus/Assets/button_ready.png";
    static const std::string pathFocus = "../Ressources/Menus/Assets/button_ready_focus.png";
    static const std::string pathActivated = "../Ressources/Menus/Assets/button_ready_yellow.png";

    validButton(Vector2D<std::string>(path, pathFocus),
                Vector2D<unsigned int>(960, 582),
                Vector2D<unsigned int>(356, 70));

    _ready = Button(Vector2D<std::string>(name, nameFocus),
                    Vector2D<unsigned int>(960, 582),
                    Vector2D<unsigned int>(356, 70));

    _ready.setPaths(Vector2D<std::string>(path, pathFocus));
    _ready.setInstance(UNDEFINED_INSTANCE);

    _sfmlHandler.createTextureFromFile(name, path,
                                       356, 70);

    _sfmlHandler.createSprite(name,
                              Vector2D<unsigned int>(960, 582),
                              Vector2D<unsigned int>(356, 70));

    _sfmlHandler.createTextureFromFile(nameFocus, pathFocus,
                                       356, 70);

    _sfmlHandler.createSprite(nameFocus,
                              Vector2D<unsigned int>(960, 582),
                              Vector2D<unsigned int>(356, 70));

    validAsset(pathActivated);

    _ready.setActivated(nameActivated, pathActivated);

    _sfmlHandler.createTextureFromFile(nameActivated, pathActivated,
                                       356, 70);

    _sfmlHandler.createSprite(nameActivated,
                              Vector2D<unsigned int>(960, 582),
                              Vector2D<unsigned int>(356, 70));
}

void SlotYellow::createButtonPlus() {

    static const std::string name = "BUTTON_PLUS_YELLOW";
    static const std::string nameFocus = "BUTTON_PLUS_YELLOW_FOCUS";
    static const std::string path = "../Ressources/Menus/Assets/button_plus.png";
    static const std::string pathFocus = "../Ressources/Menus/Assets/button_plus_yellow_focus.png";

    validButton(Vector2D<std::string>(path, pathFocus),
                Vector2D<unsigned int>(1113, 358),
                Vector2D<unsigned int>(91, 91));

    _plus = Button(Vector2D<std::string>(name, nameFocus),
                   Vector2D<unsigned int>(1113, 358),
                   Vector2D<unsigned int>(91, 91));

    _plus.setPaths(Vector2D<std::string>(path, pathFocus));
    _plus.setInstance(UNDEFINED_INSTANCE);

    _sfmlHandler.createTextureFromFile(name, path, 91, 91);

    _sfmlHandler.createSprite(name,
                              Vector2D<unsigned int>(1113, 358),
                              Vector2D<unsigned int>(91, 91));

    _sfmlHandler.createTextureFromFile(nameFocus, pathFocus, 91, 91);

    _sfmlHandler.createSprite(nameFocus,
                              Vector2D<unsigned int>(1113, 358),
                              Vector2D<unsigned int>(91, 91));
}

void SlotYellow::createButtonCancel() {

    static const std::string name = "CLOSE_SECTION_YELLOW";
    static const std::string nameFocus = "CLOSE_SECTION_YELLOW_FOCUS";
    static const std::string path = "../Ressources/Menus/Assets/button_close_ship_yellow.png";
    static const std::string pathFocus = "../Ressources/Menus/Assets/button_close_ship_yellow_focus.png";

    validButton(Vector2D<std::string>(path, pathFocus),
                Vector2D<unsigned int>(1304, 266),
                Vector2D<unsigned int>(36, 36));

    _cancel = Button(Vector2D<std::string>(name, nameFocus),
                     Vector2D<unsigned int>(1304, 266),
                     Vector2D<unsigned int>(36, 36));

    _cancel.setPaths(Vector2D<std::string>(path, pathFocus));
    _cancel.setInstance(UNDEFINED_INSTANCE);

    _sfmlHandler.createTextureFromFile(name, path, 36, 36);

    _sfmlHandler.createSprite(name,
                              Vector2D<unsigned int>(1304, 266),
                              Vector2D<unsigned int>(36, 36));

    _sfmlHandler.createTextureFromFile(nameFocus, pathFocus, 36, 36);

    _sfmlHandler.createSprite(nameFocus,
                              Vector2D<unsigned int>(1304, 266),
                              Vector2D<unsigned int>(36, 36));
}

void SlotYellow::createSlotUsername() {

    _playerText = "USERNAME_YELLOW";
    _playerPos = Vector2D<unsigned int>(1378, 254);
    _playerSize = Vector2D<unsigned int>(319, 56);

    _sfmlHandler.createText(_playerText);
    _sfmlHandler.setTextFillColor(_playerText, Color(255, 255, 255, 255));
    _sfmlHandler.setTextCharacterSize(_playerText, 30);
}

void SlotYellow::createShipSection() {

    static const std::string name = "SHIP_SECTION_YELLOW";
    static const std::string path = "../Ressources/Ships/Assets/ship_destroyer_yellow_model.png";

    validAsset(path);
    _ship = name;
    _sfmlHandler.createTextureFromFile(name, path, 328, 212);
    _sfmlHandler.createSprite(name, Vector2D<unsigned int>(999, 316), Vector2D<unsigned int>(328, 212));
}

void SlotYellow::validButton(Vector2D<std::string> const &paths, Vector2D<unsigned int> const &position,
                             Vector2D<unsigned int> const &size) {

    std::ifstream infileFirst(paths.x);
    std::ifstream infileSecond(paths.y);

    if (!infileFirst.good())
        throw ErrorsSlotYellow(std::cerr, "This file '" + paths.x + "' does not exist");
    else if (!infileSecond.good())
        throw ErrorsSlotYellow(std::cerr, "This file '" + paths.y + "' does not exist");
    else {
        infileFirst.clear();
        infileSecond.clear();
    }
}

void SlotYellow::validAsset(std::string const &path) {

    std::ifstream infile(path);

    if (!infile.good())
        throw ErrorsSlotYellow(std::cerr, "This file '" + path + "' does not exist");
    else
        infile.clear();
}