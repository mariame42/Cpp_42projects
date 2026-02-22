#ifndef SPAN_HPP
# define SPAN_HPP

// span mean "a range or interval between two points"

#define PRINTING_LIMIT 20

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"
#define ORANGE "\033[38;2;255;165;0m"

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <climits>

class Span
{
private:

    unsigned int        _capacity;
    std::vector<int>    _data;

public:

    Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);

    template <typename Iterator>
    void addRange(Iterator begin, Iterator end)
    {
        unsigned int dist = std::distance(begin, end);

        if (_data.size() + dist > _capacity)
            throw std::runtime_error("Span is already full");

        _data.insert(_data.end(), begin, end);
    }

    int shortestSpan();
    int longestSpan();

    unsigned int size() const;
    int at(unsigned int i) const;
};

std::ostream& operator<<(std::ostream& os, const Span& obj);

#endif