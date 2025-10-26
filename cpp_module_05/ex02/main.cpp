/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:29:11 by meid              #+#    #+#             */
/*   Updated: 2025/10/26 19:03:26 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

// static const bool info =  0;

int main()
{
    AForm *form = new ShrubberyCreationForm();
    std::cout << form;
    
    
    // try {
    //     Bureaucrat bureaucrat0("lol", 18);
    //     std::cout << bureaucrat0;
    // }
    // catch(const std::exception& e) {
    //     std::cerr << RED << "CATCHED: " << e.what() << RESET << '\n';
    // }
}