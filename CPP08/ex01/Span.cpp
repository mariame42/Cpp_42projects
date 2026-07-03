#include "Span.hpp"
#include <algorithm>
#include <sstream>

// ----------------------------------------------
// OCCF : Orthodox Canonical Form
// ----------------------------------------------

Span::Span() : _capacity(0)
{
}

Span::Span(unsigned int n) : _capacity(n)
{
    _data.reserve(n);
}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _capacity = other._capacity;
        _data = other._data;
    }
    return *this;
}

Span::~Span()
{
}

// ----------------------------------------------
// Member functions
// ----------------------------------------------

void Span::addNumber(int number)
{
    if (_data.size() >= _capacity)
        throw std::runtime_error("Span is already full");

    _data.push_back(number);
}

/*
    std::min_element and std::max_element are member functions of the <algorithm> library.
        1. searches the range. 
        2. returns an iterator pointing to the smallest element, or the largest element.
        3. we use * to dereference the iterator to get the value of the smallest or largest element.
*/

int Span::longestSpan()
{
    if (_data.size() < 2)
        throw std::runtime_error("Not enough numbers");

    int min = *std::min_element(_data.begin(), _data.end());
    int max = *std::max_element(_data.begin(), _data.end());

    return max - min;
}

int Span::shortestSpan()
{
    if (_data.size() < 2)
        throw std::runtime_error("Not enough numbers");

    std::vector<int> temp(_data);

    std::sort(temp.begin(), temp.end());

    int shortest = INT_MAX;

    for (size_t i = 0; i < temp.size() - 1; i++)
    {
        int span = temp[i + 1] - temp[i];

        if (span < shortest)
            shortest = span;
    }

    return shortest;
}

/*
    size() is a member function of the <vector> library.
    1. returns the number of elements in the vector.
    2. we use static_cast<unsigned int> to convert the size_t to an unsigned int.
*/

unsigned int Span::size() const
{
    return static_cast<unsigned int>(_data.size());
}

/*
    at() is a member function of the <vector> library.
    1. returns the element at the given index.
    2. we use static_cast<unsigned int> to convert the size_t to an unsigned int.
*/

int Span::at(unsigned int i) const
{
    return _data.at(i);
}

// ----------------------------------------------
// Operator overloading << for beautiful output
// ----------------------------------------------

std::ostream& operator<<(std::ostream& os, const Span& obj)
{
    unsigned int sz = obj.size();
    os << "Span with size of: " << sz << " contain: ";
    for (unsigned int i = 0; i < sz && i < PRINTING_LIMIT; i++)
        os << obj.at(i) << " ";
    if (sz > PRINTING_LIMIT)
    {
        os << "...";
        os << " " << obj.at(sz - 1);
    }
    return os;
}
