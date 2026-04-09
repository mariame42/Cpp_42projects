#include "BitcoinExchange.hpp"

int main(int ac, char* av[])
{
    try{
        if (ac != 2)
            throw std::logic_error(ErrorMessages::BAD_ARGUMENT_COUNT);

        BitcoinExchange bitcoinExchange;
        bitcoinExchange.run(av[1]);
    }
    catch (std::exception& e)
    {
        PrintWithColor::printRed(e.what());
    }
}