/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:55:38 by meid              #+#    #+#             */
/*   Updated: 2025/10/25 15:55:39 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _max_gride(1), _min_gride(150)
{
    if (OCCF)
        std::cout << GREEN << "constructor is here" << RESET << std::endl;
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
        std::cout << GREEN <<"constructor for the null" << RESET << std::endl;
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
        std::cout << PURPLE << "copy constructor" << RESET << std::endl;
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
        std::cout << YELLOW << "copy assignment operator" << RESET << std::endl;
    return (*this);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
    out << Magenta << obj.get_name() << ", bureaucrat grade " << obj.get_grade() << "." << RESET << std::endl;
    return out;
}

Bureaucrat::~Bureaucrat()
{
    if (OCCF)
        std::cout << ORANGE << "destructor is here" << RESET << std::endl;
}

const std::string   Bureaucrat::get_name() const{
    return (_name);
}

size_t              Bureaucrat::get_grade() const{
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