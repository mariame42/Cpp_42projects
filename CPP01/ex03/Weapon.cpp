/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:06:19 by meid              #+#    #+#             */
/*   Updated: 2025/10/17 14:19:05 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
    std::cout << GREEN << "Weapon constructor" << RESET << std::endl;
}

Weapon::Weapon(std::string *str)
{
    if (!str)
    {
        type = "default weapon";
        std::cout << GREEN << "Weapon constructor 03" << RESET << std::endl;
    }
    else
        type = *str;
}

Weapon::Weapon(std::string str)
{
    if (str.empty() || str.find_first_not_of(' ') == std::string::npos)
        type = "default weapon";
    else
        type = str;
    std::cout << GREEN << "Weapon constructor 02" << RESET << std::endl;
}

const std::string& Weapon::getType()
{
    return (type);
}

void Weapon::setType(const std::string& newType)
{
    type = newType;
}

void Weapon::setType(const std::string* newType)
{
    if (!newType)
        type = "default weapon";
}

Weapon::~Weapon()
{
    std::cout << RED << "the weapon is destroied" << RESET << std::endl; 
}