/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:52:21 by meid              #+#    #+#             */
/*   Updated: 2025/07/06 14:33:26 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& Weapon)
{
    this->name = name;
    this->weaponA = Weapon;
}

void HumanA::attack()
{
    std::string str = this->weaponA.getType(); 
    std::cout << this->name << " attacks with their " << str << std::endl;
}