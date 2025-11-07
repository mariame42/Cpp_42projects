/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_from.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:33:38 by meid              #+#    #+#             */
/*   Updated: 2025/11/07 19:42:56 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static std::string numric_to_char(double d)
{
    int i = static_cast<int>(d);

    if (i < 32 || i > 126)
        return ("Non displayable");
    char c = static_cast<char>(i);
    return ("char: '" + std::string(1, c) + "'");

}

void        convert_from_char(char c)
{
    std::cout << "char: " << c << std::endl;

    // numeric values
    int i = static_cast<int>(c);
    std::cout << "int: " << i << std::endl;

    float f = static_cast<float>(i);
    // print floating-point numbers in fixed-point notation
    // without std::fixed  ->  might print: 1.23457e+06
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    double d = static_cast<float>(i);
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void        convert_from_int(int i)
{
    std::cout << "char: " << numric_to_char(static_cast<double>(i)) << std::endl;

    std::cout << "int: " << i << std::endl;

    // Note: float has only ~6-7 decimal digits of precision
    // Large integers like INT_MAX (2147483647) cannot be exactly represented
    // and will round to the nearest representable float value (2147483648.0f)
    float f = static_cast<float>(i);
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    // double has ~15 decimal digits, so it can exactly represent all int values
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void        convert_from_float(float f)
{
    std::cout << "char: " << numric_to_char(static_cast<double>(f)) << std::endl;

    // float can be out of int range
    if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;



    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    // safe because float is in the range of double
    std::cout << "double: " << static_cast<double>(f) << std::endl;

}

void        convert_from_double(double d)
{
    std::cout << "char: " << numric_to_char(d) << std::endl;

    if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    if (d < FLT_MIN || d > FLT_MAX)
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;

    std::cout << "double: " << d << std::endl;
}