/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:56:16 by meid              #+#    #+#             */
/*   Updated: 2025/10/26 17:29:05 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

static const bool info =  0;

void test_form_program(std::string testname,
    std::string bureaucrat_name, size_t bureaucrat_grade,
    std::string form_name, size_t required_to_sgin, size_t required_to_execute)
{
    std::cout << Cyan << "\n=== " << testname << " ===" << RESET << std::endl;
    Form form(form_name, required_to_sgin, required_to_execute);
    Bureaucrat bureaucrat0(bureaucrat_name, bureaucrat_grade);
    bureaucrat0.signForm(form);
    if (info)
    {
        std::cout << form;
        std::cout << bureaucrat0;   
    }
}

int main()
{
    // will just catch something if the error is in 
    // Bureaucrat class : 1/ constructing  2/ increment_grade   3/ decrement_grade
    // form class : 1/ constructing 2/beSigned
    // the function signForm in the Bureaucrat class have a catch block

    {
        try {
            test_form_program("safe testing",
                "Mariam", 75,
                "first form", 75, 75);
        }
        catch(const std::exception& e) {
            std::cerr << RED << "CATCHED: " << e.what() << RESET << '\n';
        }
    }
    {
        try {
            test_form_program("giving a high grade for the bureaucrat ",
                "Mariam", 0,
                "secound form", 75, 75);
        }
        catch(const std::exception& e) {
            std::cerr << RED << "CATCHED: " << e.what() << RESET << '\n';
        }
        
    }
    {
        try {
            test_form_program("giving a low grade for the bureaucrat ",
                "Mariam", 150,
                "third form", 75, 75);
        }
        catch(const std::exception& e) {
            std::cerr << RED << "CATCHED: " << e.what() << RESET << '\n';
        }   
    }
    {
        try {
            test_form_program("high grade from the form ",
                "Mariam", 74,
                "forth form", 75, 75);
        }
        catch(const std::exception& e) {
            std::cerr << RED << "CATCHED: " << e.what() << RESET << '\n';
        }
    }
    {
        try {
            test_form_program("low grade from the form ",
                "Mariam", 76,
                "fifth form", 75, 75);
        }
        catch(const std::exception& e) {
            std::cerr << RED << "CATCHED: " << e.what() << RESET << '\n';
        }
    }
    {
        try {
            test_form_program("high grade while constructing ",
                "Mariam", 76,
                "sixth form", 151, 75);
        }
        catch(const std::exception& e) {
            std::cerr << RED << "CATCHED: " << e.what() << RESET << '\n';
        }
    }
    {
        try {
            test_form_program("low grade while constructing ",
                "Mariam", 76,
                "seventh form", 0, 75);
        }
        catch(const std::exception& e) {
            std::cerr << RED << "CATCHED: " << e.what() << RESET << '\n';
        }
    }
}