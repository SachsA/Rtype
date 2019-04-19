/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef ERRORSSLOTGREEN_HPP
#define ERRORSSLOTGREEN_HPP

#include "../../../../Errors/Errors.hpp"


class ErrorsSlotGreen: public Errors {
public:
    ErrorsSlotGreen(std::ostream &, const std::string &) noexcept;
    ~ErrorsSlotGreen() noexcept override = default;
};

#endif //ERRORSSLOTGREEN_HPP