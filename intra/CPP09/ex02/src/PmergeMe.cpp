#include "PmergeMe.hpp"
#include "SortingHelpers/SortingHelpers.hpp"
#include "utils/PrintWithColor.hpp"
#include <cctype>
#include <climits>
#include <ctime>
#include <stdexcept>

// -------------------OCCF-------------------
PmergeMe::PmergeMe()
{
    this->_vectorTime = 0;
    this->_dequeTime = 0;
    this->_vector = std::vector<int>();
    this->_deque = std::deque<int>();
    this->_sortedVector = std::vector<int>();
    this->_sortedDeque = std::deque<int>();
    this->_parsedInput = std::vector<int>();
    this->_hasStragglerVector = false;
    this->_stragglerVector = 0;
    this->_hasStragglerDeque = false;
    this->_stragglerDeque = 0;
    this->_pairsVector = std::vector<Pair>();
    this->_pairsDeque = std::deque<Pair>();
}

PmergeMe::PmergeMe(const PmergeMe& src)
{
    (*this) = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
    if (this != &src)
    {
        this->_vectorTime = src._vectorTime;
        this->_dequeTime = src._dequeTime;
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{
}

// -------------------END OF OCCF-------------------

// -------------------PARSE-------------------

std::vector<int> parseEachArg(std::string str)
{
    std::vector<int> res;
    for (std::size_t i = 0; i < str.length();)
    {
        if (std::isspace(static_cast<unsigned char>(str[i])))
        {
            ++i;
            continue;
        }
        if (str[i] == '-')
            throw std::logic_error(ErrorMessages::NEGATIVE_NUM);
        if (str[i] == '+')
        {
            ++i;
            if (i >= str.length() || !std::isdigit(static_cast<unsigned char>(str[i])))
                throw std::logic_error(ErrorMessages::INVALID_INPUT);
        }
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            throw std::logic_error(ErrorMessages::INVALID_INPUT);

        long value = 0;
        while (i < str.length() && std::isdigit(static_cast<unsigned char>(str[i])))
        {
            value = value * 10 + (str[i] - '0');
            if (value > INT_MAX)
                throw std::logic_error(ErrorMessages::NUMBER_TOO_LARGE);
            ++i;
        }
        res.push_back(static_cast<int>(value));

        if (i < str.length() && !std::isspace(static_cast<unsigned char>(str[i])))
            throw std::logic_error(ErrorMessages::INVALID_INPUT);
    }
    return (res);
}

void PmergeMe::parse(const std::vector<std::string>& args)
{
    try {
        for (std::size_t i = 0; i < args.size(); i++)
        {
            std::vector<int> parsedChanck = parseEachArg(args[i]);
            this->_parsedInput.insert(
                this->_parsedInput.end(),
                parsedChanck.begin(),
                parsedChanck.end()
            );
        }
        this->_vector = this->_parsedInput;
        this->_deque = std::deque<int>(this->_parsedInput.begin(), this->_parsedInput.end());
    }
    catch (std::exception &e)
    {
        throw std::logic_error(e.what());
    }
}

// -------------------END OF PARSE-------------------

// -------------------SORT-------------------

/*
    sorting steps :
    1. split the input into pairs
    2. sort the pairs by the big value "recursive sorting"
    3. build the main chain and the pending chain from the sorted pairs
    4. insert the pending chain into the main chain using the Jacobsthal sequence "binary sorting"
*/
void PmergeMe::sortAndCalcForVector()
{
    std::clock_t start = std::clock();
    SortingHelpers::splitPairs(
        this->_vector,
        this->_pairsVector,
        this->_hasStragglerVector,
        this->_stragglerVector);
    SortingHelpers::buildChainsFromPairs(this->_pairsVector, this->_mainChainVector, this->_pendingVector);
    SortingHelpers::insertPending(this->_mainChainVector, this->_pendingVector);
    if (this->_hasStragglerVector)
    {
        std::vector<int> one(1, this->_stragglerVector);
        SortingHelpers::insertPending(this->_mainChainVector, one);
    }

    std::clock_t end = std::clock();
    this->_vectorTime = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
    this->_sortedVector = this->_mainChainVector;
}


void PmergeMe::sortAndCalcForDeque()
{
    std::clock_t start = std::clock();
    SortingHelpers::splitPairs(this->_deque,
                               this->_pairsDeque,
                               this->_hasStragglerDeque,
                               this->_stragglerDeque);
    SortingHelpers::buildChainsFromPairs(this->_pairsDeque,
                                         this->_mainChainDeque,
                                         this->_pendingDeque);
    SortingHelpers::insertPending(this->_mainChainDeque, this->_pendingDeque);
    if (this->_hasStragglerDeque)
    {
        std::deque<int> one(1, this->_stragglerDeque);
        SortingHelpers::insertPending(this->_mainChainDeque, one);
    }
    std::clock_t end = std::clock();
    this->_dequeTime = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
    this->_sortedDeque = this->_mainChainDeque;
}

// -------------------END OF SORT-------------------

// -------------------PRINT-------------------

void PmergeMe::printstanderdOutput()
{
    PrintWithColor::printstanderdOutput(this->_vector, this->_sortedVector, this->_vectorTime, this->_dequeTime);
    if (DEBUG)
    {
        PrintWithColor::printVector(this->_sortedVector);
        PrintWithColor::printDeque(this->_sortedDeque);
    }
}

// -------------------END OF PRINT-------------------