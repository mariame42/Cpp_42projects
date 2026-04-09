#include "RPN.hpp"
#include <iostream>
#include <sstream>

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
        PrintWithColor::printRed(e.what());
    }
}
