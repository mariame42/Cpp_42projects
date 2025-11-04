#include "ScalarConverter.hpp"
#include <iostream>
#include <cctype>

// Decimal int: only digits + optional +/-

// Hex int: digits + a–f/A–F

// Float/double: digits, ., e/E, optional +/-, optional f/F/l/L

bool ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

char valid_num(std::string input)
{
    bool flag_point = false;
    char type = 'n'; // c -> char , i -> int , f -> float , d -> double , n -> error
    for (size_t i = 0; i < input.length(); i++)
    {
        std::cout << "parss: " << input[i] << std::endl;

        if (i == 0 && (input[i] == '+' || input[i] == '-'))
        {
            std::cout << "pov01" << std::endl;
            continue;
        } 
        else if (ft_isdigit(input[i]))
        {
            std::cout << "pov02" << std::endl;
            continue;
        } 
        else if (input[i] == '.') {
            if (!flag_point 
                && ((i+1 < input.length() &&  ft_isdigit(input[i+1])) 
                && (i > 0 &&  ft_isdigit(input[i-1])))) 
            {
                std::cout << "pov03" << std::endl;
                flag_point = true;
                type = 'd';
                continue;
            } else {
                std::cout << "here" << std::endl;
                return 'n';
            }
        }
        else if (i == (input.length() - 1))
        {
            if (input[i] == 'f')
            {
                type = 'f';
                std::cout << "pov04" << std::endl;
                continue;
            }
            else
                return 'n';
        }
        else {
            return 'n';
    }
}
if (type != 'f' && type != 'd')
    type = 'i';
return type;
}

static std::string parss_the_input(std::string input)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input.length() == 1 && isalpha(input[0]))
            return ("char");
        else if (valid_num(input) != 'n')
        {
            std::cout << valid_num(input) << std::endl;
            return ("num");
        }
        else
            return ("else");

    }
    return ("s");
}

void ScalarConverter::convert(std::string input)
{
    std::cout << input << std::endl;
    std::cout << parss_the_input(input) << std::endl;
}