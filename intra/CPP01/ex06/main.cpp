/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:53:11 by meid              #+#    #+#             */
/*   Updated: 2025/07/16 11:22:38 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int main(int ac, char *av[])
{
    Harl harl;
    if (ac == 2)
        harl.switch_cace_fun(av[1]);
    else
        std::cerr << RED << "Usage: ./program <level>" << RESET << std::endl
                << BLUE << "Available levels: DEBUG, INFO, WARNING, ERROR" << RESET << std::endl;
}