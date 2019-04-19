/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include <string>
#include "ErrorsCoreClient.hpp"

ErrorsCoreClient::ErrorsCoreClient(std::ostream &os, const std::string &message) noexcept
        : Errors(os, "CoreClient : " + message) {}