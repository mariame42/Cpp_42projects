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
    d2.whoAmI();
    d2.current_status();
    d.whoAmI();
    d.current_status();
    return 0;
}