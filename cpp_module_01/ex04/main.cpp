/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:19:47 by meid              #+#    #+#             */
/*   Updated: 2025/07/14 15:36:39 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

int main(int ac, char *av[])
{
    if (ac != 4) {
        std::cerr << "Usage: ./program <filename> <string_to_find> <string_to_replace>" << std::endl;
        return 1;
    }    
    FileReplacer fileReplacer(av[1], av[2], av[3]);
    if (fileReplacer.replacerBotton())
        std::cout << GREEN << "Everything was replaced correctly." << RESET << std::endl;
    else
       std::cout << RED << "The replacement was not successful." << RESET << std::endl;
}