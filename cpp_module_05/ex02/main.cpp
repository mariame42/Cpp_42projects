/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:29:11 by meid              #+#    #+#             */
/*   Updated: 2025/10/26 22:07:48 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// static const bool info =  0;

int main()
{
    AForm *form = new ShrubberyCreationForm("hello");
    AForm *form01 = new RobotomyRequestForm("hello");
    AForm *form02 = new PresidentialPardonForm("hello");
    
    Bureaucrat bureaucrat0("lol", 122);
    Bureaucrat bureaucrat1("lol", 1);

    
    
    
    try {
        form->execute(bureaucrat0);
    }
    catch(const std::exception& e) {
        std::cerr << RED << "CATCHED: " << e.what() << RESET << '\n';
    }
    try {
        form01->execute(bureaucrat0);
    }
    catch(const std::exception& e) {
        std::cerr << RED << "CATCHED: " << e.what() << RESET << '\n';
    }
    try {
        form02->execute(bureaucrat0);
    }
    catch(const std::exception& e) {
        std::cerr << RED << "CATCHED: " << e.what() << RESET << '\n';
    }

    bureaucrat0.signForm(*form);
    bureaucrat0.signForm(*form01);
    bureaucrat0.signForm(*form02);
    

    bureaucrat0.executeForm(*form);
    bureaucrat0.executeForm(*form01);
    bureaucrat0.executeForm(*form02);

    try {
        form->execute(bureaucrat1);
    }
    catch(const std::exception& e) {
        std::cerr << RED << "CATCHED: " << e.what() << RESET << '\n';
    }
    try {
        form01->execute(bureaucrat1);
    }
    catch(const std::exception& e) {
        std::cerr << RED << "CATCHED: " << e.what() << RESET << '\n';
    }
    try {
        form02->execute(bureaucrat1);
    }
    catch(const std::exception& e) {
        std::cerr << RED << "CATCHED: " << e.what() << RESET << '\n';
    }

    bureaucrat1.signForm(*form);
    bureaucrat1.signForm(*form01);
    bureaucrat1.signForm(*form02);

    bureaucrat1.executeForm(*form);
    bureaucrat1.executeForm(*form01);
    bureaucrat1.executeForm(*form02);

}