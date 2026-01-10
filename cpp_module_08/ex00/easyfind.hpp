#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iterator>
#include <stdexcept>

// Container = a type that stores multiple elements and can be iterated
template <typename T>
int easyfind(T& container, int value)
{
    for (typename T::iterator it = container.begin(); it != container.end(); ++it)
    {
        if (*it == value)
            return std::distance(container.begin(), it);
    }
    throw std::runtime_error("Value not found in container");
}

#endif