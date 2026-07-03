/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:43:49 by meid              #+#    #+#             */
/*   Updated: 2025/09/23 11:22:05 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap s("s");
    ScavTrap b;

    b = s;
    std::cout << "b: " << std::endl;
    b.current_status();
    std::cout << "s: " << std::endl;
    s.current_status();
    s.attack("a");
    s.beRepaired(20);
    s.takeDamage(50);
    s.guardGate();
    std::cout << "s: " << std::endl;
    s.current_status();
}