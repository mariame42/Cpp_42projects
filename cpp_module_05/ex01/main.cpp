#include "Form.hpp"

int main()
{
    std::cout << Cyan << "\n=== safe testing ===" << RESET << std::endl;
    try
    {
        Form form("first form", 75, 75);
        Bureaucrat bureaucrat0("Mariam", 76);
        bureaucrat0.signForm(form);
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << RED << "Bureaucrat: GradeTooHighException: " << e.what() << RESET << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << RED << "Bureaucrat: GradeTooLowException: " << e.what() << RESET << std::endl;
    }
    catch(const Form::GradeTooHighException& e)
    {
        std::cerr << RED << "Form: GradeTooHighException: " << e.what() << RESET << std::endl;
    }
    catch(const Form::GradeTooLowException& e)
    {
        std::cerr << RED << "Form: GradeTooLowException: " << e.what() << RESET << std::endl;
    }
}