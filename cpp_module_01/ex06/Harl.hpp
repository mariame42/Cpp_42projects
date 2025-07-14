/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:40:49 by meid              #+#    #+#             */
/*   Updated: 2025/07/14 16:08:34 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include "iostream"

class Harl {
    private:
        void debug();
        void info();
        void warning();
        void error();
    public:
        void switch_cace_fun (std::string level);
};

#endif