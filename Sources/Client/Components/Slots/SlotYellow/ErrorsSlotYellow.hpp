/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef ERRORSSLOTYELLOW_HPP
#define ERRORSSLOTYELLOW_HPP

#include "../../../../Errors/Errors.hpp"


class ErrorsSlotYellow: public Errors {
public:
    ErrorsSlotYellow(std::ostream &, const std::string &) noexcept;
    ~ErrorsSlotYellow() noexcept override = default;
};

#endif //ERRORSSLOTYELLOW_HPP