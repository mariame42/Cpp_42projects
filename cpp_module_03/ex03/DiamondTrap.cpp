/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 14:37:54 by meid              #+#    #+#             */
/*   Updated: 2025/09/06 14:58:18 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() :
{
    std::string pov = " _clap_name";
    _name = "Default" + pov;
    _hitPoints = ;
    _energyPoints = 50;
    _attackDamage = 20;
    if (OCCF)
        std::cout << GREEN << "DiamondTrap Default constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name)
{
    // _hitPoints = 100;
    // _energyPoints = 50;
    // _attackDamage = 20;
    if (OCCF)
        std::cout << GREEN << "DiamondTrap Parameterized constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    if (OCCF)
        std::cout << BLUE << "DiamondTrap Copy constructor called" << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    if (OCCF)
        std::cout << YELLOW << "DiamondTrap Copy assignment operator called" << RESET << std::endl;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    if (OCCF)
        std::cout << RED << "DiamondTrap Destructor called" << RESET << std::endl;
}