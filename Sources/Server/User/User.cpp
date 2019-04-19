//
// EPITECH PROJECT, 2018
// cpp_rtype
// File description:
// User related functions
//

#include "User.hpp"

User::User(std::string const &name)
    : ready(false), _name(name), _ship("")
{
}

User::User(User const &user)
    : ready(user.ready), _name(user._name), _ship(user._ship)
{
};
