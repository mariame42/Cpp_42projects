/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 14:31:30 by meid              #+#    #+#             */
/*   Updated: 2025/09/06 14:32:13 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap d;
    DiamondTrap d2("d2");
    
    std::cout << "\n=== Testing DiamondTrap functionality ===" << std::endl;
    d2.whoAmI();
    d2.current_status();
    
    std::cout << "\n=== Testing attack function (should use ScavTrap's attack) ===" << std::endl;
    d2.attack("enemy");
    
    std::cout << "\n=== Testing other functions ===" << std::endl;
    d.whoAmI();
    d.current_status();
    
    std::cout << "\n=== End of main - destructors will be called ===" << std::endl;
    return 0;
}