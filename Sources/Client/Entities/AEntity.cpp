/*
** EPITECH PROJECT, 2021
** CPP_rtype_2018
** File description:
** Created by Thomas BLENEAU
*/

#include <iostream>
#include <fstream>
#include "AEntity.hpp"
#include "ErrorsEntityClient.hpp"

AEntityClient::AEntityClient(std::string const &type) : _type(type)
{}

std::string const &AEntityClient::getType() const
{
	return this->_type;
}

std::string const &AEntityClient::getAssetPath() const
{
	return this->_assetPath;
}

Vector2D<unsigned int> const &AEntityClient::getPosition() const {
	return this->_position;
}

Vector2D<unsigned int> const &AEntityClient::getSize() const
{
	return this->_size;
}

std::string const &AEntityClient::getSoundName() const
{
	return this->_soundName;
}

void AEntityClient::setType(std::string const &type)
{
	this->_type = type;
}

void AEntityClient::setAssetPath(std::string const &assetPath)
{
    validPath(assetPath);
	this->_assetPath = assetPath;
}

void AEntityClient::setPosition(unsigned int const &topX, unsigned int const &topY){
	this->_position = {topX, topY};
}

void AEntityClient::setSize(unsigned int const &sizeX, unsigned int const &sizeY)
{
	this->_size = {sizeX, sizeY};
}

void AEntityClient::setSoundName(std::string const &name)
{
	this->_soundName = name;
}

void AEntityClient::validPath(std::string const &path) {
	std::ifstream infile(path);

	if (!infile.good())
		throw ErrorsEntityClient(std::cerr, "This file '" + path + "' does not exist");
	else
		infile.clear();
}
