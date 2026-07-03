/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:42:50 by meid              #+#    #+#             */
/*   Updated: 2025/10/17 14:19:26 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

// int main() {
//     {
//         Weapon club = Weapon(NULL);
//         HumanA bob(NULL, club);
//         bob.attack();
//         club.setType(NULL);
//         bob.attack();
//     }
//     {
//         Weapon club = Weapon("gun");
//         HumanB jim(NULL);
//         Weapon nullweapon = NULL;
//         jim.attack();
//         jim.setWeapon(club);
//         jim.attack();
//         jim.setWeapon(nullweapon);
//         jim.attack();
//         club.setType(NULL);
//         jim.attack();
//     }
//     return 0;
// }
int main() {
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.attack();
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}

// bob attacks with their crude spiked club
// bob attacks with their some other type of club

// jim attacks with their crude spiked club
// jim attacks with their some other type of club

