#ifndef ERROR_LEVEL_PARSER_HPP_
#define ERROR_LEVEL_PARSER_HPP_

#include "../../Errors/Errors.hpp"

class ErrorLevelParser: public Errors {
public:
	ErrorLevelParser(std::ostream &os, const std::string &message) noexcept;
	~ErrorLevelParser() noexcept override = default;
};

#endif //ERROR_LEVEL_PARSER_HPP_
