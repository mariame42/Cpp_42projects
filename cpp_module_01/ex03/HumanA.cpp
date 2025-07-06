/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:52:21 by meid              #+#    #+#             */
/*   Updated: 2025/07/06 15:05:37 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& Weapon) : name(name), weaponA(Weapon) // ✅ initializer list
{
}

void HumanA::attack()
{
    std::string str = this->weaponA.getType(); 
    std::cout << BLUE << this->name << " attacks with their " << str << RESET << std::endl;
}