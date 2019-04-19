/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef ERRORSSLOTBLUE_HPP
#define ERRORSSLOTBLUE_HPP

#include "../../../../Errors/Errors.hpp"


class ErrorsSlotBlue: public Errors {
public:
    ErrorsSlotBlue(std::ostream &, const std::string &) noexcept;
    ~ErrorsSlotBlue() noexcept override = default;
};

#endif //ERRORSSLOTBLUE_HPP