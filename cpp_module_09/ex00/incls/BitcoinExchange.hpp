#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>         // for std::map
#include <string>      // for std::string
#include <iostream>    // for std::cout 
#include <stdexcept>   // for std::runtime_error, std::logic_error, etc.
#include <exception>   // for std::exception (base class)
#include <fstream>     // for std::ifstream, std::ofstream
#include <utility>

#include "utils/PrintWithColor.hpp"
#include "utils/ErrorMessages.hpp"
# include "utils/DateUtils.hpp"
# include "utils/ParseUtils.hpp"

class BitcoinExchange
{
    private :
        // constant file path for exchange rate file
        static const char* const kExchangeRateFile;

        // files paths
        std::string _inputFilePath;
        std::string _exchangeRateFilePath;

        // map of exchange rates by date
        // extracted from exchange rate file
        std::map<std::string, double> _rateByDate;


    public :
        // OCCF
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& src);
        BitcoinExchange& operator=(const BitcoinExchange& src);
        ~BitcoinExchange();

        // main function to run the program
        void run(const std::string& inputFilePath);

        // main two steps of the program
        // 1. read exchange rate file and store in map
        bool csvFileToMap();
        // 2. process input file and print results
        bool processInputFile();

        // helpers for processOneLine
        double getValueForDate(const std::string& Date);
};

#endif