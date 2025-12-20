#ifndef ITER_HPP
# define ITER_HPP
#include <cstddef>
#include <iostream>
#include <string>
#include <cstring>

template <typename T>
void function(T* c)
{
    std::cout << c << std::endl;
}

template <typename T>
void iter(T* arr, const size_t length, void (* func)(T*))
{
    for (size_t i = 0; i < length; i++)
    {
        func(&arr[i]);
    }
    for (size_t i = 0; i < length; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

#endif