/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#ifndef CPP_RTYPE_2018_GAMECOMMANDS_HPP
#define CPP_RTYPE_2018_GAMECOMMANDS_HPP

#include <string>
#include <chrono>
#include "../../Template/Vector2D/Vector2D.hpp"
#include "../ACommand.hpp"

struct KeyInputCommand : public ACommand {
    KeyInputCommand(std::string const &name, std::string const &input) : ACommand(CommandType::INPUT_KEY, name)
    {
        key = input;
    };
    std::string key;
};

struct MoveUpCommand : public ACommand {
    MoveUpCommand() : ACommand(CommandType::GAME_MOVE_UP, "")
    {
    };
};

struct MoveLeftCommand : public ACommand {
    MoveLeftCommand() : ACommand(CommandType::GAME_MOVE_LEFT, "")
    {
    };
};

struct MoveRightCommand : public ACommand {
    MoveRightCommand() : ACommand(CommandType::GAME_MOVE_RIGHT, "")
    {
    };
};

struct MoveDownCommand : public ACommand {
    MoveDownCommand() : ACommand(CommandType::GAME_MOVE_DOWN, "")
    {
    };
};

struct AttackCommand : public ACommand {
    AttackCommand() : ACommand(CommandType::GAME_ATTACK, "")
    {
    };
};

struct EndGameCommand : public ACommand {
    EndGameCommand() : ACommand(CommandType::END_GAME, "")
    {
    };
};

struct CreateLibraryCommand : public ACommand {
    CreateLibraryCommand(std::string const &libName, Vector2D<double> const &position, std::chrono::time_point<std::chrono::system_clock> const &creationDate)
        : ACommand(CommandType::CREATE_LIBRARY, libName)
    {
        name = libName;
        pos = position;
        spawnTime = creationDate;
    }

    std::string name;
    Vector2D<double> pos;
    std::chrono::time_point<std::chrono::system_clock> spawnTime;
};

struct UpdateEntityCommand : public ACommand {
    UpdateEntityCommand(std::string const &libName, std::string const &type, Vector2D<double> const &position) : ACommand(CommandType::UPDATE_ENTITY, "")
    {
        name = libName;
        pos = position;
        entityType = type;
    }

    std::string name;
    Vector2D<double> pos;
    std::string entityType;
};

struct PlayerStatusCommand : public ACommand {
    PlayerStatusCommand(std::string const &cmdBody) : ACommand(CommandType::GAME_PLAYER_STATUS, "")
    {
        body = cmdBody;
    };
    std::string body;
};


#endif //CPP_RTYPE_2018_GAMECOMMANDS_HPP
