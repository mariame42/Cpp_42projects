/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_type.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:25:12 by meid              #+#    #+#             */
/*   Updated: 2025/11/09 16:24:19 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

bool ft_isprint_not_num(int c)
{
    return ((c >= 32 && c <= 47) || (c >= 58 && c <= 126));
}

InputType numeric_types_or_null(std::string input)
{
    bool flag_point = false;
    InputType type = Null;
    for (size_t i = 0; i < input.length(); i++)
    {
        if (i == 0 && (input[i] == '+' || input[i] == '-'))
            continue;
        else if (ft_isdigit(input[i]))
            continue;
        else if (input[i] == '.') {
            if (!flag_point) 
            {
                flag_point = true;
                type = Double;
                continue;
            } else 
                return Null;
        }
        else if (i == (input.length() - 1))
        {
            if (input[i] == 'f')
            {
                type = Float;
                continue;
            }
            else
                return Null;
        }
        else {
            return Null;
        }
    }
    if (type != Float && type != Double)
        type = Int;
    return type;
}

InputType  input_type(std::string input)
{
    if (input.length() == 1 && ft_isprint_not_num(input[0]))
        return (Char);
    else
    {
        InputType type = numeric_types_or_null(input);
        if (type != Null)
        {
            return (type);
        }
        else if (input == "nan" || input == "-nan" || input == "inf"  || input == "+inf" || input == "-inf" ||
                 input == "nanf" || input == "-nanf" || input == "inff" || input == "+inff" || input == "-inff")
            return (PseudoLiterals);
        else
            return (Null);
    }
}

std::string inputTypeToString(InputType type)
{
    switch (type) {
        case Char:              return "char";
        case Int:               return "int";
        case Float:             return "float";
        case Double:            return "double";
        case PseudoLiterals:    return "pseudo literals";
        case Null:              return "null";
        default:                return "unknown";
    }
};
