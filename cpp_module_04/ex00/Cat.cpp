/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:34:51 by meid              #+#    #+#             */
/*   Updated: 2025/09/23 20:14:55 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << GREEN << "Cat constructor called" << RESET << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
    std::cout << GREEN << "Cat constructor called" << RESET << std::endl;
}

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

Cat::~Cat()
{
    std::cout << RED << "Cat destructor called" << RESET << std::endl;
}