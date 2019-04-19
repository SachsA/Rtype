/*
** EPITECH PROJECT, 2021
** Project: CPP_rtype_2018
** File: ErrorsLibLoader.h
** File description:
** Header for Errors LibLoader
**
** Created by Alexandre Sachs on 19/12/2018 at 00 49
*/

#ifndef CPP_RTYPE_2018_ERRORS_LIBLOADER_H
#define CPP_RTYPE_2018_ERRORS_LIBLOADER_H

#include <ostream>
#include "../../Errors/Errors.hpp"

class ErrorsLibLoader: public Errors {
public:
    ErrorsLibLoader(std::ostream &, const std::string &) noexcept;

    ~ErrorsLibLoader() noexcept override = default;
};

#endif //CPP_RTYPE_2018_ERRORS_LIBLOADER_H