/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:11:16 by meid              #+#    #+#             */
/*   Updated: 2025/09/10 22:00:28 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "../Interface/ICharacter.hpp"

AMateria::AMateria()
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
    std::cout << "AMateria Parameterized constructor called" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "AMateria default destructor" << std::endl;
}


AMateria::AMateria(const AMateria& other) : _type(other._type)
{
    std::cout << "AMateria Copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    std::cout<< "AMateria Copy assignment operator called" << std::endl;
    return (*this);
}

std::string const & AMateria::getType() const
{
    return(_type);
}