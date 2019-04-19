/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include "MenuLobby.hpp"
#include "ErrorsMenuLobby.hpp"
#include "ButtonsMenuLobby.hpp"
#include "ModelMenuLobby.hpp"
#include "../../Components/Slots/SlotBlue/SlotBlue.hpp"
#include "../../Constants/Sounds.hpp"
#include "../../Components/Slots/SlotGreen/SlotGreen.hpp"
#include "../../Components/Slots/SlotRed/SlotRed.hpp"
#include "../../Components/Slots/SlotYellow/SlotYellow.hpp"

MenuLobby::MenuLobby(SFMLHandler const &sfmlHandler, std::string &userName, std::string &serverName,
                     CommunicationTCPClient &server, std::vector<std::string> &listServer,
                     CommunicationTCPClient &lobbyTCP)
        : AMenu(sfmlHandler, userName, serverName), _server(server), _listServer(listServer), _lobbyTCP(lobbyTCP),
          _time(std::chrono::system_clock::now()) {
    initializeAssets();
    _slots.emplace(SlotState::SLOT_BLUE, std::make_unique<SlotBlue>(sfmlHandler));
    _slots.emplace(SlotState::SLOT_GREEN, std::make_unique<SlotGreen>(sfmlHandler));
    _slots.emplace(SlotState::SLOT_RED, std::make_unique<SlotRed>(sfmlHandler));
    _slots.emplace(SlotState::SLOT_YELLOW, std::make_unique<SlotYellow>(sfmlHandler));
}

bool MenuLobby::isUpdateTime(int fpms) {
    auto now = std::chrono::system_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(now - _time);
    bool ret = false;

    if (diff.count() > fpms) {
        while (_time < now - std::chrono::milliseconds(fpms)) {
            _time += std::chrono::milliseconds(fpms);
        }
        ret = true;
    }
    return ret;
}

InstanceStatus MenuLobby::launch(enum Event const &event, InstanceStatus const &last) {
    InstanceStatus temp = UNDEFINED_INSTANCE;

    if (isUpdateTime(60)) {
        temp = getSlotStatus();
        if (temp == LOGIN_INSTANCE || temp == GAME_INSTANCE)
            return temp;
    }
    draw();
    return manageEvent(event, last);
}

void MenuLobby::initializeAssets() {

    validAsset(MenuLobbyModel::name(), MenuLobbyModel::path(),
               Vector2D<unsigned int>(MenuLobbyModel::topX, MenuLobbyModel::topY),
               Vector2D<unsigned int>(MenuLobbyModel::sizeX, MenuLobbyModel::sizeY));

    validButton(Vector2D<std::string>(ButtonCloseLobby::name(), ButtonCloseLobby::nameFocus()),
                Vector2D<std::string>(ButtonCloseLobby::path(), ButtonCloseLobby::pathFocus()),
                Vector2D<unsigned int>(ButtonCloseLobby::topX, ButtonCloseLobby::topY),
                Vector2D<unsigned int>(ButtonCloseLobby::sizeX, ButtonCloseLobby::sizeY));
    setButtonInstance(ButtonCloseLobby::name(), PREVIOUS_INSTANCE);

    validButton(Vector2D<std::string>(ExitGameLobby::name(), ExitGameLobby::nameFocus()),
                Vector2D<std::string>(ExitGameLobby::path(), ExitGameLobby::pathFocus()),
                Vector2D<unsigned int>(ExitGameLobby::topX, ExitGameLobby::topY),
                Vector2D<unsigned int>(ExitGameLobby::sizeX, ExitGameLobby::sizeY));
    setButtonInstance(ExitGameLobby::name(), EXIT_INSTANCE);
}

void
MenuLobby::validAsset(std::string const &name, std::string const &path, Vector2D<unsigned int> const &postion,
                      Vector2D<unsigned int> const &size) {
    std::ifstream infile(path);

    if (!infile.good())
        throw ErrorsMenuLobby(std::cerr, "This file '" + path + "' does not exist");
    else {
        _sfmlHandler.createTextureFromFile(name, path, size.x, size.y);
        _sfmlHandler.createSprite(name, postion, size);
        infile.clear();
    }
}

void MenuLobby::validButton(Vector2D<std::string> const &names, Vector2D<std::string> const &paths,
                            Vector2D<unsigned int> const &position, Vector2D<unsigned int> const &size) {
    std::ifstream infileFirst(paths.x);
    std::ifstream infileSecond(paths.y);

    if (!infileFirst.good())
        throw ErrorsMenuLobby(std::cerr, "This file '" + paths.x + "' does not exist");
    else if (!infileSecond.good())
        throw ErrorsMenuLobby(std::cerr, "This file '" + paths.y + "' does not exist");
    else {
        createButton(names, paths, position, size);
        infileFirst.clear();
        infileSecond.clear();
    }
}

