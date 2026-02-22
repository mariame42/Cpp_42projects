#include "Span.hpp"
#include <algorithm>
#include <sstream>

Span::Span() : _n(0), _data(0), _currentSize(0)
{
}

Span::Span(unsigned int n) : _n(n), _data(n), _currentSize(0)
{
}

Span::~Span()
{
}

std::ostream& operator<<(std::ostream& os, const Span& obj)
{
    os << "Span with size of: " << obj._currentSize << " contane: ";
    for (unsigned int i = 0; i < obj._currentSize && i < PRINTING_LIMIT; i++)
        os << obj._data.at(i) << " ";
    if (obj._currentSize > PRINTING_LIMIT)
    {
        os << "...";
        for (unsigned int i = obj._currentSize - 1; i <= obj._currentSize - 1 && i < obj._currentSize; i++)
            os << " " << obj._data.at(i);
    }
    return os;
}

void Span::addNumber(int number)
{
    if (_currentSize >= _n)
        throw std::runtime_error("Span is already full");
    _data[_currentSize++] = number;
}

int Span::longestSpan()
{
    if (_currentSize < 2)
        throw std::runtime_error("Not enough numbers to find a span");
    int maxVal = *std::max_element(_data.begin(), _data.begin() + _currentSize);
    int minVal = *std::min_element(_data.begin(), _data.begin() + _currentSize);
    return maxVal - minVal;
}

int Span::shortestSpan()
{
    if (_currentSize < 2)
        throw std::runtime_error("Not enough numbers to find a span");
    int shortest = INT_MAX;
    int* sortedArray = new int[_currentSize];
    std::copy(_data.begin(), _data.end(), sortedArray);
    std::sort(sortedArray, sortedArray + _currentSize);
    for (unsigned int i = 0; i < _currentSize - 1; ++i)
    {
        int span = sortedArray[i + 1] - sortedArray[i];
        if (span < shortest)
            shortest = span;
    }
    delete[] sortedArray;
    return shortest;
}

void Span::addRangeOfNumbers(int start, int end)
{
    if (start > end)
        throw std::runtime_error("Start is greater than end");
    for (int i = start; i <= end; i++)
    {
        try
        {
            addNumber(i);
        }
        catch (const std::runtime_error& e)
        {
            std::cout << ORANGE << "WARNING: Span is full now we can't add more numbers, we added "
                << (i - start) << " numbers" << RESET << std::endl;
            return;
        }

    }
}