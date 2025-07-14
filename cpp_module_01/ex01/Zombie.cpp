/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:18:43 by meid              #+#    #+#             */
/*   Updated: 2025/07/14 13:07:05 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
    this->name = "unnamed";
}

Zombie::Zombie(std::string name) {
    this->name = name;
}

Zombie::~Zombie() {
    std::cout << RED << this->name << " is destroyed" << RESET << std::endl;
}

void Zombie::announce(void) {
    std::cout << BLUE << this->name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}