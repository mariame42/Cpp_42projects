/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:50:04 by meid              #+#    #+#             */
/*   Updated: 2025/07/06 12:16:54 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Zombie_hpp
#define Zombie_hpp

#include <string>
#include <iostream>

class Zombie {
    private:
        std::string name;

    public:
        Zombie();  // default constructor
        Zombie(std::string name);  // parameterized constructor
        ~Zombie();  // destructor
        void announce(void);
    };
    
Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif