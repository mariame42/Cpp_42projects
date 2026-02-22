#ifndef EASYFIND_HPP
# define EASYFIND_HPP

// -------------------------- INCLUDES --------------------------

#include <iterator>
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
// Container = a type that stores multiple elements and can be iterated
// like a vector, list, deque, etc.

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    for (typename T::iterator it = container.begin(); it != container.end(); ++it)
    {
        if (*it == value)
            return it;
    }
    throw std::runtime_error("Value not found in container");
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
    {
        if (*it == value)
            return it;
    }
    throw std::runtime_error("Value not found in container");
}

// easyfind is a template function that takes a container and a value
// and returns the iterator to the value in the container
// if the value is not found, it throws a runtime error

#endif