#include "Span.hpp"

void success_test_00()
{
    std::cout << BLUE << "--------------------------------" << RESET << std::endl;
    std::cout << GREEN << "Success Test 00" << RESET << std::endl;
    std::cout << YELLOW << "This test does not cross the limit of the span." << RESET << std::endl;
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    try
    {
        std::cout << sp << std::endl;
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::runtime_error& e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << BLUE << "--------------------------------" << RESET << std::endl;
}

void success_test_01()
{
    std::cout << BLUE << "--------------------------------" << RESET << std::endl;
    std::cout << GREEN << "Success Test 01" << RESET << std::endl;
    std::cout << YELLOW << "This test adds 1000 numbers without exceeding the span limit." << RESET << std::endl;
    Span sp = Span(1000);

    for (int i = 0; i < 1000; i++)
        sp.addNumber(i);
    try
    {
        std::cout << sp << std::endl;
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::runtime_error& e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << BLUE << "--------------------------------" << RESET << std::endl;
}

void success_test_02()
{
    std::cout << BLUE << "--------------------------------" << RESET << std::endl;
    std::cout << GREEN << "Success Test 02" << RESET << std::endl;
    std::cout << YELLOW << "This test uses addRangeOfNumbers(0, 9999) and exceeds the span limit (1000)." << RESET << std::endl;
    
    Span sp = Span(1000);
    try
    {
        sp.addRangeOfNumbers(0, 9999);
        std::cout << sp << std::endl;
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::runtime_error& e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << BLUE << "--------------------------------" << RESET << std::endl;
}

void failure_test_00()
{
    std::cout << BLUE << "--------------------------------" << RESET << std::endl;
    std::cout << RED << "Failure Test 00" << RESET << std::endl;
    std::cout << YELLOW << "This test tries to add a number to a span with capacity 0 (already full)." << RESET << std::endl;
    Span sp = Span(0);
    try
    {
        sp.addNumber(1);
    }
    catch (const std::runtime_error& e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << BLUE << "--------------------------------" << RESET << std::endl;
}

void explain_output()
{
    std::cout << BLUE << "--------------------------------" << RESET << std::endl;
    std::cout << GREEN << "Explain Output" << RESET << std::endl;
    std::cout << YELLOW << "This exercise uses a Span class to compute the shortest and longest span between stored numbers. Error handling is done via exceptions." << RESET << std::endl;
    std::cout << "We have 4 tests:" << std::endl;
    std::cout << "  1. Success Test 00: Does not cross the span limit (5 numbers)." << std::endl;
    std::cout << "  2. Success Test 01: Adds 1000 numbers without exceeding the limit." << std::endl;
    std::cout << "  3. Success Test 02: addRangeOfNumbers(0, 9999) on a span of 1000; fills up and reports how many were added." << std::endl;
    std::cout << "  4. Failure Test 00: Tries to add to a span with capacity 0." << std::endl;
    std::cout << BLUE << "--------------------------------" << RESET << std::endl;
}

int main()
{
    success_test_00();
    success_test_01();
    success_test_02();
    failure_test_00();

    explain_output();
    return 0;
}