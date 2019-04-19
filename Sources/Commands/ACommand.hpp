/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#ifndef CPP_RTYPE_2018_ACOMMAND_HPP
#define CPP_RTYPE_2018_ACOMMAND_HPP

#include "CommandType/CommandType.hpp"

class ACommand {
public :
    explicit ACommand(CommandType const &cmdType, std::string const &name) : commandType(cmdType), userName(name) {};
    CommandType commandType;
    std::string userName;
//    int slotPosition;

};

#endif // CPP_RTYPE_2018_ACOMMAND_HPP
