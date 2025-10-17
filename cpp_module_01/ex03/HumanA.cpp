/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:52:21 by meid              #+#    #+#             */
/*   Updated: 2025/10/17 14:18:05 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& Weapon) : _weaponA(Weapon) // ✅ initializer list
{
    if (name.empty() || name.find_first_not_of(' ') == std::string::npos)
        _name = "default humanA";
    else
        _name = name;
}

HumanA::HumanA(std::string *name, Weapon& Weapon) : _weaponA(Weapon) // ✅ initializer list
{
    if (!name)
        _name = "default humanA";
    else
        _name = *name;
}


void HumanA::attack()
{
    std::string str = _weaponA.getType(); 
    std::cout << BLUE << _name << " attacks with their " << str << RESET << std::endl;
}