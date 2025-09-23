/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:34:57 by meid              #+#    #+#             */
/*   Updated: 2025/09/23 20:15:24 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << BLUE << "Dog Copy constructor called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
    }
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
    std::cout << RED << "Dog destructor called" << RESET << std::endl;
}