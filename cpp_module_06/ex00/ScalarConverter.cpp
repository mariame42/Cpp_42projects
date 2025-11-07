#include "ScalarConverter.hpp"
#include <iostream>
#include <cctype>
#include <iomanip>
#include <climits>
#include <cfloat>

std::string numric_to_char(double d)
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

#include <string>

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
    std::cout << "------------------------" << std::endl;
    std::cout << "input: " << input << std::endl;

    InputType type = input_type(input);

    if (type == Null)
    {
        std::cout << RED << "Invalid input" << RESET<< std::endl;
        std::cout << "------------------------" << std::endl;
        return;
    }
    else
    {
        std::cout << "Valid input of type: " << inputTypeToString(type) << std::endl;
        // Parse once here - this is where you do the single parse
        try {
            ParsedSource parsed(input, type);  // Constructor does the parsing
            if (type == PseudoLiterals)
            {
                handle_PseudoLiterals(input);
            }
            if (parsed.gethasChar())
                convert_from_char(parsed.getcharValue());
            else if (parsed.gethasInt())
                convert_from_int(parsed.getintValue());
            else if (parsed.gethasFloat())
                convert_from_float(parsed.getfloatValue());
            else if (parsed.gethasDouble())
                convert_from_double(parsed.getdoubleValue());
        }
        catch (const std::exception& e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
            std::cout << "------------------------" << std::endl;
            return;
        }
    }
    std::cout << "------------------------" << std::endl;


}