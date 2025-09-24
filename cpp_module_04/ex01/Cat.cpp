/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:34:51 by meid              #+#    #+#             */
/*   Updated: 2025/09/24 12:53:07 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    _Brain = new Brain("Cat");
    std::cout << GREEN << "Cat constructor called" << RESET << std::endl;
}

// Cat::Cat(std::string type) : Animal(type)
// {
//     _Brain = new Brain();
//     std::cout << "Cat constructor called" << std::endl;
// }

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << BLUE << "Cat Copy constructor called" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
    }
    std::cout << YELLOW << "Cat Copy assignment operator called" << RESET << std::endl;
    return (*this);
}

void Cat::makeSound()  const
{
    std::cout << PURPLE << "meow" << RESET << std::endl;
}

const std::string Cat::getType() const
{
    return (_type);
}

void Cat::printIdeas() const
{
    int i = 0;
    while(i < 100)
    {
        std::cout << _Brain->getIdea(i) << " ,";
        i++;
    }
    std::cout << std::endl;
}

Cat::~Cat()
{
    delete _Brain;
    std::cout << RED << "Cat destructor called" << RESET << std::endl;
}