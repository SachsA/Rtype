#include <iostream>

#include "ServerConfParsing.hpp"
#include "ErrorServerParser.hpp"
ServerParser::ServerParser()
{
	this->SetFilePath();
	this->LoadFileInMem(this->_filePath);
	this->_setIpAddress();
}

void ServerParser::SetFilePath()
{
	this->_filePath = this->_serverConfPath;
}

std::string ServerParser::GetFilePath() const
{
	return this->_filePath;
}

void ServerParser::_setIpAddress()
{
	auto lines = this->GetLinesRead();
	if (lines.size() != 2) {
		throw ErrorServerParser(std::cerr, "File is not well formated and couldn't be read");
	}
	if (lines.at(FileIndex::Data).at(0) != 'i' && lines.at(FileIndex::Data).at(1) != 'p') {
		throw ErrorServerParser(std::cerr, "File is not well formated and couldn't be read");;
	}
	auto data = lines.at(1);
	auto posDelim = data.find(":");
	this->_ipAddress = data.substr(posDelim + 1);
}

std::string ServerParser::GetIpAddress() const
{
	return this->_ipAddress;
}
