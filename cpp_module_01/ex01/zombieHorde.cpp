/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:18:36 by meid              #+#    #+#             */
/*   Updated: 2025/07/06 12:19:05 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::setName(std::string name) {
    this->name = name;
}

Zombie* zombieHorde(int N, std::string name )
{
    Zombie *zombiehorde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        zombiehorde[i].setName(name);
    }
    return (zombiehorde);
}