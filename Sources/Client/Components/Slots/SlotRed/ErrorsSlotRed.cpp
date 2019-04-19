/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include <string>
#include "ErrorsSlotRed.hpp"

ErrorsSlotRed::ErrorsSlotRed(std::ostream &os, const std::string &message) noexcept
        : Errors(os, "SlotRed : " + message) {}