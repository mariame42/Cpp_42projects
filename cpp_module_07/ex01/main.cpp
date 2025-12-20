#include "iter.hpp"

#include <iostream>
#include <cstring>

#define ORENGE "\033[0;33m"
#define RESET "\033[0m"

template <typename T>
void function(T& c)
{
    std::cout << ORENGE << c << RESET << std::endl;
}

int main(void)
{
	int i[3];
	i[0] = 1;
	i[1] = 2;
	i[2] = 3;
	iter(i, 3, function);

	char str[8] = "loooool";
	iter(str, strlen(str), function);

	const int arr[5] = {10, 20, 30, 40, 50};
	iter(arr, 5, function);

	return 0;
}
