/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:10:47 by meid              #+#    #+#             */
/*   Updated: 2025/10/06 12:10:48 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "../main.hpp"


Ice::Ice() : AMateria("ice")
{
    if (OCCF)
    std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
    if (OCCF)
    std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    if (OCCF)
        std::cout << "Ice copy assignment operator called" << std::endl;
    return (*this);
}

Ice::~Ice()
{
    if (OCCF)
        std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << BLUE << "shoots an ice bolt at " << target.getName() << RESET << std::endl;
}