void MenuLobby::createButton(Vector2D<std::string> const &names, Vector2D<std::string> const &paths,
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

void MenuLobby::setButtonInstance(std::string const &name, InstanceStatus const &status) {
    if (_buttons.find(name) != _buttons.end())
        _buttons[name].setInstance(status);
    else
        throw ErrorsMenuLobby(std::cerr, "Button '" + name + "' not found");
}

void MenuLobby::draw() {
    _sfmlHandler.drawSprite(MenuLobbyModel::name());
    _sfmlHandler.drawSprite(ButtonCloseLobby::name());
    _sfmlHandler.drawSprite(ExitGameLobby::name());
    drawButtonReady();
    drawButtonCancel();
    drawButtonPlus();
    drawSlotsUsername();
}

void MenuLobby::drawButtonCancel() {
    _slots[SLOT_BLUE]->drawCancel();
    _slots[SLOT_GREEN]->drawCancel();
    _slots[SLOT_RED]->drawCancel();
    _slots[SLOT_YELLOW]->drawCancel();
}

void MenuLobby::drawButtonPlus() {
    _slots[SLOT_BLUE]->drawPlus();
    _slots[SLOT_GREEN]->drawPlus();
    _slots[SLOT_RED]->drawPlus();
    _slots[SLOT_YELLOW]->drawPlus();
}

void MenuLobby::drawButtonReady() {
    _slots[SLOT_BLUE]->drawReady();
    _slots[SLOT_GREEN]->drawReady();
    _slots[SLOT_RED]->drawReady();
    _slots[SLOT_YELLOW]->drawReady();
}

void MenuLobby::drawSlotsUsername() {
    _slots[SLOT_BLUE]->drawPlayerName();
    _slots[SLOT_GREEN]->drawPlayerName();
    _slots[SLOT_RED]->drawPlayerName();
    _slots[SLOT_YELLOW]->drawPlayerName();
}

InstanceStatus MenuLobby::manageEvent(enum Event const &event, InstanceStatus const &last) {
    switch (event) {
        case E_MOUSE_PRESSED:
            return buttonPressed(_sfmlHandler.getMousePressedPosition());
        case E_MOUSE_RELEASED:
            return buttonReleased(_sfmlHandler.getMousePressedPosition(), last);
        default:
            break;
    }
    return UNDEFINED_INSTANCE;
}

InstanceStatus MenuLobby::buttonPressed(Vector2D<int> const &position) {
    for (auto &_button : _buttons) {
        if (_button.second.isSelected(position)) {
            _sfmlHandler.drawSprite(_button.second.getNameFocus());
            return UNDEFINED_INSTANCE;
        }
    }
    return slotPressed(position);
}

InstanceStatus MenuLobby::buttonReleased(Vector2D<int> const &position, InstanceStatus const &last) {
    _sfmlHandler.setMousePosition(Vector2D<int>(-1, -1));

    for (auto &_button : _buttons) {
        if (_button.second.isSelected(position))
            return clearServerName(_button.second.getInstance(), last);
    }
    return slotReleased(position);
}

InstanceStatus MenuLobby::slotPressed(Vector2D<int> const &position) {
    for (auto &_slot : _slots)
        if (!_slot.second->getisLocked()) {
            _slot.second->isPressed(position);
        }
    return UNDEFINED_INSTANCE;
}

InstanceStatus MenuLobby::slotReleased(Vector2D<int> const &position) {
    InstanceStatus status;

    for (auto &_slot : _slots) {
        if (!_slot.second->getisLocked() && _slot.second->isReleased(position)) {
            status = manageCommand(_slot.second->commandReleased(position), _slot.second->getState());
            return (status == GAME_INSTANCE) ? status : _slot.second->getReleased(position);
        }
    }
    return UNDEFINED_INSTANCE;
}

InstanceStatus MenuLobby::clearServerName(InstanceStatus const &instance, InstanceStatus const &last) {
    int userSlot;
    InstanceStatus temp = instance;

    if (temp == PREVIOUS_INSTANCE) {
        _sfmlHandler.playMusic(RETURN_SOUND());
        _serverName.clear();
        if ((userSlot = getUserSlot()) != -1)
            temp = sendLeaveSlot(static_cast<unsigned int>(userSlot));
        temp = sendLeaveInstance();
        if (last == ROOMS_INSTANCE)
            temp = sendJoinServer();
    } else {
        _serverName.clear();
        if ((userSlot = getUserSlot()) != -1)
            sendLeaveSlot(static_cast<unsigned int>(userSlot));
        sendLeaveInstance();
        return EXIT_INSTANCE;
    }
    return temp;
}

int MenuLobby::getUserSlot() {
    for (auto &slot : _slots) {
        if (slot.second->getPlayerName() == _userName)
            return slot.second->getState();
    }
    return -1;
}

InstanceStatus MenuLobby::manageCommand(CommandType const &cmd, unsigned int const &slot) {
    switch (cmd) {
        case JOIN_SLOT:
            return sendJoinSlot(slot);
        case PLAYER_READY:
            return (_slots[static_cast<SlotState>(slot)]->getisReady()) ? sendPlayerNotReady(slot) : sendPlayerReady(slot);
        case LEAVE_SLOT:
            return sendLeaveSlot(slot);
        default:
            break;
    }
    return UNDEFINED_INSTANCE;
}

void MenuLobby::manageSlot(std::vector<std::string> const &slots) {
    for (unsigned int idx = 0; idx < slots.size(); idx++) {
        switch (idx) {
            case 0:
                setSlotInfos(SLOT_BLUE, slots.at(idx));
                break;
            case 1:
                setSlotInfos(SLOT_RED, slots.at(idx));
                break;
            case 2:
                setSlotInfos(SLOT_YELLOW, slots.at(idx));
                break;
            case 3:
                setSlotInfos(SLOT_GREEN, slots.at(idx));
                break;
            default:
                break;
        }
    }
}

void MenuLobby::setSlotInfos(SlotState const &state, std::string const &infos) {
    std::string temp;

    if (infos != "EMPTY") {
        temp = infos.substr(0, infos.find(':'));
        (temp == _userName) ? _slots[state]->setisLocked(false) : _slots[state]->setisLocked(true);
        _slots[state]->setisOccuped(true);
        _slots[state]->setPlayerText(temp);
        _slots[state]->setPlayerName(temp);
        _slots[state]->setisReady((infos.substr(infos.find(':') + 1, infos.size() - temp.size()) != "0"));
    } else {
        _slots[state]->setPlayerText("");
        _slots[state]->setPlayerName("");
        _slots[state]->setisOccuped(false);
        _slots[state]->setisReady(false);
        _slots[state]->setisLocked(false);
        lockSlotBlue(true);
        lockSlotRed(true);
        lockSlotGreen(true);
        lockSlotYellow(true);
    }
}

void MenuLobby::lockSlotBlue(bool const &lock) {
    if (_slots[SLOT_BLUE]->getPlayerName() == _userName) {
        _slots[SLOT_RED]->setisLocked(lock);
        _slots[SLOT_GREEN]->setisLocked(lock);
        _slots[SLOT_YELLOW]->setisLocked(lock);
    }
}

void MenuLobby::lockSlotRed(bool const &lock) {
    if (_slots[SLOT_RED]->getPlayerName() == _userName) {
        _slots[SLOT_BLUE]->setisLocked(lock);
        _slots[SLOT_GREEN]->setisLocked(lock);
        _slots[SLOT_YELLOW]->setisLocked(lock);
    }
}

void MenuLobby::lockSlotGreen(bool const &lock) {
    if (_slots[SLOT_GREEN]->getPlayerName() == _userName) {
        _slots[SLOT_BLUE]->setisLocked(lock);
        _slots[SLOT_RED]->setisLocked(lock);
        _slots[SLOT_YELLOW]->setisLocked(lock);
    }
}

void MenuLobby::lockSlotYellow(bool const &lock) {
    if (_slots[SLOT_YELLOW]->getPlayerName() == _userName) {
        _slots[SLOT_BLUE]->setisLocked(lock);
        _slots[SLOT_RED]->setisLocked(lock);
        _slots[SLOT_GREEN]->setisLocked(lock);
    }
}

InstanceStatus MenuLobby::returnToLogin() {
    _server.decoClient();
    _userName.clear();
    _serverName.clear();
    _listServer.clear();
    return LOGIN_INSTANCE;
}

InstanceStatus MenuLobby::sendPlayerReady(unsigned int const &slot) {

    _lobbyTCP.send("PLAYER_READY;" + _userName + ";1");
    auto vectorCmd = _lobbyTCP.receive();

    if (!vectorCmd.empty() && vectorCmd.front().get()->commandType == PLAYER_READY_RESPONSE) {
        auto cmd = static_cast<PlayerReadyResponseCommand *>(&(*vectorCmd.front()));
        if (cmd->validation) {
            _slots[static_cast<SlotState>(slot)]->setisOccuped(true);
            _slots[static_cast<SlotState>(slot)]->setisReady(true);
        }
    }
    return UNDEFINED_INSTANCE;
}

InstanceStatus MenuLobby::sendPlayerNotReady(unsigned int const &slot) {

    _lobbyTCP.send("PLAYER_READY;" + _userName + ";0");
    auto vectorCmd = _lobbyTCP.receive();

    if (!vectorCmd.empty() && vectorCmd.front().get()->commandType == PLAYER_READY_RESPONSE) {
        auto cmd = static_cast<PlayerReadyResponseCommand *>(&(*vectorCmd.front()));
        if (!cmd->validation) {
            _slots[static_cast<SlotState>(slot)]->setisOccuped(true);
            _slots[static_cast<SlotState>(slot)]->setisReady(true);
        }
    }
    return UNDEFINED_INSTANCE;
}

InstanceStatus MenuLobby::sendLeaveInstance() {
    if (!_lobbyTCP.send("LEAVE_INSTANCE;" + _userName))
        return returnToLogin();
    return PREVIOUS_INSTANCE;
}

InstanceStatus MenuLobby::sendLeaveSlot(unsigned int const &slot) {

    _lobbyTCP.send("LEAVE_SLOT;" + _userName);
    auto vectorCmd = _lobbyTCP.receive();

    if (!vectorCmd.empty() && vectorCmd.front().get()->commandType == LEAVE_SLOT_RESPONSE) {
        auto cmd = static_cast<LeaveSlotResponseCommand *>(&(*vectorCmd.front()));

        if (cmd->validation) {
            _slots[static_cast<SlotState>(slot)]->setisOccuped(false);
            _slots[static_cast<SlotState>(slot)]->setisReady(false);
            lockSlotBlue(false);
            lockSlotRed(false);
            lockSlotGreen(false);
            lockSlotYellow(false);
            _slots[static_cast<SlotState>(slot)]->setPlayerName("");
            _slots[static_cast<SlotState>(slot)]->setPlayerText("");
        }
    }
    return UNDEFINED_INSTANCE;
}

InstanceStatus MenuLobby::sendJoinSlot(unsigned int const &slot) {
    std::ostringstream ss;

    ss << slot;
    _lobbyTCP.send("JOIN_SLOT;" + _userName + ";" + ss.str());
    auto vectorCmd = _lobbyTCP.receive();

    if (!vectorCmd.empty() && vectorCmd.front().get()->commandType == JOIN_SLOT_RESPONSE) {

        auto cmd = static_cast<JoinSlotResponseCommand *>(&(*vectorCmd.front()));
        if (cmd->slotPos != -1) {
            _slots[static_cast<SlotState>(cmd->slotPos)]->setisOccuped(true);
            _slots[static_cast<SlotState>(slot)]->setPlayerName(_userName);
            _slots[static_cast<SlotState>(slot)]->setPlayerText(_userName);
        }
    }
    return UNDEFINED_INSTANCE;
}

InstanceStatus MenuLobby::getSlotStatus() {
    std::string str;
    std::istringstream stream;
    std::vector<std::string> response;

    if (!_lobbyTCP.send("SLOT_STATUS;" + _userName))
        return returnToLogin();

    auto vectorCmd = _lobbyTCP.receive();
    if (!vectorCmd.empty() && vectorCmd.front().get()->commandType == DISCONNECT_SERVER)
        return returnToLogin();

    if (!vectorCmd.empty() && vectorCmd.front().get()->commandType == SLOT_STATUS_RESPONSE) {

        auto cmd = static_cast<SlotStatusResponseCommand *>(&(*vectorCmd.front()));
        stream = std::istringstream(cmd->body);
        while (getline(stream, str, '/')) {
            response.push_back(str);
        }
        manageSlot(response);
    } else if (!vectorCmd.empty() && vectorCmd.front().get()->commandType == ALL_PLAYER_READY) {

        auto cmd = static_cast<AllPlayerReadyCommand *>(&(*vectorCmd.front()));

        if (cmd->validation) {
            _sfmlHandler.stopMusic(MUSIC_MENU());
            return GAME_INSTANCE;
        }
    }
    return UNDEFINED_INSTANCE;
}

InstanceStatus MenuLobby::sendJoinServer() {
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
    return ROOMS_INSTANCE;
}