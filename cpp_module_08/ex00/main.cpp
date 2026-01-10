#include "easyfind.hpp"

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

#include <vector>
void vector_test()
{
    std::cout << MAGENTA << "=== Vector Test ===" << RESET << std::endl;
    std::vector<int> vec;
    for (int i = 1; i <= 5; ++i)
        vec.push_back(i * 10);

    std::cout << BLUE << "Vector contents: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << RESET << std::endl;

    try
    {
        std::cout << CYAN << "Searching for 30..." << RESET << std::endl;
        int index = easyfind(vec, 30);
        std::cout << GREEN << "Found at index: " << index << RESET << std::endl;
    }
    catch (const std::runtime_error& e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    try
    {
        std::cout << CYAN << "Searching for 100..." << RESET << std::endl;
        int index = easyfind(vec, 100);
        std::cout << GREEN << "Found at index: " << index << RESET << std::endl;
    }
    catch (const std::runtime_error& e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;
}

#include <list>
void list_test()
{
    std::cout << MAGENTA << "=== List Test ===" << RESET << std::endl;
    std::list<int> lst;
    for (int i = 1; i <= 5; ++i)
        lst.push_back(i * 15);

    std::cout << BLUE << "List contents: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;

    try
    {
        std::cout << CYAN << "Searching for 45..." << RESET << std::endl;
        int index = easyfind(lst, 45);
        std::cout << GREEN << "Found at index: " << index << RESET << std::endl;
    }
    catch (const std::runtime_error& e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    try
    {
        std::cout << CYAN << "Searching for 100..." << RESET << std::endl;
        int index = easyfind(lst, 100);
        std::cout << GREEN << "Found at index: " << index << RESET << std::endl;
    }
    catch (const std::runtime_error& e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;
}

#include <deque>
void deque_test()
{
    std::cout << MAGENTA << "=== Deque Test ===" << RESET << std::endl;
    std::deque<int> deq;
    for (int i = 1; i <= 5; ++i)
        deq.push_back(i * 20);
    std::cout << BLUE << "Deque contents: ";
    for (size_t i = 0; i < deq.size(); ++i)
        std::cout << deq[i] << " ";
    std::cout << RESET << std::endl;

    try
    {
        std::cout << CYAN << "Searching for 60..." << RESET << std::endl;
        int index = easyfind(deq, 60);
        std::cout << GREEN << "Found at index: " << index << RESET << std::endl;
    }
    catch (const std::runtime_error& e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    try
    {
        std::cout << CYAN << "Searching for 100..." << RESET << std::endl;
        int index = easyfind(deq, 100);
        std::cout << GREEN << "Found at index: " << index << RESET << std::endl;
    }
    catch (const std::runtime_error& e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;
}

void explain_output()
{
    std::cout << YELLOW << "Output Explanation:" << RESET << std::endl;
    std::cout << YELLOW << "The program tests the easyfind function with different containers (vector, list, deque) and values." << RESET << std::endl;
    std::cout << YELLOW << "It prints the contents of each container, searches for specific values, and indicates whether they were found or not." << RESET << std::endl;

    std::cout << YELLOW << "I want to expalin the defrence between each type of contaner :" << RESET << std::endl;
    std::cout << YELLOW << "1. Vector: A dynamic array that allows random access to elements. It is efficient for accessing elements by index." << RESET << std::endl;
    std::cout << YELLOW << "2. List: A doubly linked list that allows efficient insertions and deletions at any position but does not support random access." << RESET << std::endl;
    std::cout << YELLOW << "3. Deque: A double-ended queue that allows insertions and deletions at both ends. It supports random access like a vector." << RESET << std::endl;
    std::cout << YELLOW << "The easyfind function works with all these containers by iterating through their elements to find the specified value." << RESET << std::endl;

}

int main()
{
    vector_test();
    list_test();
    deque_test();

    explain_output(); // Function to explain the output format
    return 0;
}