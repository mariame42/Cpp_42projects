#include "Intern.hpp"


Intern::Intern()
{
    std::cout << GREEN
              << "I am the constructor. I initialize someone "
              << "with no name, no grade, and no unique characteristics, "
              << "in a world full of bureaucrats."
              << RESET << std::endl;
}

Intern::~Intern()
{
    std::cout << ORANGE
              << "I am the destructor. I delete someone who does not have "
              << "a name, a grade, or any unique characteristics. "
              << "Nobody will remember that I ever existed."
              << RESET << std::endl;
}

void print_what_intern_create(std::string form_name)
{
    std::cout << "Intern creates " << form_name << std::endl;
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
    if (form_name == "ShrubberyCreationForm")
    {
        print_what_intern_create(form_name);
        return new ShrubberyCreationForm(target);
    }
    else if (form_name == "RobotomyRequestForm")
    {
        print_what_intern_create(form_name);
        return new RobotomyRequestForm(target);
    }
    else if (form_name == "PresidentialPardonForm")
    {
        print_what_intern_create(form_name);
        return new PresidentialPardonForm(target);
    }
    else 
    {
        std::cout << RED << "there is not form called "
                    << form_name << " pleause use one of those forms"
                    << " :\nShrubberyCreationForm\nRobotomyRequestForm\nPresidentialPardonForm"
                    << RESET << std::endl;
        return NULL;
    }
}

Intern::Intern(const Intern& other)
{
    (void)other;
    std::cout << ORANGE
              << "I am the copy constructer. I not usefull my class have no "
              << "name, no grade, or any unique characteristics. to be passed"
              << RESET << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    std::cout << ORANGE
              << "I am the copy assiment oprator. I not usefull my class have no "
              << "name, no grade, or any unique characteristics. to be passed"
              << RESET << std::endl;
    return (*this);
}
// ShrubberyCreationForm
// RobotomyRequestForm
// PresidentialPardonForm