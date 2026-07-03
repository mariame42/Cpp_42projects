/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:08:17 by meid              #+#    #+#             */
/*   Updated: 2025/10/30 08:12:32 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{
    std::cout << "RobotomyRequestForm constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string *target) : AForm(target, 72, 45)
{
    std::cout << "RobotomyRequestForm constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor" << std::endl;
}

void RobotomyRequestForm::beSigned(const Bureaucrat& bureaucrat)
{
    size_t grade = bureaucrat.getGrade();
    if (grade > getGradeToSign())
        throw GradeTooLowException();
    set_is_signed(true);
}

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& obj)
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

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (get_is_signed() && executor.getGrade() <= getGradeToExecute())
    {
        std::cout << "BZZZZZZZZZZZZZZZZZZZZZZ..." << std::endl;
        std::cout << "* drilling noises *" << std::endl;
        static bool seeded = false;
        if (!seeded) { std::srand(static_cast<unsigned int>(std::time(NULL))); seeded = true; }
        if (std::rand() % 2 == 0)
            std::cout << getName() << " has been robotomized successfully." << std::endl;
        else
            std::cout << getName() << " robotomy failed." << std::endl;
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