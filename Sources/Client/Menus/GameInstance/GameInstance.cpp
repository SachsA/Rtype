/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Alexandre Sachs
*/

#include <iostream>
#include <fstream>
#include <thread>

#include "ModelGameInstance.hpp"
#include "GameInstance.hpp"
#include "../../Constants/Sounds.hpp"
#include "../../LibLoader/LibLoader.hpp"

GameInstance::GameInstance(SFMLHandler const &sfmlHandler, std::string &userName, std::string &serverName,
    CommunicationTCPClient &server, std::vector<std::string> &listServer,
    CommunicationTCPClient &lobbyTCP, CommunicationUDPClient &lobbyUDP)
    : AMenu(sfmlHandler, userName, serverName), _server(server), _listServer(listServer),
      _lobbyTCP(lobbyTCP), _lobbyUDP(lobbyUDP)
{
    initializeAssets();
    initializeShader();
}

void GameInstance::initializeAssets()
{
    validAsset(GameInstanceModel::name(), GameInstanceModel::path(),
               Vector2D<unsigned int>(GameInstanceModel::topX, GameInstanceModel::topY),
               Vector2D<unsigned int>(GameInstanceModel::sizeX, GameInstanceModel::sizeY));

    validAsset(GameInstanceStarOne::name(), GameInstanceStarOne::path(),
               Vector2D<unsigned int>(GameInstanceStarOne::topX, GameInstanceStarOne::topY),
               Vector2D<unsigned int>(GameInstanceStarOne::sizeX, GameInstanceStarOne::sizeY));

    validAsset(GameInstanceStarTwo::name(), GameInstanceStarTwo::path(),
               Vector2D<unsigned int>(GameInstanceStarTwo::topX, GameInstanceStarTwo::topY),
               Vector2D<unsigned int>(GameInstanceStarTwo::sizeX, GameInstanceStarTwo::sizeY));

    validAsset(GameInstanceStarThree::name(), GameInstanceStarThree::path(),
               Vector2D<unsigned int>(GameInstanceStarThree::topX, GameInstanceStarThree::topY),
               Vector2D<unsigned int>(GameInstanceStarThree::sizeX, GameInstanceStarThree::sizeY));
}

void GameInstance::initializeShader()
{
    _sfmlHandler.loadShaderFromMemory(
        "uniform float offset;"
        "void main() {"
        "    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
        "    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
        "    gl_TexCoord[0].x = gl_TexCoord[0].x + offset;"
        "    gl_FrontColor = gl_Color;"
        "}");
    _sfmlHandler.setTextureRepeated(GameInstanceStarOne::name(), true);
    _sfmlHandler.setTextureRepeated(GameInstanceStarTwo::name(), true);
    _sfmlHandler.setTextureRepeated(GameInstanceStarThree::name(), true);
}

void GameInstance::validAsset(std::string const &name, std::string const &path, Vector2D<unsigned int> const &position,
    Vector2D<unsigned int> const &size)
{
    std::ifstream infile(path);

    if (!infile.good())
        throw ErrorsGameInstance(std::cerr, "This file '" + path + "' does not exist");
    else {
        _sfmlHandler.createTextureFromFile(name, path, size.x, size.y);
        _sfmlHandler.createSprite(name, position, size);
        infile.clear();
    }
}

InstanceStatus GameInstance::launch(enum Event const &event, InstanceStatus const &last)
{
    if (_sfmlHandler.getMusicStatus(MUSIC_GAME()) == S_STOPPED)
        _sfmlHandler.playMusic(MUSIC_GAME());
    _lobbyUDP.send("ALIVE");
    draw();
    return manageEvent(event);
}

void GameInstance::launchThread()
{
    std::thread thread(&GameInstance::mainLoopThread, this);
    thread.detach();
}

void GameInstance::draw()
{
    drawShader();
    drawEntities();
}

void GameInstance::drawEntities()
{
    for (auto &_entity : _entities) {
        _sfmlHandler.drawSprite(_entity.first);
    }
}

void GameInstance::drawShader()
{
    _sfmlHandler.drawSprite(GameInstanceModel::name());

    _offsetStarOne += _sfmlHandler.getClockElapsedTime() / 80;
    _sfmlHandler.setShaderUniform("offset", _offsetStarOne);
    _sfmlHandler.drawSpriteWithShader(GameInstanceStarOne::name());

    _offsetStarTwo += _sfmlHandler.getClockElapsedTime() / 25;
    _sfmlHandler.setShaderUniform("offset", _offsetStarTwo);
    _sfmlHandler.drawSpriteWithShader(GameInstanceStarTwo::name());

    _offsetStarThree += _sfmlHandler.getClockElapsedTime() / 10;
    _sfmlHandler.setShaderUniform("offset", _offsetStarThree);
    _sfmlHandler.drawSpriteWithShader(GameInstanceStarThree::name());

    _sfmlHandler.resetClock();
}

