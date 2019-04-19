/*
** EPITECH PROJECT, 2021
** Project: CPP_rtype_2018
** File: ErrorsSocket.h
** File description:
** Header for Errors Socket
**
** Created by Alexandre Sachs on 23/11/18 at 15:40
*/

#ifndef CPP_RTYPE_2018_ERRORS_SOCKET_H
#define CPP_RTYPE_2018_ERRORS_SOCKET_H

#include <ostream>
#include "../../../Errors/Errors.hpp"

class ErrorsSocket: public Errors {
public:
    ErrorsSocket(std::ostream &, const std::string &) noexcept;

    ~ErrorsSocket() noexcept override = default;
};

#endif //CPP_RTYPE_2018_ERRORS_SOCKET_H