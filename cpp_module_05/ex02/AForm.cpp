/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:21:33 by meid              #+#    #+#             */
/*   Updated: 2025/10/26 22:05:58 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"

// AForm::AForm() : _name("defualt_name")
// {
//     if (OCCF)
//         std::cout << "AForm constructor" << std::endl;
// }

AForm::AForm(std::string name,
    size_t sign_required,
    size_t execute_required)
    : _name(name), _is_signed(false),
    _sign_required(sign_required),
    _execute_required(execute_required)
{
    if (sign_required < 1 || execute_required < 1)
        throw GradeTooHighException();
    if (sign_required > 150 || execute_required > 150)
        throw GradeTooLowException();

    if (OCCF)
        std::cout << "AForm constructor" << std::endl;
}

AForm::AForm(std::string *name,
    size_t sign_required,
    size_t execute_required)
    : _name("defualt_name"), _is_signed(false),
    _sign_required(sign_required),
    _execute_required(execute_required)
{
    name += 0;
    if (sign_required < 1 || execute_required < 1)
        throw GradeTooHighException();
    if (sign_required > 150 || execute_required > 150)
        throw GradeTooLowException();

    if (OCCF)
        std::cout << "AForm constructor" << std::endl;
}


AForm::AForm(const AForm& other) : _name(other._name), _is_signed(other._is_signed),
    _sign_required(other._sign_required), _execute_required(other._execute_required)
{
    if (OCCF)
        std::cout << PURPLE << "AForm copy constructor" << RESET << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        // _name is const, so it cannot be assigned after construction
        this->_is_signed = other._is_signed;
        // this->_sign_required = other._sign_required;
        // this->_execute_required = other._execute_required;
    } 
    if (OCCF)
        std::cout << YELLOW << "AForm copy assignment operator" << RESET << std::endl;
    return (*this);
}

AForm::~AForm()
{
    if (OCCF)
        std::cout << ORANGE << "AForm destructor" << RESET << std::endl;
}

std::string AForm::get_name() const{
    return (_name);
}

bool AForm::get_is_signed() const{
    return (_is_signed);
}

size_t AForm::get_sign_required() const{
    return (_sign_required);
}

size_t AForm::get_execute_required() const{
    return (_execute_required);
}

// void AForm::beSigned(Bureaucrat bureaucrat)
// {

//     size_t grade = bureaucrat.get_grade();
//     if (grade > _sign_required || grade > _execute_required)
//     throw GradeTooLowException();
//     _is_signed = true;
//     // std::cout << GREEN << bureaucrat.get_name()
//     // << " signed " << get_name() << RESET << std::endl;
// }

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
    out << Magenta
        << "------------------------\n"
            << "Aform name: " << obj.get_name()
                << "\ngrade required to be signed: " << obj.get_sign_required()
                    << "\ngrade required to be executed: " << obj.get_execute_required() << "\nand the Aform is currantly: ";
    if (obj.get_is_signed())
        out << "is signed";
    else
        out << "is not signed";
    out << "\n------------------------"<< RESET << std::endl;
    return out;
}


const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char* AForm::NotEnoughToBeExecuted::what() const throw()
{
    return "not enough to be executed";
}