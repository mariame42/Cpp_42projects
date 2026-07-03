#include "BitcoinExchange.hpp"

/*
   BitcoinExchange program
        This program is used to exchange the Bitcoin price by date
        the user should provide the input file path as an argument 
                - input file format :
                    date | value

                example :
                    date | value
                    2025-01-01 | 100
                    2025-01-02 | 200
                    2025-01-03 | 300

                notes :
                    - value must be a positive number that is not greater than 1000.
                    - date must be a valid date in the format YYYY-MM-DD.
                    - date must be not before the start date of the exchange rate file.
                    - any date after the dates that are avalable will go to the last date available.
                    - any invaled headers will not be accepted and header can only be the first line in a page.


        the program will read the input file and print the result
                example :
                    2022-01-01 => 1 = 46249.6
                    2026-01-02 => 2 = 94231.9
                    2022-01-03 => 5 = 232210
*/

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