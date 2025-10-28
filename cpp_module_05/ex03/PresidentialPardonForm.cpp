/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:08:23 by meid              #+#    #+#             */
/*   Updated: 2025/10/26 22:06:50 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{
    std::cout << "PresidentialPardonForm constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor" << std::endl;
}

void PresidentialPardonForm::beSigned(Bureaucrat bureaucrat)
{
    size_t grade = bureaucrat.get_grade();
    if (grade > get_gradeToSign())
        throw GradeTooLowException();
    set_is_signed(true);
}

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& obj)
{
    out << Magenta
        << "------------------------\n"
            << "Aform name: " << obj.get_name()
                << "\ngrade required to be signed: " << obj.get_gradeToSign()
                    << "\ngrade required to be executed: " << obj.get_gradeToExecute() << "\nand the Aform is currantly: ";
    if (obj.get_is_signed())
        out << "is signed";
    else
        out << "is not signed";
    out << "\n------------------------"<< RESET << std::endl;
    return out;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (get_is_signed() && executor.get_grade() < get_gradeToExecute())
    {
        std::cout << get_name() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
    else
        throw NotEnoughToBeExecuted();
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
    AForm(other)
{
    if (OCCF)
        std::cout << PURPLE << "PresidentialPardonForm copy constructor" << RESET << std::endl;

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    if (OCCF)
        std::cout << YELLOW << "PresidentialPardonForm copy assignment operator" << RESET << std::endl;
    return (*this);
}