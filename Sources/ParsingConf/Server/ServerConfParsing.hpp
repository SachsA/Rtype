#ifndef SERVER_CONF_PARSING_HPP
#define SERVER_CONF_PARSING_HPP

#include "../AParser.hpp"

enum FileIndex {
	Title,
	Data,
};

class ServerParser: public AParser {
public:
	ServerParser();
	~ServerParser() = default;
	void SetFilePath();
	std::string GetFilePath() const;
	std::string GetIpAddress() const;
private:
	void _setIpAddress();

	const std::string _serverConfPath = "../Ressources/ConfigFile/ServerConf/Server.cfg";
	std::string _filePath;
	std::string _ipAddress;
};

#endif // SERVER_CONF_PARSING_HPP
