/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:58:01 by meid              #+#    #+#             */
/*   Updated: 2025/09/23 10:44:36 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    set_hitPoints(100);
    set_energyPoints(100);
    set_attackDamage(30);
    if (OCCF)
        std::cout << GREEN << "FragTrap Default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    set_hitPoints(100);
    set_energyPoints(100);
    set_attackDamage(30);
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
    if (get_hitPoints() > 0)
        std::cout << ORANGE << "FragTrap " << get_name() << " is sending a high fives request" << RESET << std::endl;
    else
        std::cout << RED << "FragTrap can not send a high five request, he is dead" << RESET << std::endl;
}

FragTrap::~FragTrap()
{
    if (OCCF)
        std::cout << RED << "FragTrap Destructor called" << RESET << std::endl;
}