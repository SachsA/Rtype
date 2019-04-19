/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include <iostream>
#include <fstream>
#include <thread>
#include "CoreClient.hpp"
#include "../Constants/Constants.hpp"
#include "../Constants/Sounds.hpp"
#include "../Menus/Principal/MenuPrincipal.hpp"
#include "../Menus/Pause/MenuPause.hpp"
#include "../Menus/Settings/MenuSettings.hpp"
#include "../Menus/Right/MenuRight.hpp"
#include "../Menus/Rooms/MenuRooms.hpp"
#include "../Menus/Lobby/MenuLobby.hpp"
#include "../Menus/Login/MenuLogin.hpp"
#include "../Menus/GameInstance/GameInstance.hpp"
#include "ErrorsCoreClient.hpp"

CoreClient::CoreClient()
{
    _sfmlHandler.createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE());
    _sfmlHandler.manageWindowPosition(0, 0);
    validPath(FONT_FILENAME());
    _sfmlHandler.createFontFromFile(FONT_FILENAME());
    loadMusics();
    loadSounds();
    initializeInstances();
}

CoreClient::~CoreClient() {}

void CoreClient::launchClient() {
    enum Event event = E_UNDEFINED;
    InstanceStatus status = InstanceStatus::LOGIN_INSTANCE;
    InstanceStatus last = InstanceStatus::LOGIN_INSTANCE;

	_sfmlHandler.playMusic(MUSIC_MENU());
    while (_sfmlHandler.isOpenWindow()) {
        event = (event != E_MOUSE_PRESSED && event != E_MOUSE_RELEASED) ? E_UNDEFINED : event;
        while (_sfmlHandler.listenEvent()) {
            event = _sfmlHandler.manageWindowEvent();
        }
        _sfmlHandler.clearWindow();
		launchInstance(status, last, event);
        _sfmlHandler.displayWindow();

        if (status == EXIT_INSTANCE)
            _sfmlHandler.closeEventWindow();
    }
}

void CoreClient::launchInstance(InstanceStatus &status, InstanceStatus &last, enum Event const &event) {
    InstanceStatus tmp = _instances[status]->launch(event, last);

    if (tmp == GAME_INSTANCE)
        (static_cast<GameInstance *>(_instances[InstanceStatus::GAME_INSTANCE].get()))->launchThread();

    if (tmp == PREVIOUS_INSTANCE)
        status = last;
    else if (tmp != UNDEFINED_INSTANCE) {
        last = status;
        status = tmp;
    }
}

void CoreClient::initializeInstances() {
    _instances.emplace(InstanceStatus::LOGIN_INSTANCE, std::make_unique<MenuLogin>(_sfmlHandler, _userName, _serverName, _communicationServer));
    _instances.emplace(InstanceStatus::PRINCIPAL_INSTANCE, std::make_unique<MenuPrincipal>(_sfmlHandler, _userName, _serverName, _communicationServer, _listServer));
    _instances.emplace(InstanceStatus::PAUSE_INSTANCE, std::make_unique<MenuPause>(_sfmlHandler, _userName, _serverName, _communicationServer));
    _instances.emplace(InstanceStatus::SETTINGS_INSTANCE, std::make_unique<MenuSettings>(_sfmlHandler, _userName, _serverName, _communicationServer));
    _instances.emplace(InstanceStatus::RIGHT_INSTANCE, std::make_unique<MenuRight>(_sfmlHandler, _userName, _serverName, _communicationServer, _communicationLobby, _communicationGame));
    _instances.emplace(InstanceStatus::ROOMS_INSTANCE, std::make_unique<MenuRooms>(_sfmlHandler, _userName, _serverName, _communicationServer, _listServer, _communicationLobby, _communicationGame));
    _instances.emplace(InstanceStatus::LOBBY_INSTANCE, std::make_unique<MenuLobby>(_sfmlHandler, _userName, _serverName, _communicationServer, _listServer, _communicationLobby));
	_instances.emplace(InstanceStatus::GAME_INSTANCE, std::make_unique<GameInstance>(_sfmlHandler, _userName, _serverName, _communicationServer, _listServer, _communicationLobby, _communicationGame));
}

void CoreClient::loadMusics()
{
	_sfmlHandler.createMusic(MUSIC_MENU(), MUSIC_MENU_FILENAME());
	_sfmlHandler.createMusic(MUSIC_GAME(), MUSIC_GAME_FILENAME());
	_sfmlHandler.setMusicLoop(MUSIC_MENU(), true);
	_sfmlHandler.setMusicLoop(MUSIC_GAME(), true);
}

void CoreClient::loadSounds()
{
	_sfmlHandler.createMusic(POWER_UP_SOUND(), POWER_UP_SOUND_FILENAME());
	_sfmlHandler.createMusic(CONFIRM_SOUND(), CONFIRM_SOUND_FILENAME());
	_sfmlHandler.createMusic(CLICK_SOUND(), CLICK_SOUND_FILENAME());
	_sfmlHandler.createMusic(RETURN_SOUND(), RETURN_SOUND_FILENAME());
	_sfmlHandler.createMusic(ENGINE_SOUND(), ENGINE_SOUND_FILENAME());
	_sfmlHandler.createMusic(EXPLOSION_SOUND(), EXPLOSION_SOUND_FILENAME());
	_sfmlHandler.createMusic(SHOT_ALLY_SOUND(), SHOT_ALLY_SOUND_FILENAME());
	_sfmlHandler.createMusic(SHOT_ENEMY_SOUND(), SHOT_ENEMY_SOUND_FILENAME());
}

void CoreClient::validPath(std::string const &path) {
    std::ifstream infile(path);

    if (!infile.good())
        throw ErrorsCoreClient(std::cerr, "This file '" + path + "' does not exist");
    else
        infile.clear();
}