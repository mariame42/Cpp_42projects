/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:49:59 by meid              #+#    #+#             */
/*   Updated: 2025/07/14 13:17:57 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() :  _name("unnamed") {}

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie() {
    std::cout << RED << this->_name << " is destroyed" << RESET << std::endl;
}

void Zombie::announce(void) {
    std::cout << GREEN << this->_name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
