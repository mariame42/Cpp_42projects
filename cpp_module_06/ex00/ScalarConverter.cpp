/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:25:26 by meid              #+#    #+#             */
/*   Updated: 2025/11/07 17:36:32 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool endsWithChar(const std::string& str, char c) {
    if (str.empty()) return false;        // empty string cannot match
    return str[str.size() - 1] == c;      // check last character
}


void handle_PseudoLiterals(std::string input)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (endsWithChar(input, 'f'))
    {
        std::cout <<  "float: " + input << std::endl;
        std::cout << "double: " + input.substr(0, input.length() - 1) << std::endl;
    }
    else
    {
        std::cout << "float: " + input + "f" << std::endl;
        std::cout << "double: " + input << std::endl;
    }
}

void ScalarConverter::convert(std::string input)
{
    if (INFO)
    {
        std::cout << "------------------------" << std::endl;
        std::cout << "input: " << input << std::endl;
    }

    InputType type = input_type(input);

    if (type == Null)
    {
        std::cout << RED << "Invalid input" << RESET<< std::endl;
        if (INFO)
            std::cout << "------------------------" << std::endl;
        return;
    }
    else if (type == PseudoLiterals)
    {
        if (INFO)
            std::cout << GREEN << "Valid input of type: " << inputTypeToString(type) << RESET << std::endl;
        handle_PseudoLiterals(input);
    }
    else
    {
        if (INFO)
            std::cout << GREEN << "Valid input of type: " << inputTypeToString(type) << RESET << std::endl;
        try {
            if (type == Char)
            {
                convert_from_char(input[0]);
            }
            else if (type == Int)
            {
                 convert_from_int(string_to_int(input));
            }
            else if (type == Float)
            {
                convert_from_float(string_to_float(input));
            }
            else if (type == Double)
            {
                convert_from_double(string_to_double(input));
            }

        }
        catch (const std::exception& e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
            if (INFO)
                std::cout << "------------------------" << std::endl;
            return;
        }
    
    }
}