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

#define INT "int"
#define CHAR "char"
#define FLOAT "float"
#define DOUBLE "double"
#define NULL_TYPE "null"


static const bool OCCF =  0;

// All useful functionality is static, so the class
// behaves like a namespace — a container for tools, not an object
class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();

    public:
        static void convert(std::string input);
};

#endif