/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:20:01 by meid              #+#    #+#             */
/*   Updated: 2025/07/14 13:16:36 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main()
{
    size_t num = 5; 
    Zombie *zombiehorde = zombieHorde(num, "zombie");
    for (size_t i = 0; i < num; i++)
    {
        std::cout << GREEN << i << "  " << RESET;
        zombiehorde[i].announce();
    }
    delete[] zombiehorde;
}