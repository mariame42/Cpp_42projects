/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:40:56 by meid              #+#    #+#             */
/*   Updated: 2025/10/17 13:30:28 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"
#include <cstddef>

class HumanB{
    private:
        std::string _name;
        Weapon *_weaponB;
    public:
        HumanB(std::string name);
        HumanB(std::string *name);
        void setWeapon(Weapon& Weapon);
        void attack();
};


#endif