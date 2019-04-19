/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef ERRORSMENUROOMS_HPP
#define ERRORSMENUROOMS_HPP

#include "../../../Errors/Errors.hpp"

class ErrorsMenuRooms: public Errors {
public:
    ErrorsMenuRooms(std::ostream &, const std::string &) noexcept;
    ~ErrorsMenuRooms() noexcept override = default;
};

#endif //ERRORSMENUROOMS_HPP
