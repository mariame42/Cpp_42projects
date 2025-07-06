/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:51:59 by meid              #+#    #+#             */
/*   Updated: 2025/07/06 18:57:46 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::switch_cace_fun (std::string level)
{
    int lvl = -1;

    if (level == "DEBUG")
        lvl = 1;
    else if (level == "INFO")
        lvl = 2;
    else if (level == "WARNING")
        lvl = 3;
    else if (level == "ERROR")
        lvl = 4;

    switch (lvl) {
        case 1:
            std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
        case 2:
            std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
        case 3:
            std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
        case 4:
            std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
            break;
        default:
            std::cout << "Invalid input";
    }
}