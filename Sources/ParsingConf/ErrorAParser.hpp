#ifndef ERROR_APARSER_HPP_
#define ERROR_APARSER_HPP_

#include "../Errors/Errors.hpp"

class ErrorAParser: public Errors {
public:
	ErrorAParser(std::ostream &os, const std::string &message) noexcept;
	~ErrorAParser() noexcept override = default;
};

#endif //ERROR_APARSER_HPP_
