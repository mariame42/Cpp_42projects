/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:02:44 by meid              #+#    #+#             */
/*   Updated: 2025/07/06 14:04:56 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


HumanB::HumanB(std::string name)
{
    this->name = name;
}

void HumanB::setWeapon(Weapon& Weapon)
{
    this->weaponB = Weapon;
}

void HumanB::attack()
{
    std::string str = this->weaponB.getType();
    std::cout << this->name << " attacks with their " << str << std::endl;
}