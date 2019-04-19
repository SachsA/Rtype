#include <iostream>
#include "../AParser.hpp"
#include "AssetParser.hpp"
#include "ErrorAssetParser.hpp"

AssetParser::AssetParser(std::string fileName)
{
	this->SetFileName(fileName);
	this->SetFilePath();
	this->LoadFileInMem();
	this->_lines = this->GetLinesRead();

	this->FillData();
}

AssetParser::~AssetParser()
{}

std::string AssetParser::GetFilePath() const
{
	return this->_filePath;
}

void AssetParser::SetFilePath()
{
	this->_filePath = this->_assetPathPrefix + this->GetFileName() + this->_assetPathSufix;
}

void AssetParser::_removeReadedLines()
{
	if (this->_lines.size() == 0)
		throw ErrorAssetParser(std::cerr, "Impossible to delete memory");
	int i = 0;
	auto itBeg = this->_lines.begin();
	while (this->_lines.size() > 0 && this->_lines.at(0).size() != 0) {
		this->_lines.erase(itBeg);
	}
	if (this->_lines.size() > 0)
		this->_lines.erase(itBeg);
}

void AssetParser::FillData()
{
	SimpleData data;
	AssetData uniqueData;
	while (this->_lines.size() > 0) {
		std::string assetName = this->_lines.at(AssetOrder::AssetTitle);
		data.TopLeftX = this->_extractData(this->_lines.at(AssetOrder::TopLeftXValue));
		data.TopLeftY = this->_extractData(this->_lines.at(AssetOrder::TopLeftYValue));
		data.BottomLeftX = this->_extractData(this->_lines.at(AssetOrder::BottomLeftXValue));
		data.BottomLeftY = this->_extractData(this->_lines.at(AssetOrder::BottomLeftYValue));
		data.TopRightX = this->_extractData(this->_lines.at(AssetOrder::TopRightXValue));
		data.TopRightY = this->_extractData(this->_lines.at(AssetOrder::TopRightYValue));
		data.BottomRightX = this->_extractData(this->_lines.at(AssetOrder::BottomRightXValue));
		data.BottomRightY = this->_extractData(this->_lines.at(AssetOrder::BottomRightYValue));
		data.SizeX = this->_extractData(this->_lines.at(AssetOrder::SizeXValue));
		data.SizeY = this->_extractData(this->_lines.at(AssetOrder::SizeYValue));

		this->_fillElement(uniqueData, data);
		this->_addElement(assetName, uniqueData);
		this->_removeReadedLines();
	}
}

void AssetParser::_fillElement(AssetData &mainObject, SimpleData data)
{
	this->_setValue(mainObject.topLeftCoord, data.TopLeftX, data.TopLeftY);
	this->_setValue(mainObject.bottomLeftCoord, data.BottomLeftX, data.BottomLeftY);
	this->_setValue(mainObject.topRightCoord, data.TopRightX, data.TopRightY);
	this->_setValue(mainObject.bottomRightCoord, data.BottomRightX, data.BottomRightY);
	this->_setValue(mainObject.imgSize, data.TopRightX, data.TopRightY);
}

void AssetParser::_addElement(const std::string assetName,
			      const AssetData &data)
{
	this->_assetsCoords.emplace(std::make_pair(assetName, data));
}

void AssetParser::_setValue(Vector2D<unsigned int> &container,
			    const unsigned int x, const unsigned int y)
{
	container.x = x;
	container.y = y;
}

unsigned int AssetParser::_extractData(std::string fullData)
{
	auto pos = fullData.find(":");
	if (pos == std::string::npos)
		throw ErrorAssetParser(std::cerr, "Could not read from file");
	unsigned int value = 0;
	try {
		auto pos = fullData.find(":");
		value = std::stoi(fullData.substr(pos + 1));
	} catch (std::exception e) {
		throw e;
	}
	return value;
}
