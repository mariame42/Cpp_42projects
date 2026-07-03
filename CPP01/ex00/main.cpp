/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:50:41 by meid              #+#    #+#             */
/*   Updated: 2025/10/17 13:06:11 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// my main rules you can chnage the name but it should pass by check_and_fix_null function 
// so we can make sure that no NULL pointer is passing 

static std::string check_and_fix_null(const char* tmp)
{
    std::string new_name = "";
    if (tmp == NULL) {
        std::cerr << RED << "Error: name is NULL!" << RESET << std::endl;
        return new_name;
    }
    new_name = tmp;
    return new_name;
}

int main(void)
{
    std::string name00 = check_and_fix_null("random Zombie ");
    std::string name01 = check_and_fix_null("allocated Zombie 🧟");
    std::string name02 = check_and_fix_null("");
    
    randomChump(name00);

    Zombie *a_zombie = newZombie(name01);
    if (a_zombie)
    {
        a_zombie->announce();
        delete a_zombie;
    }

    Zombie *b_zombie = newZombie(name02);
    if (b_zombie)
    {
        b_zombie->announce();
        delete b_zombie;
    }
    return 0;
}

// we used heap allocation (new) in newZombie() because the Zombie is returned and may be used later.
// we stack allocation in randomChump() because the Zombie is used temporarily and should be automatically destroyed.