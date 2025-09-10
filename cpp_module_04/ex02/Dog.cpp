/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:34:57 by meid              #+#    #+#             */
/*   Updated: 2025/09/08 09:34:58 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    _Brain = new Brain("Dog");
    std::cout << "Dog constructor called" << std::endl;
}

// Dog::Dog(std::string type) : Animal(type)
// {
//     _Brain = new Brain();
//     std::cout << "Dog constructor called" << std::endl;
// }

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
    std::cout << "bark" << std::endl;
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

Dog::~Dog()
{
    delete _Brain;
    std::cout << "Dog destructor called" << std::endl;
}