/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef ERRORSENTITYCLIENT_HPP
#define ERRORSENTITYCLIENT_HPP

#include "../../Errors/Errors.hpp"


class ErrorsEntityClient: public Errors {
public:
    ErrorsEntityClient(std::ostream &, const std::string &) noexcept;
    ~ErrorsEntityClient() noexcept override = default;
};

#endif //ERRORSENTITYCLIENT_HPP