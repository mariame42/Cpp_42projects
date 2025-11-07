/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:25:16 by meid              #+#    #+#             */
/*   Updated: 2025/11/07 17:25:17 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

// main progran
// int main(int ac, char **av)
// {
//     if (ac == 2)
//     {
//         std::string input = av[1];
//         ScalarConverter::convert(input);
//     }
//     else
//         std::cout << RED << "Error: Invalid number of arguments." << RESET << std::endl;
//     return 0;
// }

int main(void)
{
    //  turn on the info flag from the header
    
    std::cout << "----- Valid Inputs -----" << std::endl;
    
    std::cout << BLUE << "<<<<<<<----- char:----->>>>>>>" << RESET << std::endl;
    ScalarConverter::convert("c");
    ScalarConverter::convert("a");
    ScalarConverter::convert("0");  // digit as char
    ScalarConverter::convert("Z");
    
    std::cout << BLUE << "<<<<<<<----- int:----->>>>>>>" << RESET << std::endl;
    ScalarConverter::convert("0");
    ScalarConverter::convert("82");
    ScalarConverter::convert("-42");
    ScalarConverter::convert("+42");
    ScalarConverter::convert("2147483647");  // INT_MAX
    ScalarConverter::convert("-2147483648");  // INT_MIN
    
    std::cout << BLUE << "<<<<<<<----- float:----->>>>>>>" << RESET << std::endl;
    ScalarConverter::convert("5.62f");
    ScalarConverter::convert("42.0f");
    ScalarConverter::convert("-42.5f");
    ScalarConverter::convert("+42.5f");
    ScalarConverter::convert("-inff");
    ScalarConverter::convert("+inff");
    ScalarConverter::convert("nanf");
    
    std::cout << BLUE << "<<<<<<<----- double:----->>>>>>>" << RESET << std::endl;
    ScalarConverter::convert("-4.62");
    ScalarConverter::convert("62.0");
    ScalarConverter::convert("+62.0");
    ScalarConverter::convert("-inf");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("nan");
    
    std::cout << BLUE << "\n<<<<<<<----- Invalid Inputs ----->>>>>>>" << RESET << std::endl;
    ScalarConverter::convert("-40.62f5");  // extra char after f
    ScalarConverter::convert("-4.62ff");   // double f
    ScalarConverter::convert("62.");        // trailing dot (if invalid)
    ScalarConverter::convert(".62");       // leading dot (if invalid)
    ScalarConverter::convert("-.62");       // leading dot (if invalid)
    ScalarConverter::convert("2147483647222222");  // overflow
    ScalarConverter::convert("");           // empty
    ScalarConverter::convert("abc");       // invalid string
    ScalarConverter::convert("42abc");     // mixed invalid
}