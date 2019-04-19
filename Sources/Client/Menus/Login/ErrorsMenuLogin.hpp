/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef ERRORSMENULOGIN_HPP
#define ERRORSMENULOGIN_HPP

#include "../../../Errors/Errors.hpp"

class ErrorsMenuLogin: public Errors {
public:
    ErrorsMenuLogin(std::ostream &, const std::string &) noexcept;
    ~ErrorsMenuLogin() noexcept override = default;
};

#endif //ERRORSMENULOGIN_HPP