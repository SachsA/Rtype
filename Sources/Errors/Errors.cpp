/*
** EPITECH PROJECT, 2021
** Project: CPP_rtype_2018
** File: Errors.cpp
** File description:
** Errors class for RTYPE
**
** Created by Alexandre Sachs on 19/11/18 at 20:22
*/

#include "Errors.hpp"

Errors::Errors(std::ostream &os, const std::string &message) noexcept
		: _os(os)
{
	_message = message;
}

const char *Errors::what() const noexcept
{
	return _message.c_str();
}
