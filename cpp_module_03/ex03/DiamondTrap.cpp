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

DiamondTrap::DiamondTrap()
{
    _name = "Default";
    ClapTrap::_name = "Default_clap_name";
    _hitPoints = FragTrap::get_hitPoints();
    _energyPoints = ScavTrap::get_energyPoints();
    _attackDamage = FragTrap::get_attackDamage();
    if (OCCF)
        std::cout << GREEN << "DiamondTrap Default constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
{
    _name = name;
    ClapTrap::_name = name + "_clap_name";
    _hitPoints = FragTrap::get_hitPoints();
    _energyPoints = ScavTrap::get_energyPoints();
    _attackDamage = FragTrap::get_attackDamage();
    if (OCCF)
        std::cout << GREEN << "DiamondTrap Parameterized constructor called" << RESET << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << _name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    _name = other._name;
    if (OCCF)
        std::cout << BLUE << "DiamondTrap Copy constructor called" << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        _name = other._name;
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

