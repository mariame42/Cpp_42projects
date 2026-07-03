/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:25:31 by meid              #+#    #+#             */
/*   Updated: 2025/11/09 16:29:42 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"
#define ORANGE "\033[38;2;255;165;0m"
#define Cyan "\033[36m"
#define Magenta "\033[35m"

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <cctype>
#include <iomanip>
#include <climits>
#include <cfloat>

// Use enum for internal logic (type-safe, fast comparisons)
// String defines only if you need them for output/display
enum InputType{
    Char,
    Int,
    Float,
    Double,
    PseudoLiterals,
    Null
};

// Helper: convert enum to string for display/debugging (optional)

static const bool INFO =  0;

// static utility class : A static utility class is a class that primarily
// consists of static methods and is designed to provide general-purpose helper
// functions or operations that do not require an instance of the class to be created. 

class ScalarConverter
{
    private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);
    
    public:
    static void convert(std::string input);
};

InputType   input_type(std::string input);
std::string inputTypeToString(InputType type);
int string_to_int(std::string input);
float string_to_float(std::string input);
double string_to_double(std::string input);
bool ft_isdigit(int c);

void        convert_from_char(char c);
void        convert_from_int(int i);
void        convert_from_float(float f, int digits_after_dot);
void        convert_from_double(double d, int digits_after_dot);

#endif