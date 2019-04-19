/*
** EPITECH PROJECT, 2021
** Project: CPP_rtype_2018
** File: ErrorsSocketUdpClient.cpp
** File description:
** Errors file for ErrorsSocketUdpClient, inherit from Errors class
**
** Created by Alexandre Sachs on 19/11/18 at 22:32
*/

#include <string>
#include "../../../Errors/Errors.hpp"
#include "ErrorsSocket.hpp"

ErrorsSocket::ErrorsSocket(std::ostream &os, const std::string &message) noexcept
        : Errors(os, message)
{}