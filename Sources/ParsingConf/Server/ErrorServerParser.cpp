#include <string>
#include "ErrorServerParser.hpp"

ErrorServerParser::ErrorServerParser(std::ostream &os, const std::string &message) noexcept
	: Errors(os, "CoreClient : " + message) {}
