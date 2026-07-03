/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:55:55 by meid              #+#    #+#             */
/*   Updated: 2025/10/30 09:57:54 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _max_gride(1), _min_gride(150)
{
    if (OCCF)
        std::cout << GREEN << "Bureaucrat constructor is here" << RESET << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const std::string *name, int grade) : _name ("defult name"), _max_gride(1), _min_gride(150)
{
    name += 0; 
    if (OCCF)
        std::cout << GREEN << "Bureaucrat constructor for the null" << RESET << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade),
    _max_gride(other._max_gride), _min_gride(other._min_gride)
{
    if (OCCF)
        std::cout << PURPLE << "Bureaucrat copy constructor" << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        // _name is const, so it cannot be assigned after construction
        this->_grade = other._grade;
        this->_max_gride = other._max_gride;
        this->_min_gride = other._min_gride;
    } 
    if (OCCF)
        std::cout << YELLOW << "Bureaucrat copy assignment operator" << RESET << std::endl;
    return (*this);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
    // <name>, bureaucrat grade <grade>
    out << Magenta << obj.getName() << ", bureaucrat grade " << obj.getGrade() << RESET << std::endl;   // 👈 print extra text every time
    return out;               // allow chaining
}

Bureaucrat::~Bureaucrat()
{
    if (OCCF)
        std::cout << ORANGE << "Bureaucrat destructor is here" << RESET << std::endl;
}

const std::string   Bureaucrat::getName() const{
    return (_name);
}

size_t              Bureaucrat::getGrade() const{
    return (_grade);
}

void                Bureaucrat::increment_grade(){
    if (_grade == 1)
        throw GradeTooHighException();
    _grade--;
}

void                Bureaucrat::decrement_grade()
{
    if (_grade == 150)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << GREEN << getName() << " signed " << form.getName() << RESET << std::endl;
    }
    catch(const AForm::GradeTooLowException& e)
    {
        std::cerr << RED << getName() << " couldn’t sign " << form.getName() << " because " << e.what() << RESET << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cerr << GREEN << this->getName() << " execute " << form.getName() << RESET << std::endl;
    }
    catch (const AForm::NotEnoughToBeExecuted &e)
    {
        std::cerr << RED << this->getName() << " couldn’t execute " << form.getName() << " because " << e.what() << RESET << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}