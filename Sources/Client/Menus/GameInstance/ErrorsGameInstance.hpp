/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef ERRORSGAMEINSTANCE_HPP
#define ERRORSGAMEINSTANCE_HPP

#include "../../../Errors/Errors.hpp"


class ErrorsGameInstance: public Errors {
public:
    ErrorsGameInstance(std::ostream &, const std::string &) noexcept;
    ~ErrorsGameInstance() noexcept override = default;
};

#endif //ERRORSGAMEINSTANCE_HPP