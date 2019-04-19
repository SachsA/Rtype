#include <string>
#include "../Errors/Errors.hpp"
#include "ErrorAParser.hpp"

ErrorAParser::ErrorAParser(std::ostream &os, const std::string &message) noexcept
	: Errors(os, "ErrorAParser: " + message) {}
