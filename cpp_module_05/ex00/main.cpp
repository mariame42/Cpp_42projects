#include "Bureaucrat.hpp"

int main()
{
    try
    {
        std::cout << "=== Testing string constructor ===" << std::endl;
        Bureaucrat bureaucrat1("John", 1);
        std::cout << bureaucrat1.get_name() << " has a grade of " << bureaucrat1.get_grade() << std::endl;
        
        std::cout << "\n=== Testing char* constructor with valid string ===" << std::endl;
        Bureaucrat bureaucrat2("Alice", 50);
        std::cout << bureaucrat2.get_name() << " has a grade of " << bureaucrat2.get_grade() << std::endl;
        
        std::cout << "\n=== Testing char* constructor with NULL ===" << std::endl;
        Bureaucrat bureaucrat3(NULL, 75);
        std::cout << bureaucrat3.get_name() << " has a grade of " << bureaucrat3.get_grade() << std::endl;
        
        std::cout << "\n=== Testing grade operations ===" << std::endl;
        bureaucrat1.increment_grade();
        std::cout << bureaucrat1.get_name() << " has a grade of " << bureaucrat1.get_grade() << std::endl;
        bureaucrat1.decrement_grade();
        std::cout << bureaucrat1.get_name() << " has a grade of " << bureaucrat1.get_grade() << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}