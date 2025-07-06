/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:02:44 by meid              #+#    #+#             */
/*   Updated: 2025/07/06 15:05:07 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


HumanB::HumanB(std::string name) : name(name), weaponB(NULL) {}

void HumanB::setWeapon(Weapon& Weapon)
{
    this->weaponB = &Weapon;
}

void HumanB::attack()
{
    if (weaponB != NULL)
        std::cout << BLUE << this->name << " attacks with their " << this->weaponB->getType() << RESET << std::endl;
}