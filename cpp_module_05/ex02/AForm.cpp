/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:21:33 by meid              #+#    #+#             */
/*   Updated: 2025/10/30 07:34:36 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"

AForm::AForm(std::string name,
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
        std::cout << "AForm constructor" << std::endl;
}

AForm::AForm(std::string *name,
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
        std::cout << "AForm constructor" << std::endl;
}


AForm::AForm(const AForm& other) : _name(other._name), _is_signed(other._is_signed),
    _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    if (OCCF)
        std::cout << PURPLE << "AForm copy constructor" << RESET << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->_is_signed = other._is_signed;
    if (OCCF)
        std::cout << YELLOW << "AForm copy assignment operator" << RESET << std::endl;
    return (*this);
}

AForm::~AForm()
{
    if (OCCF)
        std::cout << ORANGE << "AForm destructor" << RESET << std::endl;
}

std::string AForm::getName() const{
    return (_name);
}

bool AForm::get_is_signed() const{
    return (_is_signed);
}

size_t AForm::getGradeToSign() const{
    return (_gradeToSign);
}

size_t AForm::getGradeToExecute() const{
    return (_gradeToExecute);
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
    out << Magenta
        << "------------------------\n"
            << "Aform name: " << obj.getName()
                << "\ngrade required to be signed: " << obj.getGradeToSign()
                    << "\ngrade required to be executed: " << obj.getGradeToExecute() << "\nand the Aform is currantly: ";
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

void AForm::set_is_signed(bool is_signed)
{
    _is_signed = is_signed;
}