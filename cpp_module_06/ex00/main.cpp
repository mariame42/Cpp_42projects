#include "ScalarConverter.hpp"
#include <iostream>


int main(int ac, char **av)
{
    if (ac == 2)
    {
        std::string input = av[1];
        ScalarConverter::convert(input);
    }
    return 0;
}
// int main(int ac, char **av)
// {
//     (void) ac;
//     (void) av;
//     ScalarConverter::convert("c");
//     ScalarConverter::convert("a");
//     ScalarConverter::convert("82");
//     ScalarConverter::convert("62.0");
//     ScalarConverter::convert("62.");
//     ScalarConverter::convert(".62");
//     ScalarConverter::convert("-.62");
//     ScalarConverter::convert("-4.62");
//     ScalarConverter::convert("5.62f");
//     ScalarConverter::convert("-40.62f5");
//     ScalarConverter::convert("-4.62ff");

//     ScalarConverter::convert("0");
//     ScalarConverter::convert("42.0f");
//     ScalarConverter::convert("nan");
//     ScalarConverter::convert("2147483647222222");
//     ScalarConverter::convert("nan");
//     ScalarConverter::convert("nan");
// }

// #include <cmath>
// #include <iostream>

// int main() {
//     double value = std::sqrt(-1.0); // Generates a NaN
//     if (std::isnan(value)) {
//         std::cout << "The value is NaN" << std::endl;
//     }
//     return 0;
// }
