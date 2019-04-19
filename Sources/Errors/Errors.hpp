/*
** EPITECH PROJECT, 2021
** Project: CPP_rtype_2018
** File: Errors.cpp
** File description:
** Errors class for RTYPE
**
** Created by Alexandre Sachs on 19/11/18 at 20:22
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <exception>
#include <iostream>
#include <string>

class Errors: public std::exception {
public:
	Errors(std::ostream &, const std::string &) noexcept;

	~Errors() noexcept override = default;

	const char *what() const noexcept override;

private:
	std::string _message;
	std::ostream &_os;
};

#endif /* !ERRORS_HPP_ */
