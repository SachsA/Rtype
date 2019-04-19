/*
** EPITECH PROJECT, 2021
** Project: CPP_rtype_2018
** File: ErrorsLibLoader.cpp
** File description:
** Errors file for ErrorsLibLoader, inherit from Errors class
**
** Created by Alexandre Sachs on 19/12/18 at 00:51
*/

#include <string>
#include "ErrorsLibLoader.hpp"

ErrorsLibLoader::ErrorsLibLoader(std::ostream &os, const std::string &message) noexcept
        : Errors(os, message)
{}