/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:06:19 by meid              #+#    #+#             */
/*   Updated: 2025/07/06 14:37:48 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
    std::cout << "Weapon constructor" << std::endl;
}

Weapon::Weapon(std::string str)
{
    this->type = str;
    std::cout << "the constructor saved the wepon as the type and it is: " << this->type << std::endl;
}

const std::string& Weapon::getType()
{
    return (this->type);
}

void Weapon::setType(const std::string& newType)
{
    std::cout << "i setting the new type: " <<  newType << std::endl;
    this->type = newType;
    std::cout << this->type << std::endl;
}

Weapon::~Weapon()
{
    std::cout << "the weapon is destroied" << std::endl; 
}