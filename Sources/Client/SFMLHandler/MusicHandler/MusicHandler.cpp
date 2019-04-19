/*
** EPITECH PROJECT, 2021
** Project: CPP_rtype_2018
** File: MusicHandler.cpp
** File description:
** Handler for music : split SFMLHandler
**
** Created by Alexandre Sachs on 20/12/2018 at 17:02
*/

#include "../SFMLHandler.hpp"

void SFMLHandler::createMusic(std::string const &key, std::string const &filename) {
    if (_musics->find(key) == _musics->end()) {
        _musics->emplace(key, std::make_unique<sf::Music>());
        openMusicFromFile(key, filename);
    }
}

void SFMLHandler::openMusicFromFile(std::string const &key, std::string const &filename) {
    if (_musics->find(key) != _musics->end()) {
        (*_musics)[key]->openFromFile(filename);
    }
}

void SFMLHandler::playMusic(std::string const &key) {
    if (_musics->find(key) != _musics->end()) {
        (*_musics)[key]->stop();
        (*_musics)[key]->play();
    }
}

void SFMLHandler::pauseMusic(std::string const &key) {
    if (_musics->find(key) != _musics->end()) {
        (*_musics)[key]->pause();
    }
}

void SFMLHandler::stopMusic(std::string const &key) {
    if (_musics->find(key) != _musics->end()) {
        (*_musics)[key]->stop();
    }
}

unsigned int SFMLHandler::getMusicChannelCount(std::string const &key) const {
    if (_musics->find(key) != _musics->end()) {
        return (*_musics)[key]->getChannelCount();
    }
    return 0;
}

unsigned int SFMLHandler::getMusicSampleRate(std::string const &key) const {
    if (_musics->find(key) != _musics->end()) {
        return (*_musics)[key]->getSampleRate();
    }
    return 0;
}

enum SoundStatus SFMLHandler::getMusicStatus(std::string const &key) const {
    if (_musics->find(key) != _musics->end()) {
        switch ((*_musics)[key]->getStatus()) {
            case  sf::SoundSource::Status::Stopped:
                return S_STOPPED;
            case  sf::SoundSource::Status::Playing:
                return S_PLAYING;
            case  sf::SoundSource::Status::Paused:
                return S_PAUSED;
            default:
                break;
        }
    }
    return S_UNDEFINED;
}

void SFMLHandler::setMusicLoop(std::string const &key, bool loop) {
    if (_musics->find(key) != _musics->end()) {
        (*_musics)[key]->setLoop(loop);
    }
}

bool SFMLHandler::getMusicLoop(std::string const &key) const {
    if (_musics->find(key) != _musics->end()) {
        return (*_musics)[key]->getLoop();
    }
    return false;
}

void SFMLHandler::setMusicPitch(std::string const &key, float pitch) {
    if (_musics->find(key) != _musics->end()) {
        (*_musics)[key]->setPitch(pitch);
    }
}

void SFMLHandler::setMusicVolume(std::string const &key, float volume) {
    if (_musics->find(key) != _musics->end()) {
        (*_musics)[key]->setVolume(volume);
    }
}

void SFMLHandler::setMusicPosition(std::string const &key, float x, float y, float z) {
    if (_musics->find(key) != _musics->end()) {
        (*_musics)[key]->setPosition(sf::Vector3f(x, y, z));
    }
}

void SFMLHandler::setMusicRelativeToListener(std::string const &key, bool relative) {
    if (_musics->find(key) != _musics->end()) {
        (*_musics)[key]->setRelativeToListener(relative);
    }
}

void SFMLHandler::setMusicMinDistance(std::string const &key, float distance) {
    if (_musics->find(key) != _musics->end()) {
        (*_musics)[key]->setMinDistance(distance);
    }
}

void SFMLHandler::setMusicAttenuation(std::string const &key, float attenuation) {
    if (_musics->find(key) != _musics->end()) {
        (*_musics)[key]->setAttenuation(attenuation);
    }
}

float SFMLHandler::getMusicPitch(std::string const &key) const {
    if (_musics->find(key) != _musics->end()) {
        return (*_musics)[key]->getPitch();
    }
    return 0.0;
}

float SFMLHandler::getMusicVolume(std::string const &key) const {
    if (_musics->find(key) != _musics->end()) {
        return (*_musics)[key]->getVolume();
    }
    return 0.0;
}

float SFMLHandler::getMusicMinDistance(std::string const &key) const {
    if (_musics->find(key) != _musics->end()) {
        return (*_musics)[key]->getMinDistance();
    }
    return 0.0;
}

float SFMLHandler::getMusicAttenuation(std::string const &key) const {
    if (_musics->find(key) != _musics->end()) {
        return (*_musics)[key]->getAttenuation();
    }
    return 0.0;
}

std::shared_ptr<std::unordered_map<std::string, std::unique_ptr<sf::Music>>> SFMLHandler::getMusics() const {
    return _musics;
}