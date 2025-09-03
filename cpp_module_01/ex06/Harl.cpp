/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:51:59 by meid              #+#    #+#             */
/*   Updated: 2025/07/18 20:32:07 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void  Harl::debug(){
    std::cout << GREEN << "Extra bacon on my burger is the best!" << RESET << std::endl;
}

void Harl::info(){
    std::cout << BLUE << "I can’t believe extra bacon costs more!" << RESET << std::endl;
}

void Harl::warning(){
    std::cout << YELLOW << "I deserve free bacon; I’ve been a loyal customer." << RESET << std::endl;
}

void Harl::error(){
    std::cout << RED << "This is unacceptable! I want to speak to the manager!" <<
        RESET << std::endl;
}

void Harl::switch_cace_fun (std::string level)
{
    int lvl = -1;

    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};//const
        
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            lvl = i;
            break;
        }
    }
    if (lvl == -1)
    {
        std::cout << PURPLE << "Harl isn’t complaining I am! I’m Mariam, the one who does" 
                  << " the complaining. I gave you options, so why are you going off-script?" 
                  << RESET << std::endl;
        return;
    }
    switch (lvl) {
        case DEBUG:
            debug();
        case INFO:
            info();
        case WARNING:
            warning();
        case ERROR:
            error();
            break;
        default:
            std::cout << "Invalid input";
    }
}