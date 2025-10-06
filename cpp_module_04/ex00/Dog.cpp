/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:34:57 by meid              #+#    #+#             */
/*   Updated: 2025/10/06 11:04:49 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    if (OCCF)
        std::cout << GREEN << "Dog constructor called" << RESET << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
    if (OCCF)
        std::cout << GREEN << "Dog constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    if (OCCF)
        std::cout << BLUE << "Dog Copy constructor called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
    }
    if (OCCF)
        std::cout << YELLOW << "Dog Copy assignment operator called" << RESET << std::endl;
    return (*this);
}

void Dog::makeSound()  const
{
    std::cout << PURPLE << "bark" << RESET << std::endl;
}

const std::string Dog::getType() const
{
    return (_type);
}

Dog::~Dog()
{
    if (OCCF)
        std::cout << RED << "Dog destructor called" << RESET << std::endl;
}