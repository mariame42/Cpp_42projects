#include <iostream>
#include "Array.hpp"

int main()
{
    Array<int> arrInt(5);
    for (unsigned int i = 0; i < arrInt.size(); i++)
        arrInt[i] = i * 10;
    for (unsigned int i = 0; i < arrInt.size(); i++)
        std::cout << arrInt[i] << std::endl;

    Array<std::string> arrStr(3);
    arrStr[0] = "Hello";
    arrStr[1] = "World";
    arrStr[2] = "!";
    for (unsigned int i = 0; i < arrStr.size(); i++)
        std::cout << arrStr[i] << " ";
    std::cout << std::endl;

    try
    {
        std::cout << arrInt[10] << std::endl; // This should throw an exception
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }


    return 0;
}