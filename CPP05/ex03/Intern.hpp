#ifndef Intern_hpp
# define Intern_hpp

#include "iostream"
// #include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public :
        Intern();
        ~Intern();
        AForm *makeForm(std::string const & form_name, std::string const & target);
        AForm *makeForm(std::string const * form_name, std::string const * target);
        AForm *makeForm(std::string const * form_name, std::string const & target);
        AForm *makeForm(std::string const & form_name, std::string const * target);
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
};

#endif