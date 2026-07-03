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
              << "Nobody will remember that he ever existed."
              << RESET << std::endl;
}

void print_what_intern_create(std::string form_name)
{
    std::cout << "Intern creates " << form_name << std::endl;
}

static AForm* createShrub(const std::string& t) { return new ShrubberyCreationForm(t); }
static AForm* createRobo(const std::string& t) { return new RobotomyRequestForm(t); }
static AForm* createPardon(const std::string& t) { return new PresidentialPardonForm(t); }

AForm *Intern::makeForm(std::string const & form_name, std::string const & target)
{
    struct Map { const char* name; AForm* (*factory)(const std::string&); };
    const Map maps[] = {
        { "shrubbery creation", &createShrub },
        { "robotomy request", &createRobo },
        { "presidential pardon", &createPardon }
    };

    for (size_t i = 0; i < sizeof(maps)/sizeof(maps[0]); ++i)
    {
        if (form_name == maps[i].name)
        {
            print_what_intern_create(form_name);
            return maps[i].factory(target);
        }
    }

    std::cout << RED << "Unknown form: " << form_name
              << ". Available: shrubbery creation, robotomy request, presidential pardon"
              << RESET << std::endl;
    return NULL;
}

AForm *Intern::makeForm(std::string const *form_name, std::string const *target)
{
    static const std::string default_name = "default_form_name";
    static const std::string default_target = "default_target";

    const std::string &name = form_name ? *form_name : default_name;
    const std::string &tgt  = target ? *target : default_target;

    return makeForm(name, tgt);
}

AForm *Intern::makeForm(std::string const *form_name, std::string const &target)
{
    static const std::string default_name = "default_form_name";

    const std::string &name = form_name ? *form_name : default_name;
    return makeForm(name, target);
}

AForm *Intern::makeForm(std::string const &form_name, std::string const *target)
{
    static const std::string default_target = "default_target";

    const std::string &tgt = target ? *target : default_target;
    return makeForm(form_name, tgt);
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