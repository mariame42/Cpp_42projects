#include "utils/DateUtils.hpp"
#include <sstream>

namespace {
    bool parseInt(const std::string& s, int& out)
    {
        std::istringstream iss(s);
        if (!(iss >> out) || !iss.eof())
            return false;
        return true;
    }

    bool isLeapYear(int year)
    {
        // 1900 is not a leap year
        // 2000 is a leap year
        // 2024 is a leap year
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }
}

bool isValidDate(const std::string& date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year = 0;
    int month = 0;
    int day = 0;
    if (!parseInt(date.substr(0, 4), year)
        || !parseInt(date.substr(5, 2), month)
        || !parseInt(date.substr(8, 2), day))
        return false;

    if (year < 0 || month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[12] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };
    if (month == 2 && isLeapYear(year))
        daysInMonth[1] = 29;

    return day <= daysInMonth[month - 1];
}
