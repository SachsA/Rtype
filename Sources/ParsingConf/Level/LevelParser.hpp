#ifndef LEVEL_PARSER_HPP
#define LEVEL_PARSER_HPP

#include <map>
#include <list>
#include "../AParser.hpp"

struct DataEnemy {
	int timeUntilSpawn;
	std::string enemyLib;
	int nbEntity;
};

class LevelParser: public AParser {
public:
	LevelParser();
	~LevelParser();
	void SetFilePath();
	int GetIdLevel(std::string levelName);
	std::string GetFilePath() const;
	std::map<int, std::list<DataEnemy>> GetLvldata() const;
	void OrganizeData(int id);
	bool CheckSplitString(std::vector<std::string> splitedString);
	const std::string dirPath = "../Ressources/ConfigFile/Level/";
private:
	void removePathSuffix(std::string &fullPath);
	std::map<int, std::list<DataEnemy>> _lvlData;

};

#endif // LEVEL_PARSER_HPP
