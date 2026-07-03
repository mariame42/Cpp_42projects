/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:52:10 by meid              #+#    #+#             */
/*   Updated: 2025/10/17 13:04:09 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    if (name.empty() || name.find_first_not_of(' ') == std::string::npos)
    {
        std::cerr << RED << "Error: Zombie name cannot be empty." << RESET << std::endl;
        return NULL;
    }
    Zombie *zombie = new Zombie(name); // Safe: it stays alive after the function
    return zombie;
}