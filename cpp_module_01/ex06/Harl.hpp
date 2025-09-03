/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:40:49 by meid              #+#    #+#             */
/*   Updated: 2025/07/18 20:31:36 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

#define GREEN  "\033[32m"
#define YELLOW "\033[33m"
#define BLUE   "\033[34m"
#define RED    "\033[31m"
#define PURPLE "\033[35m"
#define RESET  "\033[0m"

enum HarlLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

class Harl {
    private:
        void debug();
        void info();
        void warning();
        void error();
    public:
        void switch_cace_fun(std::string level);  // adjusted name
};

#endif