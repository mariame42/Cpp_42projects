#ifndef ERRORMESSAGES_HPP
#define ERRORMESSAGES_HPP

#include <string>

namespace ErrorMessages
{
    // Argument errors
    static const char* const BAD_ARGUMENT_COUNT = "Error: bad number of argument";

    // File errors
    static const char* const COULD_NOT_OPEN_RATE_FILE = "Error: could not open exchange rate file";
    static const char* const COULD_NOT_OPEN_INPUT_FILE = "Error: could not open input file";

    // Header errors
    static const char* const INVALID_CSV_FILE_HEADER = "Error: invalid csv file header";
    static const char* const INVALID_INPUT_FILE_HEADER = "Error: invalid input file header";

    // Value errors
    static const char* const INVALID_EXCHANGE_RATE_VALUE = "Error: invalid exchange rate value";
    static const char* const EXCHANGE_RATES_EMPTY = "Error: exchange rates are empty";
    static const char* const NOT_POSITIVE_NUMBER = "Error: not a positive number.";
    static const char* const TOO_LARGE_NUMBER = "Error: too large a number.";

    // Date errors
    inline std::string badInput(const std::string& input)
    {
        return "Error: bad input => " + input;
    }

    inline std::string noRateBefore(const std::string& date)
    {
        return "Error: no exchange rate available before => " + date;
    }
}

#endif
