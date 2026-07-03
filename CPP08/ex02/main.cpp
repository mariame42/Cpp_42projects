#include <iostream>
#include "MutantStack.hpp"

// testing functions
void occf_test();
void normal_test();
void const_test();
void reverse_test();
void const_reverse_test();
void explain_output();

int main()
{
    occf_test();
    normal_test();
    const_test();
    reverse_test();
    const_reverse_test();

    explain_output();
    return 0;
}

static void print_stack(const MutantStack<int>& stk)
{
    for (MutantStack<int>::const_iterator it = stk.begin(); it != stk.end(); it++)
        std::cout << *it << " ";
}

void occf_test()
{
    std::cout << BLUE << "--------------------------------" << RESET << std::endl;
    std::cout << GREEN << "OCCF Test (copy ctor & copy assignment)" << RESET << std::endl;
    std::cout << YELLOW << "Tests that MutantStack copy constructor and copy assignment work correctly." << RESET << std::endl;

    MutantStack<int> original;
    original.push(42);
    original.push(21);
    original.push(7);

    std::cout << "Original: ";
    print_stack(original);
    std::cout << std::endl;

    MutantStack<int> copy_ctor(original);
    std::cout << YELLOW << "Testing copy constructor..." << RESET << std::endl;
    std::cout << "After copy ctor\n\toriginal: ";
    print_stack(original);
    std::cout << "\n\tcopy: ";
    print_stack(copy_ctor);
    std::cout << std::endl;

    original.pop();
    std::cout << "After pop on original\n\toriginal: ";
    print_stack(original);
    std::cout << "\n\tcopy unchanged: ";
    print_stack(copy_ctor);
    std::cout << std::endl;

    std::cout << YELLOW << "Testing copy assignment..." << RESET << std::endl;
    MutantStack<int> assigned;
    assigned.push(99);
    std::cout << "Before assignment\n\toriginal: ";
    print_stack(original);
    std::cout << "\n\tassigned: ";
    print_stack(assigned);
    std::cout << std::endl;
    assigned = original;
    std::cout << "After assignment (assigned = original)\n\toriginal: ";
    print_stack(original);
    std::cout << "\n\tassigned: ";
    print_stack(assigned);
    std::cout << std::endl;
    std::cout << BLUE << "--------------------------------" << RESET << std::endl;
}

void normal_test()
{
    std::cout << GREEN << "--- normal_test (iterator: begin -> end) ---" << RESET << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
        std::cout << *it << std::endl;
}

void const_test()
{
    std::cout << GREEN << "--- const_test (const_iterator: begin -> end) ---" << RESET << std::endl;
    MutantStack<int> mstack;
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    const MutantStack<int>& ref = mstack;
    std::cout << "size: " << ref.size() << std::endl;
    for (MutantStack<int>::const_iterator it = ref.begin(); it != ref.end(); it++)
        std::cout << *it << std::endl;
}

void reverse_test()
{
    std::cout << GREEN << "--- reverse_test (reverse_iterator: rbegin -> rend) ---" << RESET << std::endl;
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    std::cout << "size: " << mstack.size() << std::endl;
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); it++)
        std::cout << *it << std::endl;
}

void const_reverse_test()
{
    std::cout << GREEN << "--- const_reverse_test (const_reverse_iterator: rbegin -> rend) ---" << RESET << std::endl;
    MutantStack<int> mstack;
    mstack.push(100);
    mstack.push(200);
    mstack.push(300);
    const MutantStack<int>& ref = mstack;
    std::cout << "size: " << ref.size() << std::endl;
    for (MutantStack<int>::const_reverse_iterator it = ref.rbegin(); it != ref.rend(); it++)
        std::cout << *it << std::endl;
}

void explain_output()
{
    std::cout << BLUE << "--------------------------------" << RESET << std::endl;
    std::cout << GREEN << "Explain Output" << RESET << std::endl;
    std::cout << YELLOW << "This exercise uses a MutantStack class to test the iterator functionality of the stack." << RESET << std::endl;
    std::cout << "We have 5 tests:" << std::endl;
    std::cout << "  1. OCCF Test: Copy constructor and copy assignment." << std::endl;
    std::cout << "  2. Normal Test: iterator: begin -> end" << std::endl;
    std::cout << "  3. Const Test: const_iterator: begin -> end" << std::endl;
    std::cout << "  4. Reverse Test: reverse_iterator: rbegin -> rend" << std::endl;
    std::cout << "  5. Const Reverse Test: const_reverse_iterator: rbegin -> rend" << std::endl;
    std::cout << BLUE << "--------------------------------" << RESET << std::endl;
}