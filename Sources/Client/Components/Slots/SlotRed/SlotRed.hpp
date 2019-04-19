/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef SLOTRED_HPP
#define SLOTRED_HPP

#include "../ASlot.hpp"

class SlotRed : public ASlot {
public:
    SlotRed(SFMLHandler const &sfmlHandler);

    SlotRed(SlotRed const &) = default;

    ~SlotRed() override = default;

private:
    void createButtonReady();

    void createButtonPlus();

    void createButtonCancel();

    void createSlotUsername();

    void createShipSection();

    void validButton(Vector2D<std::string> const &paths, Vector2D<unsigned int> const &position,
                     Vector2D<unsigned int> const &size);

    void validAsset(std::string const &path);

};

#endif //SLOTRED_HPP
