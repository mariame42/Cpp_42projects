/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:52:21 by meid              #+#    #+#             */
/*   Updated: 2025/07/16 10:52:50 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& Weapon) : _name(name), _weaponA(Weapon) // ✅ initializer list
{}

void HumanA::attack()
{
    std::string str = _weaponA.getType(); 
    std::cout << BLUE << _name << " attacks with their " << str << RESET << std::endl;
}