#include "whatever.hpp"
#include <iostream>
#include <string>

#define GREEN "\033[32m"
#define RESET "\033[0m"

int main(void)
{
	int a = 2;
	int b = 3;

	std::cout << GREEN << "Before swap: " << RESET << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << GREEN << "After swap: " << RESET << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "min and max of a and b: " << RESET << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::cout << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << GREEN << "Before swap: " << RESET << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << GREEN << "After swap: " << RESET << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "min and max of c and d: " << RESET << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	return 0;
}
