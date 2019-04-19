/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef ERRORSCORECLIENT_HPP
#define ERRORSCORECLIENT_HPP

#include "../../Errors/Errors.hpp"


class ErrorsCoreClient: public Errors {
public:
    ErrorsCoreClient(std::ostream &, const std::string &) noexcept;
    ~ErrorsCoreClient() noexcept override = default;
};

#endif //ERRORSCORECLIENT_HPP