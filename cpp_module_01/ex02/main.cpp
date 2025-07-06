/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:23:30 by meid              #+#    #+#             */
/*   Updated: 2025/07/06 12:54:40 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string* strPTR = &str;
    std::string& strREF = str;
    std::cout << GREEN;
    std::cout << "The memory address of the string variable: " << &str << std::endl;
    std::cout << "The memory address held by stringPTR:      " << strPTR << std::endl;
    std::cout << "The memory address held by stringREF:      " << &strREF;
    std::cout << RESET << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << BLUE;
    std::cout << "The value of the string variable:  " << str << std::endl;
    std::cout << "The value pointed to by stringPTR: " << *strPTR << std::endl;
    std::cout << "The value pointed to by stringREF: " << strREF << std::endl;
    std::cout << RESET << std::endl;
    return 0;
}