/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:25:26 by meid              #+#    #+#             */
/*   Updated: 2025/11/09 16:16:30 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int count_digits_after_dot(const std::string& s)
{
    size_t pos = s.find('.');
    if (pos == std::string::npos) return 0; // no dot
    int count = 0;
    for (++pos; pos < s.length() && ft_isdigit(s[pos]); ++pos)
        ++count;
    if (count == 0)
        return 1;
    return count;
}

bool endsWith(const std::string& str, const std::string& suffix) {
    if (suffix.size() > str.size()) 
        return false;
    return str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}


void handle_PseudoLiterals(std::string input)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (((input[0] == 'n' && endsWith(input, "f")) || (input[0] != 'n' && endsWith(input, "ff"))))
    {
        std::cout <<  "float: " << input << std::endl;
        std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
    }
    else
    {
        std::cout << "float: " << input + "f" << std::endl;
        std::cout << "double: " << input << std::endl;
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
        handle_PseudoLiterals(input);
        if (INFO)
            std::cout << GREEN << "Valid input of type: " << inputTypeToString(type) << RESET << std::endl;
    }
    else
    {
        try {
            if (type == Char)
            {
                convert_from_char(input[0]);
            }
            else if (type == Int)
            {
                convert_from_int(string_to_int(input));
            }
            else
            {
                int digits_after_dot = count_digits_after_dot(input);
                if (type == Float)
                {
                    convert_from_float(string_to_float(input), digits_after_dot);
                }
                else if (type == Double)
                {
                    convert_from_double(string_to_double(input), digits_after_dot);
                }
            }
            if (INFO)
                std::cout << GREEN << "Valid input of type: " << inputTypeToString(type) << RESET << std::endl;

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