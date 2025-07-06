/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:06:19 by meid              #+#    #+#             */
/*   Updated: 2025/07/06 15:06:01 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
    std::cout << GREEN << "Weapon constructor" << RESET << std::endl;
}

Weapon::Weapon(std::string str)
{
    this->type = str;
    std::cout << GREEN << "Weapon constructor 02" << RESET << std::endl;
}

const std::string& Weapon::getType()
{
    return (this->type);
}

void Weapon::setType(const std::string& newType)
{
    this->type = newType;
}

Weapon::~Weapon()
{
    std::cout << RED << "the weapon is destroied" << RESET << std::endl; 
}