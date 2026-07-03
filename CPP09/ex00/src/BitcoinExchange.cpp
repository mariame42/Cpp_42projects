# include "BitcoinExchange.hpp"
# include "utils/DateUtils.hpp"
# include "utils/ParseUtils.hpp"
# include "utils/ErrorMessages.hpp"
# include <climits>


const char* const BitcoinExchange::kExchangeRateFile = "data.csv";

// -------------------OCCF-------------------
BitcoinExchange::BitcoinExchange() : _inputFilePath(""), _exchangeRateFilePath(kExchangeRateFile), _rateByDate()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
    (*this) = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
    if (this != &src)
    {
        this->_inputFilePath = src._inputFilePath;
        this->_exchangeRateFilePath = src._exchangeRateFilePath;
        this->_rateByDate = src._rateByDate;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{

}

// -------------------END OF OCCF-------------------

// -------------------RUNNING THE PROGRAM-------------------

void BitcoinExchange::run(const std::string& inputFilePath)
{
    this->_inputFilePath = inputFilePath;
    this->_rateByDate.clear();
    csvFileToMap();
    processInputFile();
}

// -------------------END OF RUNNING THE PROGRAM-------------------

// -------------------Processing the exchange rate file and store it in a map-------------------

bool BitcoinExchange::csvFileToMap()
{
    std::string line;
    std::ifstream MyReadFile(this->_exchangeRateFilePath.c_str());
    if (!MyReadFile.is_open())
        throw std::runtime_error(ErrorMessages::COULD_NOT_OPEN_RATE_FILE);

    for (int pos = 0; getline (MyReadFile, line); pos++)
    {
        try
        {
            std::pair<std::string, double> data = parseCsvRateLine(line, pos);
            if (pos == 0)
                continue;
            if (!isValidDate(data.first))
                throw std::logic_error(ErrorMessages::invalidDateInExchangeRateFile(data.first));
            this->_rateByDate.insert(data);
        }
        catch (const std::exception& e)
        {
            if (std::string(e.what()) == ErrorMessages::EMPTY_LINE)
                continue;
            throw std::logic_error(e.what());
        }
    }
    MyReadFile.close();
    return (true);
}

// -------------------END OF Processing the exchange rate file and store it in a map-------------------

// -------------------Processing the input file and print the result-------------------

bool BitcoinExchange::processInputFile()
{
    std::string line;
    std::ifstream MyReadFile(this->_inputFilePath.c_str());
    if (!MyReadFile.is_open())
        throw std::runtime_error(ErrorMessages::COULD_NOT_OPEN_INPUT_FILE);

    for (int i = 0; getline (MyReadFile, line); i++)
    {
        try
        {
            std::pair<std::string, double> data = parseInputValueLine(line, i);
            if (i == 0)
                continue;
            double bitcoinValue = getValueForDate(data.first);
            PrintWithColor::printResultLine(data.first, bitcoinValue, data.second);
        }
        catch (const std::exception& e)
        {
            if (i == 0)
                throw std::logic_error(e.what());
            if (std::string(e.what()) == ErrorMessages::EXCHANGE_RATES_EMPTY)
                throw std::logic_error(e.what());
            if (std::string(e.what()) == ErrorMessages::EMPTY_LINE)
                continue;
            PrintWithColor::printRed(e.what());
        }
    }
    MyReadFile.close();
    return (true);
}

double BitcoinExchange::getValueForDate(const std::string& Date)
{
    if (!isValidDate(Date))
        throw std::logic_error(ErrorMessages::badInput(Date));

    if (this->_rateByDate.empty())
        throw std::logic_error(ErrorMessages::EXCHANGE_RATES_EMPTY);

    //  lower_bound: returns an iterator to the first key that is >= Date
    std::map<std::string, double>::const_iterator it = this->_rateByDate.lower_bound(Date);
    if (it == this->_rateByDate.end() || it->first != Date)
    {
        if (it == this->_rateByDate.begin())
            throw std::logic_error(ErrorMessages::noRateBefore(Date));
        --it;
    }
    return it->second;
}

// -------------------END OF Processing the input file and print the result-------------------