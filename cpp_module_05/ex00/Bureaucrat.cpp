#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _max_gride(1), _min_gride(150)
{
    std::cout << "constructor is here" << std::endl;
    if (grade < 1)
        throw std::out_of_range("Grade is too high");
    if (grade > 150)
        throw std::out_of_range("Grade is too low");
    _grade = grade;
}

Bureaucrat::Bureaucrat(char *name, int grade) : _name(name ? std::string(name) : "default_name"), _max_gride(1), _min_gride(150)
{
    std::cout << "constructor for the char* parameter" << std::endl;
    if (grade < 1)
        throw std::out_of_range("Grade is too high");
    if (grade > 150)
        throw std::out_of_range("Grade is too low");
    _grade = grade;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "destructor is here" << std::endl;
}

const std::string   Bureaucrat::get_name() const{
    return (_name);
}

size_t              Bureaucrat::get_grade() const{
    return (_grade);
}

void                Bureaucrat::increment_grade(){
    if (_grade == 1)
        throw std::out_of_range("1 is the highist grade");
    _grade--;
}

void                Bureaucrat::decrement_grade()
{
    if (_grade == 150)
        throw std::out_of_range("150 is the lowest grade");
    _grade++;
}