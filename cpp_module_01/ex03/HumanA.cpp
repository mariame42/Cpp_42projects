/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:52:21 by meid              #+#    #+#             */
/*   Updated: 2025/07/14 14:35:07 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& Weapon) : _name(name), _weaponA(Weapon) // ✅ initializer list
{
}

void HumanA::attack()
{
    std::string str = this->_weaponA.getType(); 
    std::cout << BLUE << this->_name << " attacks with their " << str << RESET << std::endl;
}