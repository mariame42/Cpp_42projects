#ifndef ERRORMESSAGES_HPP
#define ERRORMESSAGES_HPP

#include <string>

/*
    ErrorMessages namespace
    This namespace is used to store the error messages
    it is used to print the error messages
*/

namespace ErrorMessages
{
    // Argument errors
    static const char* const BAD_ARGUMENT_COUNT = "Error: bad number of arguments";

#if WITH_ERROR_DETAILS
    static const char* const INVALID_INPUT = "Error: invalid input";
    static const char* const NEGATIVE_NUM = "Error: negative number is not allowed";
    static const char* const NUMBER_TOO_LARGE = "Error: number too large";
#else
    static const char* const INVALID_INPUT = "Error";
    static const char* const NEGATIVE_NUM = "Error";
    static const char* const NUMBER_TOO_LARGE = "Error";
#endif
}

#endif
