#ifndef ERROR_SERVER_PARSER_HPP_
#define ERROR_SERVER_PARSER_HPP_

#include "../../Errors/Errors.hpp"

class ErrorServerParser: public Errors {
public:
	ErrorServerParser(std::ostream &os, const std::string &message) noexcept;
	~ErrorServerParser() noexcept override = default;
};

#endif //ERROR_SERVER_PARSER_HPP_
