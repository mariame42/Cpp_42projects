/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:50:41 by meid              #+#    #+#             */
/*   Updated: 2025/07/14 13:14:27 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *zombiehorde = newZombie("Foo");
    zombiehorde->announce();
    delete zombiehorde;
    randomChump("randomZombie");
    return 0;
}

// we used heap allocation (new) in newZombie() because the Zombie is returned and may be used later.
// we stack allocation in randomChump() because the Zombie is used temporarily and should be automatically destroyed.