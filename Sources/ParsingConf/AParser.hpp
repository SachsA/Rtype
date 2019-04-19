#ifndef APARSER_HPP_
#define APARSER_HPP_

#include <string>
#include <vector>

class AParser {
public:
	virtual ~AParser();

	void LoadFileInMem();
	void LoadFileInMem(std::string filePath);
	void SetFileName(std::string fileName);
	virtual void SetFilePath() = 0;
        virtual std::string GetFilePath() const;
	std::vector<std::string>& GetLinesRead();
	std::string GetFileName();
	void SetLineRead(std::vector<std::string> lines);
	std::vector<std::string> SplitString(std::string &line,
							  std::string token);
private:
	std::string _fileName;
	std::vector<std::string> _lines;
};

#endif // APARSER_HPP_
