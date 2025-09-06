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
    FragTrap f;

    f.current_status();
    f.attack("a");
    f.takeDamage(12);
    f.current_status();
    f.beRepaired(UINT_MAX);
    f.current_status();
    f.highFivesGuys();
    f.current_status();
}