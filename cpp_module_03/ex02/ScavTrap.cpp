/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:10:07 by meid              #+#    #+#             */
/*   Updated: 2025/09/06 14:06:14 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    set_hitPoints(100);
    set_energyPoints(50);
    set_attackDamage(20);
    if (OCCF)
        std::cout << GREEN << "ScavTrap Default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    set_hitPoints(100);
    set_energyPoints(50);
    set_attackDamage(20);
    if (OCCF)
        std::cout << GREEN << "ScavTrap Parameterized constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    if (OCCF)
        std::cout << BLUE << "ScavTrap Copy constructor called" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    if (OCCF)
        std::cout << YELLOW << "ScavTrap Copy assignment operator called" << RESET << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    if (OCCF)
        std::cout << RED << "ScavTrap Destructor called" << RESET << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << ORANGE << "ScavTrap is now in Gate keeper mode." << RESET << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (get_energyPoints() > 0 && get_hitPoints() > 0)
    {
        set_energyPoints(get_energyPoints() - 1);
        std::cout << BLUE << "ScavTrap " << get_name() << " attacks " << target <<
            ", causing " << get_attackDamage() << " points of damage!" << RESET << std::endl;
    }
    else
        std::cout << RED << "ScavTrap " << get_name() << " not able to attack or you are dead" << RED << std::endl;
}