#ifndef ERRORMESSAGES_HPP
#define ERRORMESSAGES_HPP

#include <string>

#ifndef WITH_ERROR_DETAILS
# define WITH_ERROR_DETAILS 0
#endif

namespace ErrorMessages
{
    static const char* const BAD_ARGUMENT_COUNT = "Error: bad number of argument";
    static const char* const EXTRA_NUMS = "Error: extra numbers in the input";
    static const char* const EXTRA_OPERATION = "Error: extra operation in the input";
    static const char* const INVALID_INPUT = "Error: invalid input";

#if WITH_ERROR_DETAILS
    static const std::string EMPTY_STRING_ERROR = "Error: empty string";
    static const std::string NUMBER_TOO_LARGE_ERROR = "Error: number too large";
    static const std::string NOT_ENOUGH_NUMBERS_ERROR = "Error: not enough numbers";
    static const std::string DIVISION_BY_ZERO_ERROR = "Error: division by zero";
    static const std::string INVALID_OPERATOR_ERROR = "Error: invalid operator";
    static const std::string INVALID_TOKEN_ERROR = "Error: invalid token";
    static const std::string EXTRA_NUMBERS_ERROR = "Error: extra numbers in the input";
    static const std::string EXTRA_OPERATION_ERROR = "Error: extra operation in the input";
    static const std::string INVALID_INPUT_ERROR = "Error: invalid input => ";
#else
    static const std::string EMPTY_STRING_ERROR = "Error";
    static const std::string NUMBER_TOO_LARGE_ERROR = "Error";
    static const std::string NOT_ENOUGH_NUMBERS_ERROR = "Error";
    static const std::string DIVISION_BY_ZERO_ERROR = "Error";
    static const std::string INVALID_OPERATOR_ERROR = "Error";
    static const std::string INVALID_TOKEN_ERROR = "Error";
    static const std::string EXTRA_NUMBERS_ERROR = "Error";
    static const std::string EXTRA_OPERATION_ERROR = "Error";
    static const std::string INVALID_INPUT_ERROR = "Error: ";
#endif
}

#endif
