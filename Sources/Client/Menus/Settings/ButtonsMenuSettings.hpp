/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef BUTTONSMENUSETTINGS_HPP
#define BUTTONSMENUSETTINGS_HPP

#include <string>


/**** BUTTON UP ****/
struct ButtonDownMusic {
    static const std::string name() { return "BUTTON_DOWN_MUSIC"; };
    static const std::string nameFocus() { return "BUTTON_DOWN_MUSIC_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_down.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_down_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ButtonDownMusic::sizeX = 67;
const unsigned int ButtonDownMusic::sizeY = 67;
const unsigned int ButtonDownMusic::topX = 891;
const unsigned int ButtonDownMusic::topY = 435;


struct ButtonDownMenus {
    static const std::string name() { return "BUTTON_DOWN_MENUS"; };
    static const std::string nameFocus() { return "BUTTON_DOWN_MENUS_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_down.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_down_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ButtonDownMenus::sizeX = 67;
const unsigned int ButtonDownMenus::sizeY = 67;
const unsigned int ButtonDownMenus::topX = 891;
const unsigned int ButtonDownMenus::topY = 611;


struct ButtonDownGame {
    static const std::string name() { return "BUTTON_DOWN_GAME"; };
    static const std::string nameFocus() { return "BUTTON_DOWN_GAME_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_down.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_down_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ButtonDownGame::sizeX = 67;
const unsigned int ButtonDownGame::sizeY = 67;
const unsigned int ButtonDownGame::topX = 891;
const unsigned int ButtonDownGame::topY = 788;


/**** BUTTON UP ****/
struct ButtonUpMusic {
    static const std::string name() { return "BUTTON_UP_MUSIC"; };
    static const std::string nameFocus() { return "BUTTON_UP_MUSIC_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_up.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_up_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ButtonUpMusic::sizeX = 67;
const unsigned int ButtonUpMusic::sizeY = 67;
const unsigned int ButtonUpMusic::topX = 1291;
const unsigned int ButtonUpMusic::topY = 435;


struct ButtonUpMenus {
    static const std::string name() { return "BUTTON_UP_MENUS"; };
    static const std::string nameFocus() { return "BUTTON_UP_MENUS_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_up.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_up_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ButtonUpMenus::sizeX = 67;
const unsigned int ButtonUpMenus::sizeY = 67;
const unsigned int ButtonUpMenus::topX = 1291;
const unsigned int ButtonUpMenus::topY = 611;


struct ButtonUpGame {
    static const std::string name() { return "BUTTON_UP_GAME"; };
    static const std::string nameFocus() { return "BUTTON_UP_GAME_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_up.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_up_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ButtonUpGame::sizeX = 67;
const unsigned int ButtonUpGame::sizeY = 67;
const unsigned int ButtonUpGame::topX = 1291;
const unsigned int ButtonUpGame::topY = 788;


/**** SOUND ICON ****/
struct SoundIconMusic {
    static const std::string name() { return "SOUND_ICON_MUSIC"; };
    static const std::string nameFocus() { return "SOUND_ICON_MUSIC_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_sound.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_mute.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int SoundIconMusic::sizeX = 76;
const unsigned int SoundIconMusic::sizeY = 76;
const unsigned int SoundIconMusic::topX = 652;
const unsigned int SoundIconMusic::topY = 430;


struct SoundIconMenus {
    static const std::string name() { return "SOUND_ICON_MENUS"; };
    static const std::string nameFocus() { return "SOUND_ICON_MENUS_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_sound.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_mute.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int SoundIconMenus::sizeX = 76;
const unsigned int SoundIconMenus::sizeY = 76;
const unsigned int SoundIconMenus::topX = 652;
const unsigned int SoundIconMenus::topY = 609;


struct SoundIconGame {
    static const std::string name() { return "SOUND_ICON_GAME"; };
    static const std::string nameFocus() { return "SOUND_ICON_GAME_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_sound.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_mute.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int SoundIconGame::sizeX = 76;
const unsigned int SoundIconGame::sizeY = 76;
const unsigned int SoundIconGame::topX = 652;
const unsigned int SoundIconGame::topY = 782;


/**** VOLUME TEXT ****/
struct TextVolumeMusic {
    static const std::string name() { return "INPUT_VOLUME_MUSIC"; };
    static const std::string nameFocus() { return ""; };
    static const std::string path() { return ""; };
    static const std::string pathFocus() { return ""; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int TextVolumeMusic::sizeX = 220;
const unsigned int TextVolumeMusic::sizeY = 63;
const unsigned int TextVolumeMusic::topX = 1015;
const unsigned int TextVolumeMusic::topY = 438;


struct TextVolumeMenus {
    static const std::string name() { return "INPUT_VOLUME_MENUS"; };
    static const std::string nameFocus() { return ""; };
    static const std::string path() { return ""; };
    static const std::string pathFocus() { return ""; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int TextVolumeMenus::sizeX = 220;
const unsigned int TextVolumeMenus::sizeY = 63;
const unsigned int TextVolumeMenus::topX = 1015;
const unsigned int TextVolumeMenus::topY = 613;


struct TextVolumeGame {
    static const std::string name() { return "INPUT_VOLUME_GAME"; };
    static const std::string nameFocus() { return ""; };
    static const std::string path() { return ""; };
    static const std::string pathFocus() { return ""; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int TextVolumeGame::sizeX = 220;
const unsigned int TextVolumeGame::sizeY = 63;
const unsigned int TextVolumeGame::topX = 1015;
const unsigned int TextVolumeGame::topY = 790;


/**** BUTTON CLOSE ****/
struct ButtonCloseSettings {
    static const std::string name() { return "BUTTON_CLOSE"; };
    static const std::string nameFocus() { return "BUTTON_CLOSE_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/button_close.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/button_close_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ButtonCloseSettings::sizeX = 59;
const unsigned int ButtonCloseSettings::sizeY = 59;
const unsigned int ButtonCloseSettings::topX = 1732;
const unsigned int ButtonCloseSettings::topY = 94;


/**** EXIT GAME ****/
struct ExitGameSettings {
    static const std::string name() { return "EXIT_GAME"; };
    static const std::string nameFocus() { return "EXIT_GAME_FOCUS"; };
    static const std::string path() { return "../Ressources/Menus/Assets/exit.png"; };
    static const std::string pathFocus() { return "../Ressources/Menus/Assets/exit_focus.png"; };
    static const unsigned int sizeX;
    static const unsigned int sizeY;
    static const unsigned int topX;
    static const unsigned int topY;
};
const unsigned int ExitGameSettings::sizeX = 59;
const unsigned int ExitGameSettings::sizeY = 59;
const unsigned int ExitGameSettings::topX = 36;
const unsigned int ExitGameSettings::topY = 939;


#endif //BUTTONSMENUSETTINGS_HPP