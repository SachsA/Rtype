#ifndef ASSET_PARSER_HPP
#define ASSET_PARSER_HPP

#include <unordered_map>
#include "../AParser.hpp"
#include "../../Template/Vector2D/Vector2D.hpp"

enum AssetOrder {
	AssetTitle,
	TopLeftTitle,
	TopLeftXValue,
	TopLeftYValue,
	BottomLeftTitle,
	BottomLeftXValue,
	BottomLeftYValue,
	TopRigthTitle,
	TopRightXValue,
	TopRightYValue,
	BottomRightTitle,
	BottomRightXValue,
	BottomRightYValue,
	SizeTitle,
	SizeXValue,
	SizeYValue,
};

struct SimpleData {
	unsigned int TopLeftX;
	unsigned int TopLeftY;
	unsigned int BottomLeftX;
	unsigned int BottomLeftY;
	unsigned int TopRightX;
	unsigned int TopRightY;
	unsigned int BottomRightX;
	unsigned int BottomRightY;
	unsigned int SizeX;
	unsigned int SizeY;
};

struct AssetData {
	Vector2D<unsigned int> topLeftCoord;
	Vector2D<unsigned int> bottomLeftCoord;
	Vector2D<unsigned int> topRightCoord;
	Vector2D<unsigned int> bottomRightCoord;
	Vector2D<unsigned int> imgSize;
};

using AssetPosDataType = std::unordered_map<std::string, AssetData>;

class AssetParser: public AParser {
public:
	AssetParser(std::string fileName);
	~AssetParser();
	void SetFilePath();
	std::string GetFilePath() const;
	void FillData();
	const std::string _assetPathSufix =  ".cfg";
	const std::string _assetPathPrefix = "../Ressources/ConfigFile/AssetConf/";
private:
	void _removeReadedLines();
	void _addElement(AssetPosDataType &data, std::string assetName);
	unsigned int _extractData(std::string fullData);
	void _fillElement(AssetData &mainObject, SimpleData data);
	void _setValue(Vector2D<unsigned int> &container, const unsigned int x, const unsigned int y);
	void _addElement(const std::string assetName, const AssetData &data);
	std::string _filePath;
	AssetPosDataType _assetsCoords;
	std::vector<std::string> _lines;
};

#endif // PARSER_HPP
