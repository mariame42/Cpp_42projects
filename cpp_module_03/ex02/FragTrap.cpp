/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:58:01 by meid              #+#    #+#             */
/*   Updated: 2025/09/06 14:27:54 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    _name = "Default";
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    if (OCCF)
        std::cout << GREEN << "FragTrap Default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string& name)
{
    _name = name;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    if (OCCF)
        std::cout << GREEN << "FragTrap Parameterized constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    if (OCCF)
        std::cout << BLUE << "FragTrap Copy constructor called" << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    if (OCCF)
        std::cout << YELLOW << "FragTrap Copy assignment operator called" << RESET << std::endl;
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << ORANGE << _name << "FragTrap is is sending a high-fives request" << RESET << std::endl;
}

FragTrap::~FragTrap()
{
    if (OCCF)
        std::cout << RED << "FragTrap Destructor called" << RESET << std::endl;
}