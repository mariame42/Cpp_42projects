/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:08:23 by meid              #+#    #+#             */
/*   Updated: 2025/10/26 21:58:32 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{
    std::cout << "PresidentialPardonForm constructor" << std::endl;
    std::cout << get_sign_required() << " " << get_execute_required() << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor" << std::endl;
}

void PresidentialPardonForm::beSigned(Bureaucrat bureaucrat)
{
    
    std::cout << bureaucrat << std::endl;

    // size_t grade = bureaucrat.get_grade();
    // if (grade > _sign_required || grade > _execute_required)
    // throw GradeTooLowException();
    // _is_signed = true;
    // std::cout << GREEN << bureaucrat.get_name()
    // << " signed " << get_name() << RESET << std::endl;
}

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& obj)
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

#include <filesystem>
#include <fstream>



void PresidentialPardonForm::execute(Bureaucrat const & executor)
{
    if (get_is_signed() && executor.get_grade() < get_execute_required())
    {
        std::cout << get_name() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
    else
        std::cout << RED << "PresidentialPardonForm error" << RESET << std::endl;
}