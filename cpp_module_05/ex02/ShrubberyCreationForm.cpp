/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:08:12 by meid              #+#    #+#             */
/*   Updated: 2025/10/26 19:04:11 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    set_execute_required(137);
    set_sign_required(145);
    std::cout << "ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

void ShrubberyCreationForm::beSigned(Bureaucrat bureaucrat)
{
    
    std::cout << bureaucrat << std::endl;

    // size_t grade = bureaucrat.get_grade();
    // if (grade > _sign_required || grade > _execute_required)
    // throw GradeTooLowException();
    // _is_signed = true;
    // std::cout << GREEN << bureaucrat.get_name()
    // << " signed " << get_name() << RESET << std::endl;
}

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& obj)
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
