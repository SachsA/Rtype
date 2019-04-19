/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef ERRORSMENUPAUSE_HPP
#define ERRORSMENUPAUSE_HPP

#include "../../../Errors/Errors.hpp"

class ErrorsMenuPause: public Errors {
public:
    ErrorsMenuPause(std::ostream &, const std::string &) noexcept;
    ~ErrorsMenuPause() noexcept override = default;
};


#endif //ERRORSMENUPAUSE_HPP
