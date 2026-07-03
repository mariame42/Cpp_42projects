/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:50:30 by meid              #+#    #+#             */
/*   Updated: 2025/10/17 11:42:54 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump( std::string name )
{
    if (name.empty() || name.find_first_not_of(' '))
        std::cerr << RED << "Error: Zombie name cannot be empty." << RESET << std::endl;
    else
    {
        Zombie zombie(name);
        zombie.announce();
    }
}