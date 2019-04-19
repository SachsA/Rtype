/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef ERRORSMENUPRINCIPAL_HPP
#define ERRORSMENUPRINCIPAL_HPP

#include "../../../Errors/Errors.hpp"

class ErrorsMenuPrincipal: public Errors {
public:
    ErrorsMenuPrincipal(std::ostream &, const std::string &) noexcept;
    ~ErrorsMenuPrincipal() noexcept override = default;
};

#endif //ERRORSMENUPRINCIPAL_HPP
