#include "iter.hpp"
#include <iostream>
#include <cstring>

#define ORENGE "\033[38;2;255;165;0m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

template <typename T>
void print_blue(T& c)
{
    std::cout << BLUE << c << RESET << std::endl;
}

// Modified function to accept both const and non-const elements
template <typename T>
void print_orange(const T& c)
{
    std::cout << ORENGE << c << RESET << std::endl;
}

int main(void)
{
    std::cout << GREEN << "Array of ints: " << RESET << std::endl;
    int i[3] = {1, 2, 3};
    iter(i, 3,  print_blue);  // Works with non-const array
    std::cout << std::endl;

    std::cout << GREEN << "Array of chars: " << RESET << std::endl;
    char str[8] = "ABC,def";
    iter(str, strlen(str),  print_blue);  // Works with non-const array
    std::cout << std::endl;

    std::cout << GREEN << "Array of const ints: " << RESET << std::endl;
    const int arr[5] = {10, 20, 30, 40, 50};
    iter(arr, 5, print_orange);  // Now works with const array

    return 0;
}
