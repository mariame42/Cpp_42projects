/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:30:44 by meid              #+#    #+#             */
/*   Updated: 2025/11/07 17:30:45 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int string_to_int(std::string input)
{
        // C++98: Use stringstream or strtol
        std::istringstream iss(input);
        long long temp;
        iss >> temp;
        // Check if read was successful and value is within int range
        if (iss.fail() || !iss.eof())
            throw std::runtime_error("Invalid integer format");
        if (temp > INT_MAX || temp < INT_MIN)
            throw std::overflow_error("Integer value out of range");
        int intValue = temp;  // Store as long long (validated to be within int range)
        return intValue;
}

float string_to_float(std::string input)
{
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
        float floatValue = static_cast<float>(temp);
        return floatValue;
}

double string_to_double(std::string input)
{
        // C++98: Use stringstream or strtod
        long double temp;
        std::istringstream iss(input);
        iss >> temp;
        if (iss.fail() || !iss.eof())
            throw std::runtime_error("Invalid double format");
        if (temp > DBL_MAX || temp < DBL_MIN)
            throw std::overflow_error("Double value out of range");
        double doubleValue = static_cast<double>(temp);
        return doubleValue;
}