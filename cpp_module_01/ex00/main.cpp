/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:50:41 by meid              #+#    #+#             */
/*   Updated: 2025/07/06 11:55:03 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *zombiehorde = newZombie("zombie_00");
    zombiehorde->announce();
    delete zombiehorde;

    randomChump("randomZombie");

    return 0;
}