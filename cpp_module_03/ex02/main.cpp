/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 14:26:19 by meid              #+#    #+#             */
/*   Updated: 2025/09/06 14:28:20 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
    std::cout << "=== Creating FragTrap with name ===" << std::endl;
    FragTrap f("FragBot");
    
    std::cout << "\n=== Creating FragTrap without name ===" << std::endl;
    FragTrap g;
    
    std::cout << "\n=== Testing copy constructor ===" << std::endl;
    FragTrap h(f);
    
    std::cout << "\n=== Testing copy assignment ===" << std::endl;
    g = f;
    
    std::cout << "\n=== Testing FragTrap functionality ===" << std::endl;
    f.current_status();
    f.attack("enemy");
    f.takeDamage(12);
    f.current_status();
    f.beRepaired(20);
    f.current_status();
    f.highFivesGuys();
    
    std::cout << "\n=== End of main - destructors will be called ===" << std::endl;
}