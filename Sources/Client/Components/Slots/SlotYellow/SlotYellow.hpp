/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef SLOTYELLOW_HPP
#define SLOTYELLOW_HPP

#include "../ASlot.hpp"

class SlotYellow : public ASlot {
public:
    SlotYellow(SFMLHandler const &sfmlHandler);

    SlotYellow(SlotYellow const &) = default;

    ~SlotYellow() override = default;

private:
    void createButtonReady();

    void createButtonPlus();

    void createButtonCancel();

    void createSlotUsername();

    void createShipSection();

    void validButton(Vector2D<std::string> const &paths, Vector2D<unsigned int> const &position,
                     Vector2D<unsigned int> const &size);

    void validAsset(std::string const &reference);

};

#endif //SLOTYELLOW_HPP
