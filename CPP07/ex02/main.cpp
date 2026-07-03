#include <iostream>
#include "Array.hpp"

#define BLUE "\033[34m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"

int main()
{
    Array<int> arrInt(5);
    std::cout << BLUE << "Array of ints/ size = " << arrInt.size() << ": " << RESET << std::endl;
    for (unsigned int i = 0; i < arrInt.size(); i++)
        arrInt[i] = i * 10;
    for (unsigned int i = 0; i < arrInt.size(); i++)
        std::cout << GREEN << arrInt[i] << RESET << ", ";
    std::cout << std::endl;
    std::cout << std::endl;

    Array<std::string> arrStr(3);
    std::cout << BLUE << "Array of strings/ size = " << arrStr.size() << ": " << RESET << std::endl;
    arrStr[0] = "Hello";
    arrStr[1] = "World";
    arrStr[2] = "!";
    for (unsigned int i = 0; i < arrStr.size(); i++)
        std::cout << GREEN << arrStr[i] << RESET << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << BLUE << "Trying to access index 10 of array of ints that has size 5" << RESET << std::endl;
    try
    {
        std::cout << arrInt[10] << std::endl; // This should throw an exception
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
        std::cout << std::endl;
    }

    Array<std::string> constArr(3);
    // Test const access
    constArr[0] = "Hello";
    constArr[1] = "World";
    constArr[2] = "!";
    const Array<std::string>& constRef = constArr;
    std::cout << BLUE << "Array of const strings/ size = " << constArr.size() << ": " << RESET << std::endl;
    for (unsigned int i = 0; i < constRef.size(); i++)
        std::cout << GREEN << constRef[i] << RESET << " ";
    std::cout << std::endl;

    return 0;
}