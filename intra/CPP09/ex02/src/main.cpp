#include "PmergeMe.hpp"
#include "utils/ErrorMessages.hpp"
#include "utils/PrintWithColor.hpp"

/*
    PmergeMe program
    This program is used to merge and sort the input vectors and deques
    the user should provide the input as an argument
    the program will merge and sort the input and print the result
    the program will handle the errors and print the appropriate error message
    
    example :
    ./PmergeMe 1 2 3 4 5 6 7 8 9 10
    output :
    Vector time : 0.000000
    Deque time : 0.000000
    Vector : 1 2 3 4 5 6 7 8 9 10
    Deque : 1 2 3 4 5 6 7 8 9 10
    
    notes :
    - the input must be a valid integer
    - the input must be a positive number
    - the input must be a number that is not greater than 2147483647
    - the input must be a number that is not less than -2147483648
    - the input must be a number that is not greater than 2147483647
*/

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
        PrintWithColor::printRedError(e.what());
        return 1;
    }
    return 0;
}