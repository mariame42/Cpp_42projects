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


#include <string>

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
inline std::string inputTypeToString(InputType type)
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
}

static const bool OCCF =  0;
static const bool INFO =  1;


class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();

    public:
        static void convert(std::string input);
};

InputType   input_type(std::string input);

void        convert_from_char(char c);
void        convert_from_int(int i);
void        convert_from_float(float f);
void        convert_from_double(double d);

#endif