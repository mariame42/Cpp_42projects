/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:56:16 by meid              #+#    #+#             */
/*   Updated: 2025/10/25 15:57:03 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
    std::cout << Cyan << "\n=== safe testing ===" << RESET << std::endl;
    try
    {
        Form form("first form", 1, 75);
        Bureaucrat bureaucrat0("Mariam", 22);
        bureaucrat0.signForm(form);
        std::cout << form;
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << RED << "Bureaucrat: GradeTooHighException: " << e.what() << RESET << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << RED << "Bureaucrat: GradeTooLowException: " << e.what() << RESET << std::endl;
    }
    catch(const Form::GradeTooHighException& e)
    {
        std::cerr << RED << "Form: GradeTooHighException: " << e.what() << RESET << std::endl;
    }
    catch(const Form::GradeTooLowException& e)
    {
        std::cerr << RED << "Form: GradeTooLowException: " << e.what() << RESET << std::endl;
    }
}