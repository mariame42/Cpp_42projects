/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:16:34 by meid              #+#    #+#             */
/*   Updated: 2025/07/06 13:59:16 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

#include <iostream>

class HumanA{
    private:
        std::string name;
        Weapon weaponA;
    public:
        HumanA(std::string name, Weapon& Weapon);
        void attack();
};

#endif
