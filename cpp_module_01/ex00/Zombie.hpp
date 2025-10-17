/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:50:04 by meid              #+#    #+#             */
/*   Updated: 2025/10/17 11:34:22 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Zombie_hpp
#define Zombie_hpp

#include <string>
#include <iostream>

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"
#define ORANGE "\033[38;2;255;165;0m"
#define Cyan "\033[36m"

class Zombie {
    private:
        std::string _name;

    public:
        Zombie();  // default constructor
        Zombie(std::string name);  // parameterized constructor
        ~Zombie();  // destructor
        void announce(void);
    };
    
Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif