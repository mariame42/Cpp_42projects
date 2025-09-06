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

ScavTrap::ScavTrap() : ClapTrap("Default")
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    if (OCCF)
        std::cout << GREEN << "ScavTrap Default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    if (OCCF)
        std::cout << GREEN << "ScavTrap Parameterized constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    if (OCCF)
        std::cout << BLUE << "ScavTrap Copy constructor called" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
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
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        _energyPoints--;
        std::cout << BLUE << "ScavTrap " << _name << " attacks " << target <<
            ", causing one points of damage!"  << BLUE << std::endl;
    }
    else
        std::cout << RED << "ScavTrap " << _name << "not able to attack or dead" << RED << std::endl;
}