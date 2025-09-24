/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:34:57 by meid              #+#    #+#             */
/*   Updated: 2025/09/24 12:57:08 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    _Brain = new Brain("Dog");
    std::cout << GREEN << "Dog constructor called" << RESET << std::endl;
}

// Dog::Dog(std::string type) : Animal(type)
// {
//     _Brain = new Brain();
//     std::cout << GREEN << "Dog constructor called" << RESET << std::endl;
// }

Dog::Dog(const Dog& other) : Animal(other)
{
    _Brain = new Brain(*other._Brain); // Deep copy of Brain
    std::cout << BLUE << "Dog Copy constructor called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete _Brain; // Delete existing Brain
        _Brain = new Brain(*other._Brain); // Deep copy of Brain
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

void Dog::printIdeas() const
{
    int i = 0;
    while(i < 100)
    {
        std::cout << _Brain->getIdea(i) << " ,";
        i++;
    }
    std::cout << std::endl;
}

std::string Dog::getIdea(int index) const
{
    return _Brain->getIdea(index);
}

Dog::~Dog()
{
    delete _Brain;
    std::cout << RED << "Dog destructor called" << RESET << std::endl;
}