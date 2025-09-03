/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:50:41 by meid              #+#    #+#             */
/*   Updated: 2025/07/20 17:58:22 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::string name = "ZombieName";
    std::string* nameptr = &name;
    if (nameptr == nullptr) {
        std::cerr << "Error: Zombie name cannot be NULL." << std::endl;
        return 1;
    }
    if (nameptr->empty()) {
        std::cerr << "Error: Zombie name cannot be empty." << std::endl;
        return 1;
    }
    Zombie *zombiehorde = newZombie(*nameptr);
    zombiehorde->announce();
    delete zombiehorde;
    randomChump("randomZombie");
    return 0;
}

// we used heap allocation (new) in newZombie() because the Zombie is returned and may be used later.
// we stack allocation in randomChump() because the Zombie is used temporarily and should be automatically destroyed.