#include <fstream>
#include <iostream>
#include <string>

#include "ErrorAParser.hpp"
#include "AParser.hpp"

AParser::~AParser()
{}

void AParser::LoadFileInMem()
{
	std::ifstream fs(this->GetFilePath());
	std::string tmp;

	if (!fs.is_open())
		throw ErrorAParser(std::cerr, "Could not open file: " + this->GetFilePath());
	while (getline(fs, tmp)) {
		if (tmp.at(0) == '#')
			continue;
		tmp = tmp.substr(0, tmp.length() - 1);
		this->_lines.push_back(tmp);
	}
}

void AParser::LoadFileInMem(std::string filePath)
{
	std::ifstream fs(filePath);
	std::string tmp;

	if (!fs.is_open())
		throw ErrorAParser(std::cerr, "Could not open file: " + this->GetFilePath());
	while (getline(fs, tmp)) {
		if (tmp.at(0) == '#')
			continue;
		tmp = tmp.substr(0, tmp.size());
		this->_lines.push_back(tmp);
	}
}

void AParser::SetFileName(std::string fileName)
{
	this->_fileName = fileName;
}

std::vector<std::string>& AParser::GetLinesRead()
{
	return this->_lines;
}

std::string AParser::GetFileName()
{
	return this->_fileName;
}

std::string AParser::GetFilePath() const
{
	return "";
}

void AParser::SetLineRead(std::vector<std::string> lines)
{
	this->_lines = lines;
}

std::vector<std::string> AParser::SplitString(std::string &line,
						  std::string token)
{
	std::vector<std::string> result;
	std::string tmp;
	bool end = false;
	int first = 0;
	int second = line.find(token);

	while (!end) {
		if (second == std::string::npos) {
			end = true;
		}
		tmp = line.substr(first, second);
		line = line.substr(second + 1);
		second = line.find(token);
		result.push_back(tmp);
	}
	return result;
}
