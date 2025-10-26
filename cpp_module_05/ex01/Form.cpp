/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:56:05 by meid              #+#    #+#             */
/*   Updated: 2025/10/26 17:01:53 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    if (OCCF)
        std::cout << "Form constructor" << std::endl;
}

Form::Form(std::string *name,
    size_t sign_required,
    size_t execute_required)
    : _name("defualt_name"), _is_signed(false)
{
    name += 0;
    if (sign_required < 1 || execute_required < 1)
        throw GradeTooHighException();
    if (sign_required > 150 || execute_required > 150)
        throw GradeTooLowException();

    _sign_required = sign_required;
    _execute_required = execute_required;
    if (OCCF)
        std::cout << "Form constructor" << std::endl;
}


Form::Form(const Form& other) : _name(other._name), _is_signed(other._is_signed),
    _sign_required(other._sign_required), _execute_required(other._execute_required)
{
    if (OCCF)
        std::cout << PURPLE << "Form copy constructor" << RESET << std::endl;
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        // _name is const, so it cannot be assigned after construction
        this->_is_signed = other._is_signed;
        this->_sign_required = other._sign_required;
        this->_execute_required = other._execute_required;
    } 
    if (OCCF)
        std::cout << YELLOW << "Form copy assignment operator" << RESET << std::endl;
    return (*this);
}

Form::~Form()
{
    if (OCCF)
        std::cout << ORANGE << "Form destructor" << RESET << std::endl;
}

std::string Form::get_name() const{
    return (_name);
}

bool Form::get_is_signed() const{
    return (_is_signed);
}

size_t Form::get_sign_required() const{
    return (_sign_required);
}

size_t Form::get_execute_required() const{
    return (_execute_required);
}

void Form::beSigned(Bureaucrat bureaucrat)
{

    size_t grade = bureaucrat.get_grade();
    if (grade > _sign_required || grade > _execute_required)
    throw GradeTooLowException();
    _is_signed = true;
    // std::cout << GREEN << bureaucrat.get_name()
    // << " signed " << get_name() << RESET << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Form& obj)
{
    out << Magenta
        << "------------------------\n"
            << "form name: " << obj.get_name()
                << "\ngrade required to be signed: " << obj.get_sign_required()
                    << "\ngrade required to be executed: " << obj.get_execute_required() << "\nand the form is currantly: ";
    if (obj.get_is_signed())
        out << "is signed";
    else
        out << "is not signed";
    out << "\n------------------------"<< RESET << std::endl;
    return out;
}


const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}