#ifndef PARSEUTILS_HPP
#define PARSEUTILS_HPP

#include <string>
#include <utility>
#include <cctype>
#include <sstream>
#include <stdexcept>

#include "utils/ErrorMessages.hpp"

std::string getAfterChar(const std::string& str, char delim);
std::string getUntilChar(const std::string& str, char delim);
std::string trim(const std::string& str);
std::pair<std::string, double> parseCsvRateLine(const std::string& line, int pos);
std::pair<std::string, double> parseInputValueLine(const std::string& line, int pos);

#endif
