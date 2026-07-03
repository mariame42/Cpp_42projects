#include "RPN.hpp"
#include <iostream>
#include <sstream>

/*
    RPN program
    This program is used to evaluate the inverted Polish mathematical expression (RPN)
    the user should provide the expression as an argument
    the program will evaluate the expression and print the result
    the program will handle the errors and print the appropriate error message

    example :
        ./RPN "3 4 2 * 1 + 5 *"
        output :
            60

    notes :
        - the expression must be a valid RPN expression
        - the expression must be a valid mathematical expression
        - the expression must be a valid RPN expression
*/
int main(int ac, char* av[])
{
    try{
        if (ac == 2)
        {
            RPN rpn;
            rpn.evaluate(av[1]);
            std::stringstream ss;
            ss << rpn.getResult();
            PrintWithColor::printGreen(ss.str());
        }
        else
            throw std::logic_error(ErrorMessages::BAD_ARGUMENT_COUNT);
    }
    catch (std::exception& e)
    {
        PrintWithColor::printRedError(e.what());
    }
}
