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
    
    Bureaucrat bureaucrat0("lol", 140);
    
    
    
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
}