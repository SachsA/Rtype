/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef ERRORSMENUSETTINGS_HPP
#define ERRORSMENUSETTINGS_HPP

#include "../../../Errors/Errors.hpp"

class ErrorsMenuSettings: public Errors {
public:
    ErrorsMenuSettings(std::ostream &, const std::string &) noexcept;
    ~ErrorsMenuSettings() noexcept override = default;
};

#endif //ERRORSMENUSETTINGS_HPP
