/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:23:17 by meid              #+#    #+#             */
/*   Updated: 2025/09/06 12:09:19 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    if (OCCF)
        std::cout << GREEN << "ClapTrap Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    if (OCCF)
        std::cout << GREEN << "ClapTrap Parameterized constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
    if (OCCF)
        std::cout << BLUE << "ClapTrap Copy constructor called" << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    if (OCCF)
        std::cout << YELLOW << "ClapTrap Copy assignment operator called" << RESET << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    if (OCCF)
        std::cout << RED << "ClapTrap Destructor called" << RESET << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        _energyPoints--;
        std::cout << BLUE << "ClapTrap " << _name << " attacks " << target <<
            ", causing one points of damage!"  << BLUE << std::endl;
    }
    else
        std::cout << RED << "ClapTrap " << _name << "not able to attack or dead" << RED << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    unsigned int damage = (amount > _hitPoints) ? _hitPoints : amount;
    _hitPoints -= damage;

    if (damage > 0)
    {
        std::cout << YELLOW << "ClapTrap " << _name << " took "
            << damage << " points of damage!" << RESET;
        if (_hitPoints == 0)
            std::cout << ORANGE << " so now he is dead" << RESET;
        std::cout << std::endl;
    }
    else
        std::cout << RED << "ClapTrap " << _name <<
            " has no hit points left to take damage!" << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << GREEN << "ClapTrap " << _name <<
            " is beRepaired by " << amount << " points "<< RESET << std::endl;
    }
    else
        std::cout << RED << "ClapTrap " << _name <<
            " dead or has no energy points to repaire from his health" << RESET << std::endl; 
}