/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef SFMLHANDLER_HPP
#define SFMLHANDLER_HPP

#include <memory>
#include <iostream>
#include <unordered_map>

#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/VideoMode.hpp>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Shader.hpp>

#include "../Constants/Constants.hpp"
#include "../Components/Color/Color.hpp"
#include "../../Template/Vector2D/Vector2D.hpp"


enum Event {
    E_KEY_UP,
    E_KEY_DOWN,
    E_KEY_LEFT,
    E_KEY_RIGHT,
    E_KEY_ESCAPE,
    E_KEY_SPACE,
    E_KEY_A,
    E_KEY_Z,
    E_KEY_E,
    E_KEY_R,
    E_KEY_Q,
    E_KEY_S,
    E_UNDEFINED,
    E_MOUSE_RELEASED,
    E_MOUSE_PRESSED,
    E_TEXT_ENTERED,
    E_CLOSE
};

enum SoundStatus {
    S_STOPPED,
    S_PLAYING,
    S_PAUSED,
    S_UNDEFINED
};


class SFMLHandler {
public:
    SFMLHandler();
    SFMLHandler(SFMLHandler const &);
    ~SFMLHandler() = default;
    SFMLHandler& operator=(SFMLHandler const &);
    bool validColorValue(unsigned int value);

    enum Event manageWindowEvent();
    enum Event getKeyEvent();
    void setMousePosition(Vector2D<int> const &position);
    Vector2D<int> const getMousePressedPosition();
    std::shared_ptr<sf::Event> getEvent() const;
    std::string getTextEntered();

    void createFontFromFile(std::string const &filename);
    float getFontLineSpacing(unsigned int characterSize) const;
    float getFontUnderlinePosition(unsigned int characterSize) const;
    float getFontUnderlineThickness(unsigned int characterSize) const;
    std::shared_ptr<sf::Font> getFont() const;

    void createMusic(std::string const &key, std::string const &filename);
    void openMusicFromFile(std::string const &key, std::string const &filename);
    void playMusic(std::string const &key);
    void pauseMusic(std::string const &key);
    void stopMusic(std::string const &key);
    unsigned int getMusicChannelCount(std::string const &key) const;
    unsigned int getMusicSampleRate(std::string const &key) const;
    enum SoundStatus getMusicStatus(std::string const &key) const;
    void setMusicLoop(std::string const &key, bool loop);
    bool getMusicLoop(std::string const &key) const;
    void setMusicPitch(std::string const &key, float pitch);
    void setMusicVolume(std::string const &key, float volume);
    void setMusicPosition(std::string const &key, float x, float y, float z);
    void setMusicRelativeToListener(std::string const &key, bool relative);
    void setMusicMinDistance(std::string const &key, float distance);
    void setMusicAttenuation(std::string const &key, float attenuation);
    float getMusicPitch(std::string const &key) const;
    float getMusicVolume(std::string const &key) const;
    float getMusicMinDistance(std::string const &key) const;
    float getMusicAttenuation(std::string const &key) const;
    std::shared_ptr<std::unordered_map<std::string, std::unique_ptr<sf::Music>>> getMusics() const;


    void createSprite(std::string const &key);
    void createSprite(std::string const &key, Vector2D<unsigned int> const &position, Vector2D<unsigned int> const &size);
    void setTexturetoSprite(std::string const &keyS, std::string const &keyT);
    void setSpritePosition(std::string const &key, float x, float y);
    void setSpriteColor(std::string const &key, Color const &color);
    void setSpriteRotation(std::string const &key, float angle);
    void setSpriteScale(std::string const &key, float factorX, float factorY);
    void setSpriteOrigin(std::string const &key, float x, float y);
    void moveSprite(std::string const &key, float offsetX, float offsetY);
    void rotateSprite(std::string const &key, float angle);
    void scaleSprite(std::string const &key, float factorX, float factorY);
    void drawSprite(std::string const &key);
	void drawSpriteWithShader(std::string const &key);
	void loadShaderFromMemory(std::string const &vertexShader);
	void setShaderUniform(std::string const &params, float const &time);
	float getClockElapsedTime();
	void resetClock();
    std::unordered_map<std::string, sf::Sprite> getSprites() const;

    void createText(std::string const &key);
    void setTextRotation(std::string const &key, float angle);
    void setTextScale(std::string const &key, float factorX, float factorY);
    void setTextOrigin(std::string const &key, float x, float y);
    void moveText(std::string const &key, float offsetX, float offsetY);
    void rotateText(std::string const &key, float angle);
    void scaleText(std::string const &key, float factorX, float factorY);
    std::string const getTextString(std::string const &key);
    unsigned int getTextCharacterSize(std::string const &key);
    float getTextLetterSpacing(std::string const &key);
    float getTextLineSpacing(std::string const &key);
    float getTextOutlineThickness(std::string const &key);
    void setTextString(std::string const &key, std::string const &string);
    void setTextCharacterSize(std::string const &key, unsigned int size);
    void setTextLineSpacing(std::string const &key, float factor);
    void setTextLetterSpacing(std::string const &key, float factor);
    void setTextFillColor(std::string const &key, Color const &color);
    void setTextOutlineColor(std::string const &key, Color const &color);
    void setTextOutlineThickness(std::string const &key, float thickness);
    void drawText(std::string const &key, Vector2D<unsigned int> const &position,
                  Vector2D<unsigned int> const &size);
    void setTextPosition(std::string const &key, float x, float y);
    Vector2D<float> getTextLocalBounds(std::string const &key);

    void createTexture(std::string const &key, unsigned int width, unsigned int height);
    void createTextureFromFile(std::string const &key, const std::string &filename, unsigned int width, unsigned int height);
    void updateTexture(std::string const &key);
    void updateTexture(std::string const &key, unsigned int x, unsigned int y);
    void setTextureSmooth(std::string const &key, bool smooth);
    void setTextureRepeated(std::string const &key, bool repeated);
    std::unordered_map<std::string, sf::Texture> getTextures() const;

    void createWindow(unsigned int width, unsigned int height, const std::string &title);
    enum Event closeEventWindow();
    void displayWindow();
    void clearWindow();
    bool isOpenWindow();
    bool listenEvent();
    void manageWindowPosition(unsigned int posX, unsigned int posY);
    void setWindowPosition(unsigned int posX, unsigned int posY);
    void setWindowSize(unsigned int posX, unsigned int posY);
    void setWindowTitle(const std::string &title);
    void setWindowCursorVisible(bool visible);
    std::shared_ptr<sf::RenderWindow> getWindow() const;



private:
	sf::Clock _clock;
	sf::Shader _shader;
    sf::RectangleShape _cursor;
    std::shared_ptr<sf::Font> _font;
    std::shared_ptr<sf::Event> _event;
    std::shared_ptr<sf::RenderWindow> _window;
    std::unordered_map<std::string, sf::Texture> _textures;
    std::unordered_map<std::string, sf::Sprite> _sprites;
    std::shared_ptr<std::unordered_map<std::string, std::unique_ptr<sf::Music>>> _musics;
    std::unordered_map<std::string, sf::Text> _texts;
};

#endif //SFMLHANDLER_HPP
