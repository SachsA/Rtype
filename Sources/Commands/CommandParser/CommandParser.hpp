/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#ifndef CPP_RTYPE_2018_COMMANDPARSER_HPP
#define CPP_RTYPE_2018_COMMANDPARSER_HPP


#include <string>
#include <memory>
#include <vector>


#include "../ACommand.hpp"
#include "../CoreCommands/CoreCommand.hpp"
#include "../LobbyCommands/LobbyCommands.hpp"
#include "../GameCommands/GameCommands.hpp"

class CommandParser {
public:
    CommandParser() = default;
    ~CommandParser() = default;

    std::vector<std::string> hashCmd(std::string const &cmd);
    void addClientCmd(std::vector<std::shared_ptr<ACommand>> &, std::string &cmd);
    void addServerCmd(std::vector<std::shared_ptr<ACommand>> &, std::string &cmd);
    void addGameClientCmd(std::vector<std::shared_ptr<ACommand>> &, std::string &cmd);
    void addGameServerCmd(std::vector<std::shared_ptr<ACommand>> &, std::string &cmd);
    CommandType getTypeCmd(std::vector<std::string> &cmd);
    CommandType getGameTypeCmd(std::vector<std::string> &cmd);
};


#endif //CPP_RTYPE_2018_COMMANDPARSER_HPP
