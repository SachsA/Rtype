/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef SLOTBLUE_HPP
#define SLOTBLUE_HPP

#include "../ASlot.hpp"

class SlotBlue : public ASlot {
public:
    SlotBlue(SFMLHandler const &sfmlHandler);

    SlotBlue(SlotBlue const &) = default;

    ~SlotBlue() override = default;

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

#endif //SLOTBLUE_HPP
