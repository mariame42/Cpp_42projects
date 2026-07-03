/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:09:37 by meid              #+#    #+#             */
/*   Updated: 2025/10/06 11:29:08 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    if (OCCF)
        std::cout << GREEN << "WrongCat constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    if (OCCF)
        std::cout << BLUE << "WrongCat Copy constructor called" << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
    {
        WrongAnimal::operator=(other);
    }
    if (OCCF)
        std::cout << YELLOW << "WrongCat Copy assignment operator called" << RESET << std::endl;
    return (*this);
}

void WrongCat::makeSound()  const
{
    std::cout << PURPLE << "growl" << RESET << std::endl;
}

const std::string WrongCat::getType() const
{
    return (_type);
}

WrongCat::~WrongCat()
{
    if (OCCF)
        std::cout << RED << "WrongCat destructor called" << RESET << std::endl;
}