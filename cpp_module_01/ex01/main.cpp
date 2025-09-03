/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:20:01 by meid              #+#    #+#             */
/*   Updated: 2025/07/20 18:00:56 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main()
{
    std::string name = "ZombieHorde";
    std::string* ptr = &name;
    if (ptr && !name.empty()) {
        std::string& sstrref = *ptr;
        size_t num = 3;
        Zombie *zombiehorde = zombieHorde(num, sstrref);
        if (!zombiehorde){
            std::cerr << RED << "Failed to create zombie horde." << RESET << std::endl;
            return 1;
        }
        for (size_t i = 0; i < num; i++)
        {
            std::cout << GREEN << i << "  " << RESET;
            zombiehorde[i].announce();
        }
        delete[] zombiehorde;
    } else {
        std::cerr << "Pointer is null or empty string" << std::endl;
        return 1;
    }
}