#include <iostream>
#include <exception>

#ifdef _WIN32
#include <filesystem>
#elif defined (linux)
#include <experimental/filesystem>
#endif

namespace fs = std::experimental::filesystem::v1;

#include "LevelParser.hpp"
#include "ErrorLevelParser.hpp"

LevelParser::LevelParser()
{
	int place = 0;

	for (auto &p : fs::directory_iterator(this->dirPath)) {
		place = GetIdLevel(p.path().u8string());
		if (place == -1)
			throw ErrorLevelParser(std::cerr, "A level can't be negative");
	        this->LoadFileInMem(p.path().u8string());
		this->OrganizeData(place);
		this->SetLineRead({""});
	}
}

LevelParser::~LevelParser()
{}

int LevelParser::GetIdLevel(std::string lvlName)
{

	removePathSuffix(lvlName);

	int id = 0;
	std::string toFind = "level";

	auto startId = lvlName.find(toFind) + toFind.length();
	if (startId != std::string::npos) {
		lvlName = lvlName.substr(startId);
		auto pos = lvlName.find(".");
		if (pos == std::string::npos)
			return -1;
		lvlName = lvlName.substr(0, pos);
	}
	try {
		id = std::stoi(lvlName);
	} catch (std::exception e) {
		throw e;
	}
	return id;
}

std::string LevelParser::GetFilePath() const
{
	return this->dirPath;
}


void LevelParser::removePathSuffix(std::string &fullPath)
{
	auto pos = fullPath.find("/");
	while (pos != std::string::npos) {
		fullPath = fullPath.substr(pos + 1);
		pos = fullPath.find("/");
	}
}

void LevelParser::SetFilePath()
{}

void LevelParser::OrganizeData(int id)
{
	std::list<DataEnemy> list = {};
	auto lines = this->GetLinesRead();
	DataEnemy data{};
	for (auto &l : lines) {
		if (l == "" || l.empty() || l.length() == 0)
			continue;
		std::vector<std::string> splitLines = this->SplitString(l, ";");
		if (CheckSplitString(splitLines)) {
			try {
				data.enemyLib = splitLines.at(0);
				data.nbEntity = std::stoi(splitLines.at(1));
				data.timeUntilSpawn = std::stoi(splitLines.at(2));
			} catch (std::exception e) {
				throw e;
			}
		}
		list.emplace_back(data);
	}
	list.sort();
	this->_lvlData.emplace(std::make_pair(id, list));
}

bool LevelParser::CheckSplitString(std::vector<std::string> splitedString)
{
	bool correct = true;
	if (splitedString.size() != 3) {
		correct = false;
	} else {
		for (int i = 0; i < splitedString.size(); i++) {
			if (splitedString[i] == "") {
				correct = false;
			}
		}
	}
	return correct;
}

std::map<int, std::list<DataEnemy>> LevelParser::GetLvldata() const
{
	return this->_lvlData;
}

static bool operator<(const DataEnemy &data1, const DataEnemy &data2) {
	if (data1.timeUntilSpawn > data2.timeUntilSpawn)
		return false;
	return true;
};
