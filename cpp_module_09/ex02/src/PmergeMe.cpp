#include "PmergeMe.hpp"
#include "sorting_helpers/sorting_helpers.hpp"
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

// -------------------parse-------------------
std::vector<int> parseEachArg(std::string str)
{
    std::vector<int> res;
    for (std::size_t i = 0; i < str.length();)
    {
        if (str[i] == '-')
            throw std::logic_error(ErrorMessages::NEGATIVE_NUM);
        if (std::isspace(static_cast<unsigned char>(str[i])))
        {
            ++i;
            continue;
        }
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            throw std::logic_error(ErrorMessages::INVALED_INPUT);

        long value = 0;
        while (i < str.length() && std::isdigit(static_cast<unsigned char>(str[i])))
        {
            value = value * 10 + (str[i] - '0');
            if (value > INT_MAX)
                throw std::logic_error(ErrorMessages::INVALED_INPUT);
            ++i;
        }
        res.push_back(static_cast<int>(value));

        if (i < str.length() && !std::isspace(static_cast<unsigned char>(str[i])))
            throw std::logic_error(ErrorMessages::INVALED_INPUT);
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

void PmergeMe::sortAndCalcForVector()
{
    std::clock_t start = std::clock();

    SortingHelpers::splitPairs(this->_vector,
                               this->_pendingVector,
                               this->_mainChainVector,
                               this->_hasStragglerVector,
                               this->_stragglerVector);
    this->_mainChainVector = SortingHelpers::mergeInsertSortRecursive(this->_mainChainVector);
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
                               this->_pendingDeque,
                               this->_mainChainDeque,
                               this->_hasStragglerDeque,
                               this->_stragglerDeque);
    this->_mainChainDeque = SortingHelpers::mergeInsertSortRecursive(this->_mainChainDeque);
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

void PmergeMe::printstanderdOutput()
{
    PrintWithColor::printstanderdOutput(this->_vector, this->_sortedVector, this->_vectorTime, this->_dequeTime);
}