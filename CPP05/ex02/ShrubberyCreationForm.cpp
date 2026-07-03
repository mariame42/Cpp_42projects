/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:08:12 by meid              #+#    #+#             */
/*   Updated: 2025/10/30 08:12:49 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{
    std::cout << "ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string *target) : AForm(target, 145, 137)
{
    std::cout << "ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

void ShrubberyCreationForm::beSigned(const Bureaucrat& bureaucrat)
{
    size_t grade = bureaucrat.getGrade();
    if (grade > getGradeToSign())
        throw GradeTooLowException();
    set_is_signed(true);
}

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& obj)
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

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (get_is_signed() && executor.getGrade() <= getGradeToExecute())
    {
        std::string file_name =  getName() + "_shrubbery";
        std::ofstream out(file_name.c_str(), std::ios::out | std::ios::trunc);    
        if (!out.is_open())
        {
            std::cerr << "Error: could not open output file." << std::endl;
        }
        
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

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
    AForm(other)
{
    if (OCCF)
        std::cout << PURPLE << "ShrubberyCreationForm copy constructor" << RESET << std::endl;

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    if (OCCF)
        std::cout << YELLOW << "ShrubberyCreationForm copy assignment operator" << RESET << std::endl;
    return (*this);
}