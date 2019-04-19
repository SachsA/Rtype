/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef ERRORSMENURIGHT_HPP
#define ERRORSMENURIGHT_HPP

#include "../../../Errors/Errors.hpp"

class ErrorsMenuRight: public Errors {
public:
    ErrorsMenuRight(std::ostream &, const std::string &) noexcept;
    ~ErrorsMenuRight() noexcept override = default;
};

#endif //ERRORSMENURIGHT_HPP
