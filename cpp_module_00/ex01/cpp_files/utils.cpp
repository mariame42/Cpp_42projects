/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:01:37 by meid              #+#    #+#             */
/*   Updated: 2025/07/12 12:50:55 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hpp_files/main.hpp"

void displayc_ten_char(const std::string& str)
{
    if (str.length() <= 10) {
        std::cout << std::setw(10) << str;
    } else {
        for (size_t i = 0; i < 9; i++) {
            std::cout << str[i];
        }
        std::cout << ".";
    }
}

bool containsOnlySpaces(const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] != ' ') {
            return false;
        }
    }
    return true;
}

int name_check(const std::string& name)
{
    for (size_t i = 0; i < name.length(); ++i) {
        if (std::isdigit(name[i])) {
            std::cout << RED << "Error: name cannot contain numbers!" << RESET << std::endl;
            return 1;
        }
    }
    if (name.length() > 50) {
        std::cout << RED << "Error: Names cannot exceed 50 characters!" << RESET << std::endl;
        return 1;
    }
    return 0;
}

std::string check_for_eof_and_print(const std::string& prompt, const std::string& color) {
    std::string input;

    std::cout << color << prompt;
    if (!std::getline(std::cin, input)) {
        std::cout << RESET << RED << "\nEOF detected or input error." << RESET << std::endl;
        return std::string(); // empty string means failure
    }
    else if (containsOnlySpaces(input))
    {
        std::cout << RESET << RED << "\n this string contains only spaces or nothing" << RESET << std::endl;
        return std::string();
    }
    std::cout << RESET;
    return input;
}

bool is_number(const std::string& str) {
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}
