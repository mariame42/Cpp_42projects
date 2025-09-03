/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:02:44 by meid              #+#    #+#             */
/*   Updated: 2025/07/20 18:15:52 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


HumanB::HumanB(std::string name) : _name(name), _weaponB(NULL) {}

void HumanB::setWeapon(Weapon& Weapon)
{
    _weaponB = &Weapon;
}

void HumanB::attack()
{
    if (_weaponB != NULL)
        std::cout << BLUE << _name << " attacks with their " << _weaponB->getType() << RESET << std::endl;
    else
        std::cout << YELLOW << _name << " :I should have weapon to attack"  << RESET << std::endl;
}