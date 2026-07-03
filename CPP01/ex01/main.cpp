/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:20:01 by meid              #+#    #+#             */
/*   Updated: 2025/10/17 13:09:10 by meid             ###   ########.fr       */
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

int main()
{
    std::string name = check_and_fix_null("zombieHorde");
    size_t num = 3;
    Zombie *zombiehorde = zombieHorde(num, name);
    if (!zombiehorde){
        std::cerr << RED << "Failed to create zombie horde." << RESET << std::endl;
        return 1;
    }
    for (size_t i = 0; i < num; i++)
    {
       std::cout << GREEN << i << ": " << RESET;
        zombiehorde[i].announce();
    }
    delete[] zombiehorde;
}