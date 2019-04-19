/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#ifndef AENTITY_CLIENT_HPP
#define AENTITY_CLIENT_HPP

#include <string>
#include "../../Template/Vector2D/Vector2D.hpp"
#include "../Constants/Sounds.hpp"

class AEntityClient {
public:
	explicit AEntityClient(std::string const &type);
	~AEntityClient() = default;
	std::string const &getAssetPath() const;
	Vector2D<unsigned int> const &getPosition() const;
	Vector2D<unsigned int> const &getSize() const;
	std::string const &getSoundName() const;
	std::string const &getType() const;
	void setType(std::string const &type);
	void setAssetPath(std::string const &assetPath);
	void setPosition(unsigned int const &topX, unsigned int const &topY);
	void setSize(unsigned int const &sizeX, unsigned int const &sizeY);
	void setSoundName(std::string const &name);

private:
	std::string _type;
	std::string _assetPath;
	std::string _soundName;
	Vector2D<unsigned int> _position;
	Vector2D<unsigned int> _size;

	void validPath(std::string const &path);
};

#endif //AENTITY_CLIENT_HPP
