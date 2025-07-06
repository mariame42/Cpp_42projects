/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:20:01 by meid              #+#    #+#             */
/*   Updated: 2025/07/06 12:20:04 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *zombiehorde = zombieHorde(5, "zombie");
    for (int i = 0; i < 5; i++)
    {
        zombiehorde[i].announce();
    }
    delete[] zombiehorde;
}