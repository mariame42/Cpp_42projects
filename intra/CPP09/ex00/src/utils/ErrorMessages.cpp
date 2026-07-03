#include "utils/ErrorMessages.hpp"

namespace ErrorMessages
{
    std::string badInput(const std::string& input)
    {
        return "Error: bad input => " + input;
    }

    std::string invalidDateInExchangeRateFile(const std::string& input)
    {
        return "Error: Invalid date in exchange rate file => " + input;
    }

    std::string noRateBefore(const std::string& date)
    {
        return "Error: no exchange rate available at that date => " + date;
    }
}
