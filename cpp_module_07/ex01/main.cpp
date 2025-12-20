#include "iter.hpp"

#include <iostream>
#include <cstring>

#define ORENGE "\033[0;33m"
#define RESET "\033[0m"
#define GREEN "\033[32m"

template <typename T>
void function(T& c)
{
    std::cout << ORENGE << c << RESET << std::endl;
}

int main(void)
{
	std::cout << GREEN << "Array of ints: " << RESET << std::endl;
	int i[3] = {1, 2, 3};
	iter(i, 3, function);
	std::cout << std::endl;

	std::cout << GREEN << "Array of chars: " << RESET << std::endl;
	char str[8] = "ABC,def";
	iter(str, strlen(str), function);
	std::cout << std::endl;

	std::cout << GREEN << "Array of const ints: " << RESET << std::endl;
	const int arr[5] = {10, 20, 30, 40, 50};
	iter(arr, 5, function);
	std::cout << std::endl;

	return 0;
}
