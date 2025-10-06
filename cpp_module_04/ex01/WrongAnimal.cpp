/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:09:18 by meid              #+#    #+#             */
/*   Updated: 2025/10/06 11:28:47 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
WrongAnimal::WrongAnimal()
{
    if (OCCF)
        std::cout << GREEN << "WrongAnimal constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    if (OCCF)
        std::cout << GREEN << "WrongAnimal constructor called" << RESET << std::endl;   
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type)
{
    if (OCCF)
        std::cout << BLUE << "WrongAnimal Copy constructor called" << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    if (OCCF)
        std::cout << YELLOW << "WrongAnimal Copy assignment operator called" << RESET << std::endl;
    return (*this);
}


const std::string WrongAnimal::getType() const
{
    return (_type);
}

void WrongAnimal::makeSound() const
{
    std::cout << PURPLE << "Some generic WrongAnimal sound"  << RESET << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    if (OCCF)
        std::cout << RED << "WrongAnimal destructor called" << RESET << std::endl;
}
