/*
** EPITECH PROJECT, 2021
** Project: CPP_rtype_2018
** File: Main.cpp
** File description:
** main function for R-Type Client
**
** Created by Alexandre Sachs on 13/11/18 at 16:10
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFMLHandler/SFMLHandler.hpp"
#include "CoreClient/CoreClient.hpp"

int main()
{
    try {
        CoreClient core;

        core.launchClient();
    } catch (std::exception &e) {
        std::cerr << "Catch exception in client : " << e.what() << std::endl;
    }
    return 0;
}