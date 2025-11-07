#include "ParsedSource.hpp"
#include <iostream>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <sstream>  // For std::istringstream (C++98 compatible)
// Constructor: Parse input string into canonical source value
// This is where you do the SINGLE parse - fill in the appropriate
// hasXXX and XXXValue fields based on the input type
ParsedSource::ParsedSource(const std::string& input, InputType type)
: isNaN(false), isInf(false), sign(1),
  hasChar(false), charValue(0),
  hasInt(false), intValue(0),
  hasFloat(false), floatValue(0.0f),
  hasDouble(false), doubleValue(0.0)
{
    if (type == Char)
    {
        hasChar = true;
        charValue = input[0];
    }
    else if (type == Int)
    {
        hasInt = true;
        // C++98: Use stringstream or strtol
        std::istringstream iss(input);
        long long temp;
        iss >> temp;
        // Check if read was successful and value is within int range
        if (iss.fail() || !iss.eof())
            throw std::runtime_error("Invalid integer format");
        if (temp > INT_MAX || temp < INT_MIN)
            throw std::overflow_error("Integer value out of range");
        intValue = temp;  // Store as long long (validated to be within int range)
    }
    else if (type == Float)
    {
        hasFloat = true;
        // C++98: Use stringstream or strtod + cast
        // Remove 'f' suffix if present for parsing
        std::string parseInput = input;
        if (!parseInput.empty() && parseInput[parseInput.length() - 1] == 'f')
            parseInput = parseInput.substr(0, parseInput.length() - 1);
        std::istringstream iss(parseInput);
        double temp;
        iss >> temp;
        // Check if read was successful and entire string was consumed
        if (iss.fail() || !iss.eof())
            throw std::runtime_error("Invalid float format");
        // Check if value is within float range (handle both positive and negative)
        if ((temp > 0 && temp > FLT_MAX) || (temp < 0 && temp < -FLT_MAX))
            throw std::overflow_error("Float value out of range");
        floatValue = static_cast<float>(temp);
    }
    else if (type == Double)
    {
        hasDouble = true;
        // C++98: Use stringstream or strtod
        long double temp;
        std::istringstream iss(input);
        iss >> temp;
        if (iss.fail() || !iss.eof())
            throw std::runtime_error("Invalid double format");
        if (temp > DBL_MAX || temp < DBL_MIN)
            throw std::overflow_error("Double value out of range");
        doubleValue = static_cast<double>(temp);
    }
    else if (type == PseudoLiterals)
    {
        if (input == "nan" || input == "nanf")
        {
            isNaN = true;
        }
        else if (input == "+inf" || input == "+inff")
        {
            isInf = true;
            sign = 1;
        }
        else if (input == "-inf" || input == "-inff")
        {
            isInf = true;
            sign = -1;
        }
    }
    else if (type == Null)
    {
        isNaN = true;
    }
    // TODO: Handle special cases: NaN, +inf, -inf, nanf, +inff, -inff
}

ParsedSource::~ParsedSource()
{
    // Destructor - nothing to clean up for POD types
}

bool ParsedSource::getisNaN() const{
    return isNaN;
}
bool ParsedSource::getisInf() const{
    return isInf;
}
int ParsedSource::getsign() const{
    return sign;
}
bool ParsedSource::gethasChar() const{
    return hasChar;
}
char ParsedSource::getcharValue() const{
    return charValue;
}
bool ParsedSource::gethasInt() const{
    return hasInt;
}
long long ParsedSource::getintValue() const{
    return intValue;
}
bool ParsedSource::gethasFloat() const{
    return hasFloat;
}
float ParsedSource::getfloatValue() const{
    return floatValue;
}
bool ParsedSource::gethasDouble() const{
    return hasDouble;
}
double ParsedSource::getdoubleValue() const{
    return doubleValue;
}