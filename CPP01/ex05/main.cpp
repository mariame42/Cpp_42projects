/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:53:53 by meid              #+#    #+#             */
/*   Updated: 2025/07/18 20:37:46 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;
    std::cout << PURPLE << "------------ Harl complains:" << RESET << std::endl;
    std::cout << GREEN << "Debug messages: " << RESET;
    harl.complain("DEBUG");
    std::cout << BLUE << "Info messages: " << RESET;
    harl.complain("INFO");
    std::cout << YELLOW << "Warning messages: " << RESET;
    harl.complain("WARNING");
    std::cout << RED << "Error messages: " << RESET;
    harl.complain("ERROR");
    for (int i = 0; i < 12; ++i) {
        std::cout << std::endl;
        harl.complain("DEBUG");
        harl.complain("INFO");
        harl.complain("WARNING");
        harl.complain("ERROR");
        std::cout << std::endl;
    }
    harl.complain("");
}