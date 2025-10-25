#include "Bureaucrat.hpp"

int main()
{

    std::cout << Cyan << "\n=== safe testing ===" << RESET << std::endl;
    try
    {
        Bureaucrat bureaucrat0("Mariam", 50);
        std::cout << bureaucrat0;
        bureaucrat0.increment_grade();
        std::cout << bureaucrat0;
        bureaucrat0.increment_grade();
        std::cout << bureaucrat0;
        bureaucrat0.decrement_grade();
        std::cout << bureaucrat0;
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << RED << "GradeTooHighException: " << e.what() << RESET << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << RED << "GradeTooLowException: " << e.what() << RESET << std::endl;
    }

    std::cout << Cyan << "\n=== high grade ===" << RESET << std::endl;
    try
    {
        Bureaucrat bureaucrat1("John", 1);
        std::cout << bureaucrat1;
        bureaucrat1.increment_grade();
        std::cout << bureaucrat1;
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << RED << "GradeTooHighException: " << e.what() << RESET << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << RED << "GradeTooLowException: " << e.what() << RESET << std::endl;
    }
        
    std::cout << Cyan << "\n=== low grade ===" << RESET << std::endl;
    try
    {
        Bureaucrat bureaucrat2("Alice", 150);
        std::cout << bureaucrat2;
        bureaucrat2.decrement_grade();
        std::cout << bureaucrat2;
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << RED << "GradeTooHighException: " << e.what() << RESET << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << RED << "GradeTooLowException: " << e.what() << RESET << std::endl;
    }

    std::cout << Cyan << "\n=== null in the name ===" << RESET << std::endl;
    try
    {
        Bureaucrat bureaucrat3(NULL, 75);
        std::cout << bureaucrat3;
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << RED << "GradeTooHighException: " << e.what() << RESET << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << RED << "GradeTooLowException: " << e.what() << RESET << std::endl;
    }
    
    std::cout << Cyan << "\n=== high grade while constructing ===" << RESET << std::endl;
    try
    {
        Bureaucrat bureaucrat1("John", 0);
        std::cout << bureaucrat1;
        bureaucrat1.increment_grade();
        std::cout << bureaucrat1;
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << RED << "GradeTooHighException: " << e.what() << RESET << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << RED << "GradeTooLowException: " << e.what() << RESET << std::endl;
    }
        
    std::cout << Cyan << "\n=== low grade while constructing ===" << RESET << std::endl;
    try
    {
        Bureaucrat bureaucrat2("Alice", 151);
        std::cout << bureaucrat2;
        bureaucrat2.decrement_grade();
        std::cout << bureaucrat2;
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << RED << "GradeTooHighException: " << e.what() << RESET << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << RED << "GradeTooLowException: " << e.what() << RESET << std::endl;
    }
}