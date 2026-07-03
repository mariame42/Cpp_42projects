/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:43:35 by meid              #+#    #+#             */
/*   Updated: 2025/09/22 21:27:47 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_CPP
#define ClapTrap_CPP

#include <iostream>

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"
#define ORANGE "\033[38;2;255;165;0m"
#define Cyan "\033[36m"

// a flag to show when Orthodox Canonical class form is used
// turn it on when we want to see the constructor and destructor messages
static const int OCCF = 1;
static const int FUNCTIONS_CALLED = 0;
#include <climits>

class ClapTrap {
    private:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;

    public:
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        // my functions
        void current_status();

        // getters and setters
        std::string get_name();
        unsigned int get_hitPoints();
        unsigned int get_energyPoints();
        unsigned int get_attackDamage();
        void set_name(std::string name);
        void set_hitPoints(unsigned int hitPoints);
        void set_energyPoints(unsigned int energyPoints);
        void set_attackDamage(unsigned int attackDamage);
};

#endif