/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:50:04 by meid              #+#    #+#             */
/*   Updated: 2025/07/14 13:17:08 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Zombie_hpp
#define Zombie_hpp

#include <string>
#include <iostream>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

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