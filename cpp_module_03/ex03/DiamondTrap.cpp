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

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap()
{
    _name = "Default";
    set_hitPoints(100);  // FragTrap value
    set_energyPoints(50);  // ScavTrap value
    set_attackDamage(30);  // FragTrap value
    if (OCCF)
        std::cout << GREEN << "DiamondTrap Default constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap()
{
    _name = name;
    set_hitPoints(100);  // FragTrap value
    set_energyPoints(50);  // ScavTrap value
    set_attackDamage(30);  // FragTrap value
    if (OCCF)
        std::cout << GREEN << "DiamondTrap Parameterized constructor called" << RESET << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << _name << std::endl;
    std::cout << "ClapTrap name: " << get_name() << std::endl;
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

