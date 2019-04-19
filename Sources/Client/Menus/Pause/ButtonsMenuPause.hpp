/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef BUTTONSMENUPAUSE_HPP
#define BUTTONSMENUPAUSE_HPP

#include <string>

/**** BUTTON RESUME ****/
struct ButtonResumePause {
    static const std::string name() { return "BUTTON_RESUME"; };
    static const std::string nameFocus() { return "BUTTON_RESUME_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_resume.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_resume_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ButtonResumePause::sizeX = 480;
const unsigned int ButtonResumePause::sizeY = 113;
const unsigned int ButtonResumePause::topX = 722;
const unsigned int ButtonResumePause::topY = 391;


/**** BUTTON LEAVE ****/
struct ButtonLeavePause {
    static const std::string name() { return "BUTTON_LEAVE"; };
    static const std::string nameFocus() { return "BUTTON_LEAVE_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_leave.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_leave_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ButtonLeavePause::sizeX = 480;
const unsigned int ButtonLeavePause::sizeY = 113;
const unsigned int ButtonLeavePause::topX = 722;
const unsigned int ButtonLeavePause::topY = 559;


/**** BUTTON SETTINGS ****/
struct ButtonSettingsPause {
    static const std::string name() { return "BUTTON_SETTINGS"; };
    static const std::string nameFocus() { return "BUTTON_SETTINGS_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_settings.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_settings_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ButtonSettingsPause::sizeX = 480;
const unsigned int ButtonSettingsPause::sizeY = 111;
const unsigned int ButtonSettingsPause::topX = 722;
const unsigned int ButtonSettingsPause::topY = 727;

#endif //BUTTONSMENUPAUSE_HPP
