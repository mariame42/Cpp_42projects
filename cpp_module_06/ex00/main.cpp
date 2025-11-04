#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av)
{
    (void) ac;
    (void) av;
    std::cout << "lol" << std::endl;
    ScalarConverter::convert("2");
    std::cout << "------------------------" << std::endl;
    ScalarConverter::convert("2.0");
    std::cout << "------------------------" << std::endl;
    ScalarConverter::convert("2.");
    std::cout << "------------------------" << std::endl;
    ScalarConverter::convert(".2");
    std::cout << "------------------------" << std::endl;
    ScalarConverter::convert("-.2");
    std::cout << "------------------------" << std::endl;
    ScalarConverter::convert("-4.2");
    std::cout << "------------------------" << std::endl;
    ScalarConverter::convert("5.2f");
    std::cout << "------------------------" << std::endl;
    ScalarConverter::convert("-0.2f5");
    std::cout << "------------------------" << std::endl;
    ScalarConverter::convert("-4.2ff");
    std::cout << "------------------------" << std::endl;
    // if (ac == 2)
    // {
    //     std::string input = av[0];
    //     std::string type = ScalarConverter::is_valid_type(av[0]);
    //     if (type != "null")
    //     {
    //         ScalarConverter::is_valid_type(av[0]);
    //         ScalarConverter::is_valid_type(av[0]);
    //         ScalarConverter::is_valid_type(av[0]);        
    //     }
    //     else
    //     {

    //     }
    // }
    // else
    //     std::cout << RED << "the format is ./convert any_valid_string" << std::endl;
    // return 0;
}

// #include <cmath>
// #include <iostream>

// int main() {
//     double value = std::sqrt(-1.0); // Generates a NaN
//     if (std::isnan(value)) {
//         std::cout << "The value is NaN" << std::endl;
//     }
//     return 0;
// }
