/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:02:44 by meid              #+#    #+#             */
/*   Updated: 2025/10/17 14:18:00 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


HumanB::HumanB(std::string name) : _weaponB(NULL) {
    if (name.empty() || name.find_first_not_of(' ') == std::string::npos)
        _name = "default humanB";
    else
        _name = name;
}

HumanB::HumanB(std::string *name) : _weaponB(NULL) {
    if (!name)
        _name = "default humanB";
    else
        _name = *name;
}

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