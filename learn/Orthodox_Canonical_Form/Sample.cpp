
#include "Sample.hpp"


int main(void)
{
    std::cout << "--- Default constructor ---" << std::endl;
    Sample a;   // Default constructor is called

    std::cout << "\n--- Copy constructor ---" << std::endl;
    Sample b(a);   // Copy constructor is called (b created from a)

    std::cout << "\n--- Copy assignment operator ---" << std::endl;
    Sample c;      // Default constructor
    c = a;         // Copy assignment operator (c already exists)

    std::cout << "\n--- Destructor ---" << std::endl;
    // When main ends, destructors are called for a, b, c automatically

    return 0;
}
