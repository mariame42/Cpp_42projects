/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:08:17 by meid              #+#    #+#             */
/*   Updated: 2025/10/26 22:06:45 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{
    std::cout << "RobotomyRequestForm constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor" << std::endl;
}

void RobotomyRequestForm::beSigned(Bureaucrat bureaucrat)
{
    size_t grade = bureaucrat.get_grade();
    if (grade > get_gradeToSign())
        throw GradeTooLowException();
    set_is_signed(true);
}

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& obj)
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

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (get_is_signed() && executor.get_grade() < get_gradeToExecute())
    {
        std::cout << "BZZZZZZZZZZZZZZZZZZZZZZ..." << std::endl;
        std::cout << "* drilling noises *" << std::endl;
        std::cout << get_name() << " has been robotomized successfully 50% of the time." << std::endl;
    }
    else
        throw NotEnoughToBeExecuted();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
    AForm(other)
{
    if (OCCF)
        std::cout << PURPLE << "ARobotomyRequestForm copy constructor" << RESET << std::endl;

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    if (OCCF)
        std::cout << YELLOW << "RobotomyRequestForm copy assignment operator" << RESET << std::endl;
    return (*this);
}