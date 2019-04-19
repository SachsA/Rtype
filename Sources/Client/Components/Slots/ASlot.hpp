/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef ASLOT_HPP
#define ASLOT_HPP

#include "../Button/Button.hpp"
#include "../../../Commands/CommandType/CommandType.hpp"

class ASlot {
public:
    explicit ASlot(SFMLHandler const &sfmlHandler);
    virtual ~ASlot() = default;

    Button const &getButtonReady() const;
    Button const &getButtonCancel() const;
    Button const &getButtonPlus() const;
    std::string const &getPlayerText() const;
    std::string const &getPlayerName() const;
    Vector2D<unsigned int> const &getPlayerPosition() const;
    Vector2D<unsigned int> const &getPlayerSize() const;
    bool const &getisReady() const;
    bool const &getisOccuped() const;
    bool const &getisLocked() const;
    unsigned int const &getState() const;
    std::string const &getShip() const;


    void setPlayerText(std::string const &name);
    void setShip(std::string const &ship);
    void setPlayerName(std::string const &name);
    void setisReady(bool const &isReady);
    void setisOccuped(bool const &isOccuped);
    void setisLocked(bool const &isLocked);

    void drawReady();
    void drawPlus();
    void drawCancel();
    void drawPlayerName();

    void isPressed(Vector2D<int> const &position);
    bool isReleased(Vector2D<int> const &position);
    InstanceStatus getReleased(Vector2D<int> const &position);
    CommandType commandReleased(Vector2D<int> const &position);

protected:
    Button _ready;
    Button _cancel;
    Button _plus;

    std::string _ship;

    std::string _playerName;

    std::string _playerText;
    Vector2D<unsigned int> _playerPos;
    Vector2D<unsigned int> _playerSize;

    SFMLHandler _sfmlHandler;

    bool _isOccuped;
    bool _isReady;
    bool _isLocked;

    unsigned int _state;

    bool isReadySelected(Vector2D<int> const &position);
    bool isPlusSelected(Vector2D<int> const &position);
    bool isCancelSelected(Vector2D<int> const &position);
};

#endif //ASLOT_HPP
