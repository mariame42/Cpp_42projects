/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:19:47 by meid              #+#    #+#             */
/*   Updated: 2025/07/06 16:33:26 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::ifstream file("input.txt");
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

// It must open the file <filename> and copy its content into a new file <filename>.
// replace, replacing every occurrence of s1 with s2.

void check_line_and_change(std::string line, std::string to_find, std::string  to_replace)
{
    std::cout << GREEN << "the line: " <<  line << RESET << std::endl;
    std::cout << RED << "we should change any:  " << to_find << RESET << std::endl;
    std::cout << BLUE << "with:                  " << to_replace << RESET << std::endl;

    // std::cout 
    int start = -1;
    int end = -1;
    int j = 0;
    for (int i = 0; line[i]; i++)
    { 
        if (line[i] == to_find[0])
        {
            j = 0;
            start = i;
            while (line[i] && to_find[j] && line[i] == to_find[j])
            {
                j++;
                i++;
            }
            end = i - 1;
            i--;
            if (to_find[j] == '\0')
            {
                std::cout << GREEN << "i found it" << RESET << std::endl;
                std::cout << start << "::" << end << std::endl;
            }
            else
                std::cout << RED << "did not: " << to_find[j] << RESET << std::endl;
        }   
    }
}

int main(int ac, char *av[])
{
    if (ac == 4)
    {
        std::string line;
        std::ifstream file(av[1]);
        while (getline (file, line)) {
            check_line_and_change(line, av[2], av[3]);
            // std::cout << line;
        }
    }
    else
        std::cout << RED << "i need those parameters filename, s1, s2" << RESET << std::endl;
}


// steps i will take
// will try a simple example then make it harder step by step


// s1 = "hello world"
// s2 = "hi universe" 
// 