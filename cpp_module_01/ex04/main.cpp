/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:19:47 by meid              #+#    #+#             */
/*   Updated: 2025/07/06 17:09:46 by meid             ###   ########.fr       */
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

std::string    change_line(std::string line, int *i, int start, int end, std::string to_replace)
{
    std::string result;
    result += line.substr(0, start);
    result += to_replace;
    result += line.substr(end + 1);
    std::cout << result << std::endl;
    *i = start + to_replace.length() - 1;
    return (result);
}

std::string check_line_and_change(std::string *linee, std::string to_find, std::string  to_replace)
{
    std::string line = *linee;
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
                std::string new_line = change_line(line, &i, start, end, to_replace);
                std::cout << "new i: " << i << "it stopt at " << line[i] << new_line[i] << std::endl;
                std::cout << new_line << std::endl;
                line = new_line;
                std::cout << GREEN << "i found it" << RESET << std::endl;
                std::cout << start << "::" << end << std::endl;
            }
            else
                std::cout << RED << "did not: " << to_find[j] << RESET << std::endl;
        }   
    }
    return (line);
}

int main(int ac, char *av[])
{
    if (ac == 4)
    {
        std::string line;
        std::string new_line;
        std::ifstream file(av[1]);
        std::ofstream out("output.txt", std::ios::out | std::ios::trunc);
        if (out.is_open())
        {
            while (getline (file, line)) {
                new_line = check_line_and_change(&line, av[2], av[3]);
                std::cout << new_line << std::endl;
                out << new_line;
            }
            out.close();
        }
        else
        {
            std::cerr << "Failed to open the file!" << std::endl;
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