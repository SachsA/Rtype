/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by kellian CIPIERRE,
*/

#ifndef CPP_RTYPE_2018_USER_HPP
#define CPP_RTYPE_2018_USER_HPP

#include <string>
#include <memory>
#include <chrono>
#include "../GameEngine/Entities/AEntity.hpp"

class User {
public :
    User(std::string const &name);
    ~User() = default;
    User(User const &user);

public:
    bool ready;
    std::string _name;
    std::string _ship;
    std::chrono::time_point<std::chrono::system_clock> _lastAliveSign;
};

#endif //CPP_RTYPE_2018_USER_HPP
