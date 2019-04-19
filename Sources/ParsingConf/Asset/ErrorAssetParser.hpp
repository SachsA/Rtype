#ifndef ERROR_ASSET_PARSER_HPP_
#define ERROR_ASSET_PARSER_HPP_

#include "../../Errors/Errors.hpp"

class ErrorAssetParser: public Errors {
public:
	ErrorAssetParser(std::ostream &os, const std::string &message) noexcept;
	~ErrorAssetParser() noexcept override = default;
};

#endif //ERROR_ASSET_PARSER_HPP_
