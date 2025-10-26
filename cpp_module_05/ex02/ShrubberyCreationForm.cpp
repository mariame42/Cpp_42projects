/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:08:12 by meid              #+#    #+#             */
/*   Updated: 2025/10/26 22:06:38 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{
    std::cout << "ShrubberyCreationForm constructor" << std::endl;
    std::cout << get_sign_required() << " " << get_execute_required() << std::endl;
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

#include <filesystem>
#include <fstream>



void ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
    if (get_is_signed() && executor.get_grade() < get_execute_required())
    {
        std::string file_name =  get_name() + "_shrubbery";
        std::ofstream out(file_name.c_str(), std::ios::out | std::ios::trunc);    
        if (!out.is_open())
            std::cerr << "Error: could not open output file." << std::endl;
        
            for (int i = 0; i < 3; i++)
            {
                out << "                                                         ." <<
                    "                                              .         ;\n" <<
                    "                .              .              ;%     ;;\n" <<  
                    "                   ,           ,                :;%  %;\n" <<   
                    "                    :         ;                   :;%;'     .,\n" <<  
                    "           ,.        %;     %;            ;        %;'    ,;\n" <<
                    "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n" <<
                    "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n" <<
                    "               ;%;      %;        ;%;        % ;%;  ,%;'\n" <<
                    "                `%;.     ;%;     %;'         `;%%;.%;'\n" <<
                    "                 `:;%.    ;%%. %@;        %; ;@%;%'\n" <<
                    "                    `:%;.  :;bd%;          %;@%;'\n" <<
                    "                      `@%:.  :;%.         ;@@%;'\n" <<   
                    "                        `@%.  `;@%.      ;@@%; \n" <<        
                    "                          `@%%. `@%%    ;@@%; \n" <<       
                    "                            ;@%. :@%%  %@@%; \n" <<      
                    "                              %@bd%%%bd%%:; \n" <<    
                    "                                #@%%%%%:;;\n" <<
                    "                                %@@%%%::;\n" <<
                    "                                %@@@%(o);  . '\n" <<         
                    "                                %@@@o%;:(.,'\n" <<         
                    "                            `.. %@@@o%::;\n" <<         
                    "                               `)@@@o%::; \n" <<        
                    "                                %@@(o)::; \n" <<       
                    "                               .%@@@@%::;  \n" <<       
                    "                               ;%@@@@%::;.  \n" <<        
                    "                              ;%@@@@%%:;;;. \n" <<
                    "                          ...;%@@@@@%%:;;;;,.. " << std::endl;
            }
        
    }
    else
        throw NotEnoughToBeExecuted();
}