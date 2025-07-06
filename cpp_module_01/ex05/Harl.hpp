/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:46:35 by meid              #+#    #+#             */
/*   Updated: 2025/07/06 18:27:35 by meid             ###   ########.fr       */
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
        void    complain( std::string level );

};

#endif