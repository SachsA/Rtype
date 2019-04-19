/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef ERRORSMENULOBBY_HPP
#define ERRORSMENULOBBY_HPP

#include "../../../Errors/Errors.hpp"

class ErrorsMenuLobby: public Errors {
public:
    ErrorsMenuLobby(std::ostream &, const std::string &) noexcept;
    ~ErrorsMenuLobby() noexcept override = default;
};

#endif //ERRORSMENULOBBY_HPP
