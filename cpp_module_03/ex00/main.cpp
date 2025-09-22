/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:23:29 by meid              #+#    #+#             */
/*   Updated: 2025/09/06 11:55:17 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("a");
    ClapTrap b("b");
    
    a.current_status();
    b.current_status();
    a.attack("b");
    b.takeDamage(12);
    a.current_status();
    b.current_status();
    b.beRepaired(UINT_MAX);
    a.current_status();
    b.current_status();
}