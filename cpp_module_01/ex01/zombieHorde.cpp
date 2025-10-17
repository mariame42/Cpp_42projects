/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:18:36 by meid              #+#    #+#             */
/*   Updated: 2025/10/17 13:12:13 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::setName(const std::string name) {
    this->name = name;
}

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
    {
        std::cerr << RED << "Error: Number of zombies must be greater than 0." << RESET << std::endl;
        return nullptr;
    }
    if (name.empty() || name.find_first_not_of(' ') == std::string::npos)
    {
        std::cerr << RED << "Error: Zombie name cannot be empty." << RESET << std::endl;
        return nullptr;
    }
    Zombie *zombiehorde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        zombiehorde[i].setName(name);
    }
    return (zombiehorde);
}