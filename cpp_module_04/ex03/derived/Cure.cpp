/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:11:07 by meid              #+#    #+#             */
/*   Updated: 2025/10/02 20:41:06 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "../main.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    std::cout << "Cure copy assignment operator called" << std::endl;
    return (*this);
}

Cure::~Cure()
{
    std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << Cyan << "Cure: heals " << target.getName() << "'s wounds" << RESET << std::endl;
}