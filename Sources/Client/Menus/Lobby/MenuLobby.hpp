/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef MENULOBBY_HPP
#define MENULOBBY_HPP

#include <chrono>
#include "../AMenu.hpp"
#include "../../Components/Slots/ASlot.hpp"
#include "../../../Communication/CommunicationTCP/CommunicationTCPClient/CommunicationTCPClient.hpp"

enum SlotState {
    SLOT_BLUE,
    SLOT_RED,
    SLOT_YELLOW,
    SLOT_GREEN
};


class MenuLobby: public AMenu {
public:
    MenuLobby(SFMLHandler const &sfmlHandler, std::string &userName, std::string &serverName,
            CommunicationTCPClient &server, std::vector<std::string> &listServer, CommunicationTCPClient &lobbyTCP);
    MenuLobby(MenuLobby const &) = default;
    ~MenuLobby() override = default;
    InstanceStatus launch(enum Event const &event, InstanceStatus const &last) override;

private:
    /* FONCTIONS */
    void draw();
    void drawButtonReady();
    void drawButtonCancel();
    void drawButtonPlus();
    void drawSlotsUsername();

    InstanceStatus manageEvent(enum Event const &event, InstanceStatus const &last);
    InstanceStatus buttonPressed(Vector2D<int> const &position);
    InstanceStatus buttonReleased(Vector2D<int> const &position, InstanceStatus const &last);
    InstanceStatus slotPressed(Vector2D<int> const &position);
    InstanceStatus slotReleased(Vector2D<int> const &position);

    void initializeAssets();
    void validAsset(std::string const &name, std::string const &path, Vector2D<unsigned int> const &position, Vector2D<unsigned int> const &size);
    void validButton(Vector2D<std::string> const &names, Vector2D<std::string> const &paths, Vector2D<unsigned int> const &position, Vector2D<unsigned int> const &size);

    void createButton(Vector2D<std::string> const &names, Vector2D<std::string> const &paths, Vector2D<unsigned int> const &position, Vector2D<unsigned int> const &size);
    void setButtonInstance(std::string const &name, InstanceStatus const &status);

    void manageSlot(std::vector<std::string> const &slots);
    InstanceStatus manageCommand(CommandType const &cmd, unsigned int const &slot);
    void setSlotInfos(SlotState const &state, std::string const &infos);
    bool isUpdateTime(int fpms);

    InstanceStatus clearServerName(InstanceStatus const &instance, InstanceStatus const &last);
    InstanceStatus getSlotStatus();
    InstanceStatus sendJoinServer();
    InstanceStatus sendJoinSlot(unsigned int const &slot);
    InstanceStatus sendLeaveSlot(unsigned int const &slot);
    InstanceStatus sendPlayerReady(unsigned int const &slot);
    InstanceStatus sendPlayerNotReady(unsigned int const &slot);
    InstanceStatus sendLeaveInstance();
    InstanceStatus returnToLogin();
    void lockSlotBlue(bool const &lock);
    void lockSlotRed(bool const &lock);
    void lockSlotYellow(bool const &lock);
    void lockSlotGreen(bool const &lock);

    int getUserSlot();

    /* VARIABLES */
    std::chrono::time_point<std::chrono::system_clock> _time;
    std::vector<std::string> &_listServer;
    std::unordered_map<std::string, Button> _buttons;
    CommunicationTCPClient &_server;
    CommunicationTCPClient &_lobbyTCP;
    std::unordered_map<SlotState, std::unique_ptr<ASlot>> _slots;
};

#endif //MENUPAUSE_HPP