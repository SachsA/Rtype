#include <string>
#include "../../Errors/Errors.hpp"
#include "ErrorLevelParser.hpp"

ErrorLevelParser::ErrorLevelParser(std::ostream &os, const std::string &message) noexcept
	: Errors(os, "ErrorLevelParser: " + message) {}
