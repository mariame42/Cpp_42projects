/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:29:11 by meid              #+#    #+#             */
/*   Updated: 2025/10/30 09:38:53 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"

// static const bool info =  0;
// shrubbery creation
// robotomy request
// presidential pardon

int main()
{
    Intern intern;

    AForm *form1 = intern.makeForm("shrubbery creation", NULL);
    AForm *form = intern.makeForm("shrubbery creation", "potato");
    
    if (form)
    {
        Bureaucrat bureaucrat0("lol", 1);
        bureaucrat0.signForm(*form);
        bureaucrat0.executeForm(*form);
    }
    if (form1)
    {
        Bureaucrat bureaucrat0("lol", 1);
        bureaucrat0.signForm(*form1);
        bureaucrat0.executeForm(*form1);
    }
}