#include <string>
#include "ErrorAssetParser.hpp"

ErrorAssetParser::ErrorAssetParser(std::ostream &os, const std::string &message) noexcept
	: Errors(os, "ErrorAssetParsing: " + message) {}
