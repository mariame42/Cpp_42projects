/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:42:50 by meid              #+#    #+#             */
/*   Updated: 2025/07/20 18:08:42 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main() {
    {
        Weapon club = Weapon("NULL");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("©˙˚∆∫˜¬˚˙¬∆😀©˙˚∆∫˜¬˚˙¬∆😀©˙˚∆∫˜¬˚˙¬¬˚˙¬∆😀");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("asd");
        jim.attack();
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    // HumanB jim("Jim"
    return 0;
}



// bob attacks with their crude spiked club
// bob attacks with their some other type of club

// jim attacks with their crude spiked club
// jim attacks with their some other type of club