InstanceStatus GameInstance::manageEvent(enum Event const &event)
{
    if (event == E_KEY_UP) {
        _lobbyUDP.send("INPUT_KEY;" + _userName + ";KEY_UP");
    }
    if (event == E_KEY_DOWN) {
        _lobbyUDP.send("INPUT_KEY;" + _userName + ";KEY_DOWN");

    }
    if (event == E_KEY_LEFT) {
        _lobbyUDP.send("INPUT_KEY;" + _userName + ";KEY_LEFT");

    }
    if (event == E_KEY_RIGHT) {
        _lobbyUDP.send("INPUT_KEY;" + _userName + ";KEY_RIGHT");
    }
    if (event == E_KEY_SPACE) {
        _lobbyUDP.send("INPUT_KEY;" + _userName + ";KEY_SPACE");
    }
    if (manageCommand())
        return EXIT_INSTANCE;
    return UNDEFINED_INSTANCE;
}

InstanceStatus GameInstance::returnToLogin()
{
    _server.decoClient();
    _userName.clear();
    _serverName.clear();
    _listServer.clear();
    return LOGIN_INSTANCE;
}

void GameInstance::mainLoopThread()
{
    while (1) {
        auto cmd = _lobbyUDP.receive();
        _commandMutex.lock();
        while (!cmd.empty()) {
            checkDuplicate(*cmd.begin());
            cmd.erase(cmd.begin());
        }
        _commandMutex.unlock();
    }
}

bool GameInstance::manageCommand()
{

    auto ret = false;
    _commandMutex.lock();
    for (auto &_command : _commands) {
        switch (_command.get()->commandType) {
            case UPDATE_ENTITY:
                updateEntity(*static_cast<UpdateEntityCommand *>(_command.get()));
                break;
            case GAME_PLAYER_STATUS:
                updatePlayerStatus(*static_cast<PlayerStatusCommand *>(_command.get()));
                break;
            case END_GAME:
                ret = true;
                break;
            default:
                break;
        }
        _commands.erase(_commands.begin());
    }
    _commandMutex.unlock();
    return ret;
}

void GameInstance::updateEntity(UpdateEntityCommand const &command)
{
    if (_entities.find(command.name) != _entities.end()) {
        _entities[command.name]->setPosition(static_cast<unsigned int>(command.pos.x),
                                             static_cast<unsigned int>(command.pos.y));
        _sfmlHandler.setSpritePosition(command.name, static_cast<float>(command.pos.x),
                                       static_cast<float>(command.pos.y));
    } else {
        loadEntity(command);
        if (_entities.find(command.name) != _entities.end()) {
            _entities[command.name]->setPosition(static_cast<unsigned int>(command.pos.x),
                                                 static_cast<unsigned int>(command.pos.y));
            _sfmlHandler.createTextureFromFile(command.name, _entities[command.name]->getAssetPath(),
                                               _entities[command.name]->getSize().x,
                                               _entities[command.name]->getSize().y);
            _sfmlHandler.createSprite(command.name, _entities[command.name]->getPosition(),
                                      _entities[command.name]->getSize());
        }
    }
}

void GameInstance::updatePlayerStatus(PlayerStatusCommand const &status)
{
}

void GameInstance::loadEntity(UpdateEntityCommand const &command)
{
#ifdef _WIN32
    EntityLoader entityLoader("./lib/" + command.entityType + "Client.dll");
#elif defined (linux)
    EntityLoader entityLoader("./lib/lib" + command.entityType + "Client.so");
#endif
    AEntityClient *entity = entityLoader.load("buildEngine");

    if (entity != nullptr)
        _entities.emplace(command.name, entity);
}

bool GameInstance::checkDuplicate(std::shared_ptr<ACommand> &node)
{

    if (_commands.empty()) {
        _commands.emplace_back(node);
        return true;
    }

    auto command = _commands.begin();

    while (command != _commands.end()) {
        if ((*command)->commandType == node->commandType) {
            if ((*command)->commandType == UPDATE_ENTITY) {
                auto cmd1 = *static_cast<UpdateEntityCommand *>(&(**command));
                auto cmd2 = *static_cast<UpdateEntityCommand *>(&(*node));
                if (cmd1.name == cmd2.name && (cmd1.pos.y != cmd2.pos.y || cmd1.pos.x != cmd2.pos.x)) {
                    _commands.erase(command);
                    _commands.emplace_back(node);
                    return true;
                }
            }
        }
        command++;
    }

    return false;
}