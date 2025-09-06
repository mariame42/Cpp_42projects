/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:58:04 by meid              #+#    #+#             */
/*   Updated: 2025/09/06 14:22:16 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_hpp
#define FragTrap_hpp

#include <iostream>

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"
#define ORANGE "\033[38;2;255;165;0m"

// a flag to show when Orthodox Canonical class form is used
// turn it on when we want to see the constructor and destructor messages
#define OCCF 1

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public :
        FragTrap();
        FragTrap(const std::string& name);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap();

        void highFivesGuys(void);
};

#endif