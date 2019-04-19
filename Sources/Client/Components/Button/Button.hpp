/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include "../../../Template/Vector2D/Vector2D.hpp"
#include "../../Menus/AMenu.hpp"

class Button {
public:
    Button(Vector2D<std::string> const &names, Vector2D<unsigned int> const &position,
            Vector2D<unsigned int> const &size);
    Button() = default;
    ~Button();

    bool isSelected(Vector2D<int> const &position);

    void setPaths(Vector2D<std::string> const &paths);
    void setInstance(InstanceStatus const &status);
    void setActivated(std::string const &name, std::string const &path);

    std::string const &getName() const;
    std::string const &getNameFocus() const;
    std::string const &getNameActivated() const;
    std::string const &getPath() const;
    std::string const &getPathFocus() const;
    std::string const &getPathActivated() const;
    Vector2D<unsigned int> const &getPosition() const;
    Vector2D<unsigned int> const &getSize() const;
    InstanceStatus const &getInstance() const;

private:

    // VARIABLES //
    std::string _name;
    std::string _nameFocus;
    std::string _nameActivated;
    std::string _path;
    std::string _pathFocus;
    std::string _pathActivated;
    InstanceStatus _status;
    Vector2D<unsigned int> _position;
    Vector2D<unsigned int> _size;
};

#endif //BUTTON_HPP
