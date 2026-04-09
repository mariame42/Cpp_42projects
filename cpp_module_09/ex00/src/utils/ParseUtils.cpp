#include "utils/ParseUtils.hpp"

std::string getAfterChar(const std::string& str, char delim) {
    size_t pos = str.rfind(delim);
    if (pos == std::string::npos)
        return str;
    return str.substr(pos + 1);
}

std::string getUntilChar(const std::string& str, char delim) {
    size_t pos = str.find(delim);
    if (pos == std::string::npos)
        return str;
    return str.substr(0, pos);
}

std::string trim(const std::string& str) {
    size_t start = 0;
    while (start < str.length() && std::isspace(static_cast<unsigned char>(str[start]))) {
        ++start;
    }
    if (start == str.length())
        return "";

    size_t end = str.length() - 1;
    while (end > start && std::isspace(static_cast<unsigned char>(str[end]))) {
        --end;
    }
    return str.substr(start, end - start + 1);
}

namespace {
    bool isCsvHeader(const std::string& line)
    {
        if (line.find(',') == std::string::npos || line.find(',') != line.rfind(','))
            return false;
        std::string left = trim(getUntilChar(line, ','));
        std::string right = trim(getAfterChar(line, ','));
        return (left == "date" && right == "exchange_rate");
    }

    bool isInputHeader(const std::string& line)
    {
        if (line.find('|') == std::string::npos || line.find('|') != line.rfind('|'))
            return false;
        std::string left = trim(getUntilChar(line, '|'));
        std::string right = trim(getAfterChar(line, '|'));
        return (left == "date" && right == "value");
    }
}

std::pair<std::string, double> parseCsvRateLine(const std::string& line, int pos)
{
    if (pos == 0)
    {
        if (!isCsvHeader(line))
            throw std::logic_error(ErrorMessages::INVALID_CSV_FILE_HEADER);
        return (std::make_pair(std::string(), 0.0));
    }

    std::string date = trim(getUntilChar(line, ','));
    std::string rateStr = trim(getAfterChar(line, ','));
    double exchange_rate = 0.0;
    std::istringstream iss(rateStr);
    if (!(iss >> exchange_rate) || !iss.eof())
        throw std::logic_error(ErrorMessages::INVALID_EXCHANGE_RATE_VALUE);
    return (std::make_pair(date, exchange_rate));
}

std::pair<std::string, double> parseInputValueLine(const std::string& line, int pos)
{
    if (pos == 0)
    {
        if (!isInputHeader(line))
            throw std::logic_error(ErrorMessages::INVALID_INPUT_FILE_HEADER);
        return (std::make_pair(std::string(), 0.0));
    }

    std::string date = trim(getUntilChar(line, '|'));
    std::string strValue = trim(getAfterChar(line, '|'));
    double value = 0.0;
    std::istringstream iss(strValue);
    if (!(iss >> value) || !iss.eof())
        throw std::logic_error(ErrorMessages::badInput(line));

    return (std::make_pair(date, value));
}


