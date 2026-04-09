#include "PmergeMe.hpp"

int main(int ac, char* av[])
{
    try{
        if (ac > 1)
        {
            // args(iterator to the first element, iterator to one element after the last element)
            std::vector<std::string> args(av + 1, av + ac);
            PmergeMe p;
            p.parse(args);
            p.sortAndCalcForVector();
            p.sortAndCalcForDeque();
            p.printstanderdOutput();
        }
        else
            throw std::logic_error(ErrorMessages::BAD_ARGUMENT_COUNT);
    }
    catch (std::exception& e)
    {
        PrintWithColor::printRed(e.what());
    }
}