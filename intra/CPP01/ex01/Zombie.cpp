/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:18:43 by meid              #+#    #+#             */
/*   Updated: 2025/10/17 13:09:40 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
    name = "unnamed";
}

Zombie::Zombie(const std::string name) {
    this->name = name;
}

Zombie::~Zombie() {
    std::cout << ORANGE << name << " is destroyed" << RESET << std::endl;
}

void Zombie::announce(void) const{
    std::cout << BLUE << name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}