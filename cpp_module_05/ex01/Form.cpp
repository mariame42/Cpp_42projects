/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:56:05 by meid              #+#    #+#             */
/*   Updated: 2025/10/26 20:07:07 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name,
    size_t gradeToSign,
    size_t gradeToExecute)
    : _name(name), _is_signed(false),
    _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();

    if (OCCF)
        std::cout << "Form constructor" << std::endl;
}

Form::Form(std::string *name,
    size_t gradeToSign,
    size_t gradeToExecute)
    : _name("defualt_name"), _is_signed(false),
    _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute)
{
    name += 0;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();

    if (OCCF)
        std::cout << "Form constructor" << std::endl;
}


Form::Form(const Form& other) : _name(other._name), _is_signed(other._is_signed),
    _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    if (OCCF)
        std::cout << PURPLE << "Form copy constructor" << RESET << std::endl;
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->_is_signed = other._is_signed;
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

size_t Form::get_gradeToSign() const{
    return (_gradeToSign);
}

size_t Form::get_gradeToExecute() const{
    return (_gradeToExecute);
}

void Form::beSigned(Bureaucrat bureaucrat)
{

    size_t grade = bureaucrat.get_grade();
    if (grade > _gradeToSign)
        throw GradeTooLowException();
    _is_signed = true;
}

std::ostream& operator<<(std::ostream& out, const Form& obj)
{
    out << Magenta
        << "------------------------\n"
            << "form name: " << obj.get_name()
                << "\ngrade required to be signed: " << obj.get_gradeToSign()
                    << "\ngrade required to be executed: " << obj.get_gradeToExecute() << "\nand the form is currantly: ";
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