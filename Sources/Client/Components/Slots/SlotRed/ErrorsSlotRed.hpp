/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef ERRORSSLOTRED_HPP
#define ERRORSSLOTRED_HPP

#include "../../../../Errors/Errors.hpp"


class ErrorsSlotRed: public Errors {
public:
    ErrorsSlotRed(std::ostream &, const std::string &) noexcept;
    ~ErrorsSlotRed() noexcept override = default;
};

#endif //ERRORSSLOTRED_HPP