/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:34:49 by meid              #+#    #+#             */
/*   Updated: 2025/09/24 12:50:18 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << GREEN << "Animal constructor called" << RESET << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << GREEN << "Animal constructor called" << RESET << std::endl;
}


Animal::Animal(const Animal& other) : _type(other._type)
{
    std::cout << BLUE << "Animal Copy constructor called" << RESET << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    std::cout << YELLOW << "Animal Copy assignment operator called" << RESET << std::endl;
    return (*this);
}


const std::string Animal::getType() const
{
    return (_type);
}

void Animal::makeSound() const
{
    std::cout << PURPLE << "Some generic animal sound" << RESET << std::endl;
}

Animal::~Animal()
{
    std::cout << RED << "Animal destructor called" << RESET << std::endl;
}

void Animal::printIdeas() const
{
    std::cout << "Animal has no idea" << std::endl;
}