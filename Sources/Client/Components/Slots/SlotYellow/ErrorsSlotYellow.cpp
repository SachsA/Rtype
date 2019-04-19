/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include <string>
#include "ErrorsSlotYellow.hpp"

ErrorsSlotYellow::ErrorsSlotYellow(std::ostream &os, const std::string &message) noexcept
        : Errors(os, "SlotYellow : " + message) {}