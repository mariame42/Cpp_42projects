/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:48:20 by meid              #+#    #+#             */
/*   Updated: 2025/07/17 23:09:38 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void  Harl::debug(){
    std::cout << GREEN << "Extra bacon on my burger is the best!" << RESET << '\n';
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

// funPtr[0] = pointer to Harl::debug
// funPtr[1] = pointer to Harl::info
// funPtr[2] = pointer to Harl::warning
// funPtr[3] = pointer to Harl::error

void    Harl::complain( std::string level )
{
    void (Harl::*funPtr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};//const
    bool flag = false;

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            flag = true;
            (this->*funPtr[i])();
        }
    }
    if (!flag)
        std::cout << PURPLE << "Harl isn’t complaining I am! I’m Mariam, the one who does" << 
            "the complaining. I gave you options, so why are you going off-script?" << RESET <<std::endl;
}
