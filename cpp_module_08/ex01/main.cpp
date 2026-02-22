#include "Span.hpp"

// testing functions
void occf_test();
void success_test_00();
void success_test_01();
void success_test_02();
void failure_test_00();
void failure_test_01();
void explain_output();

int main()
{
    occf_test();
    success_test_00();
    success_test_01();
    success_test_02();
    failure_test_00();
    failure_test_01();

    explain_output(); // Function to explain the output 
    return 0;
}

void occf_test()
{
    std::cout << BLUE << "--------------------------------" << RESET << std::endl;
    std::cout << GREEN << "OCCF Test (copy ctor & copy assignment)" << RESET << std::endl;
    std::cout << YELLOW << "Tests that Span copy constructor and copy assignment work correctly." << RESET << std::endl;

    Span original(5);
    original.addNumber(10);
    original.addNumber(20);
    original.addNumber(30);

    std::cout << "Original: " << original << std::endl;
    std::cout << "Shortest Span: " << original.shortestSpan() << ", Longest Span: " << original.longestSpan() << std::endl;

    Span copy_ctor(original);
    std::cout << YELLOW << "Testing copy constructor..." << RESET << std::endl;
    std::cout << "After copy ctor, copy: " << copy_ctor << std::endl;
    std::cout << "Copy shortest/longest: " << copy_ctor.shortestSpan() << " / " << copy_ctor.longestSpan() << std::endl;

    original.addNumber(40);
    std::cout << "After addNumber(40) on original\n\torginal: " << original << "\n\tcopy unchanged: " << copy_ctor << std::endl;

    std::cout << YELLOW << "Testing copy assignment..." << RESET << std::endl;
    Span assigned(3);
    assigned.addNumber(1);
    std::cout << "Before assignment\n\t original: " << original << "\n\t assigned: " << assigned << std::endl;
    assigned = original;
    std::cout << "After assignment (assigned = original)\n\t original: " << original << "\n\t assigned: " << assigned << std::endl;
    std::cout << BLUE << "--------------------------------" << RESET << std::endl;
}

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
    int span_size = 1000;
    std::cout << BLUE << "--------------------------------" << RESET << std::endl;
    std::cout << GREEN << "Success Test 02" << RESET << std::endl;
    std::cout << YELLOW << "This test uses addRange() to add a range at the same size as the span capacity (1000)" << RESET << std::endl;

    Span sp = Span(span_size);
    std::vector<int> data;
    for (int i = 0; i < span_size; ++i)
        data.push_back(i);
    try
    {
        sp.addRange(data.begin(), data.end());
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


void failure_test_01()
{
    int span_size = 1000;
    std::cout << BLUE << "--------------------------------" << RESET << std::endl;
    std::cout << RED << "Failure Test 01" << RESET << std::endl;
    std::cout << YELLOW << "This test uses addRange() to add a range larger than the span capacity (1000); expect an exception." << RESET << std::endl;

    Span sp = Span(span_size);
    std::vector<int> data;
    for (int i = 0; i < span_size + 1; ++i)
        data.push_back(i);
    try
    {
        sp.addRange(data.begin(), data.end());
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

void explain_output()
{
    std::cout << BLUE << "--------------------------------" << RESET << std::endl;
    std::cout << GREEN << "Explain Output" << RESET << std::endl;
    std::cout << YELLOW << "This exercise uses a Span class to compute the shortest and longest span between stored numbers. Error handling is done via exceptions." << RESET << std::endl;
    std::cout << "We have 6 tests:" << std::endl;
    std::cout << "  1. OCCF Test: Copy constructor and copy assignment." << std::endl;
    std::cout << "  2. Success Test 00: Does not cross the span limit (5 numbers)." << std::endl;
    std::cout << "  3. Success Test 01: Adds 1000 numbers without exceeding the limit." << std::endl;
    std::cout << "  4. Success Test 02: addRange() with the same size as the span capacity (1000)." << std::endl;
    std::cout << "  5. Failure Test 00: Tries to add to a span with capacity 0." << std::endl;
    std::cout << "  6. Failure Test 01: Tries to add a range larger than the span capacity (1000)." << std::endl;
    std::cout << BLUE << "--------------------------------" << RESET << std::endl;
}