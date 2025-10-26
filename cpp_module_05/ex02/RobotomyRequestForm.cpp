/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:08:17 by meid              #+#    #+#             */
/*   Updated: 2025/10/26 21:58:06 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{
    std::cout << "RobotomyRequestForm constructor" << std::endl;
    std::cout << get_sign_required() << " " << get_execute_required() << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor" << std::endl;
}

void RobotomyRequestForm::beSigned(Bureaucrat bureaucrat)
{
    
    std::cout << bureaucrat << std::endl;

    // size_t grade = bureaucrat.get_grade();
    // if (grade > _sign_required || grade > _execute_required)
    // throw GradeTooLowException();
    // _is_signed = true;
    // std::cout << GREEN << bureaucrat.get_name()
    // << " signed " << get_name() << RESET << std::endl;
}

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& obj)
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



void RobotomyRequestForm::execute(Bureaucrat const & executor)
{
    if (get_is_signed() && executor.get_grade() < get_execute_required())
    {
        std::cout << "BZZZZZZZZZZZZZZZZZZZZZZ..." << std::endl;
        std::cout << "* drilling noises *" << std::endl;
        std::cout << get_name() << " has been robotomized successfully 50% of the time." << std::endl;
    }
    else
        std::cout << RED << "RobotomyRequestForm error" << RESET << std::endl;
}
