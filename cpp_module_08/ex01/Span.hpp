#ifndef SPAN_HPP
# define SPAN_HPP

// span mean "a range or interval between two points"
#include <iostream>
#include <stdexcept>
#include <climits>
#include <algorithm>
#include <vector>

#define PRINTING_LIMIT 20

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"
#define ORANGE "\033[38;2;255;165;0m"

class Span
{
    private:
        unsigned int    _n;
        std::vector<int>  _data;
        unsigned int    _currentSize;

        friend std::ostream& operator<<(std::ostream& os, const Span& obj);
    
    public:
        Span();
        Span(unsigned int n);
        void addNumber(int number);
        void addRangeOfNumbers(int start, int end);
        int shortestSpan();;
        int longestSpan();
        ~Span();
};

std::ostream& operator<<(std::ostream& os, const Span& obj);

#endif