#ifndef EASYFIND_HPP
# define EASYFIND_HPP

// -------------------------- INCLUDES --------------------------

#include <algorithm>   // std::find
#include <stdexcept>
#include <iostream>

// -------------------------- COLOR MACROS --------------------------
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

// -------------------------- TEMPLATE FUNCTION --------------------------
// T must be a sequence container of integers (vector, list, deque, etc.)
// with begin(), end() and iterator types. Associative containers not required.

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found in container");
    return it;
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found in container");
    return it;
}

// easyfind is a template function that takes a container and a value
// and returns the iterator to the value in the container
// if the value is not found, it throws a runtime error

#endif