#include "Form.hpp"

Form::Form(std::string name,
    size_t sign_required,
    size_t execute_required)
    : _name(name), _is_signed(false)
{
    if (sign_required < 1 || execute_required < 1)
        throw GradeTooHighException();
    if (sign_required > 150 || execute_required > 150)
        throw GradeTooLowException();

    _sign_required = sign_required;
    _execute_required = execute_required;
    std::cout << "Form constructor" << std::endl;
}


Form::~Form()
{
    std::cout << "Form destructor" << std::endl;
}



// std::ostream& operator<<(std::ostream& out, const Formt& obj)
// {
//     // <name>, Formt grade <grade>
//     out << Magenta << obj.get_name() << ", Formt sign status: " << obj.get_is_signed()() << RESET << std::endl;   // 👈 print extra text every time
//     return out;               // allow chaining
// }



std::string Form::get_name(){
    return (_name);
}

bool Form::get_is_signed(){
    return (_is_signed);
}

size_t Form::get_sign_required(){
    return (_sign_required);
}

size_t Form::get_execute_required(){
    return (_execute_required);
}

void Form::beSigned(Bureaucrat bureaucrat)
{
    size_t grade = bureaucrat.get_grade();
    if (grade < sign_required)
        throw GradeTooHighException();
    if (grade > execute_required)
        throw GradeTooLowException();
    _is_signed = true;
    std::cout << GREEN << bureaucrat.get_name()
        << "signed" << get_name() << RESET << std::endl;
}

