/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:16:13 by meid              #+#    #+#             */
/*   Updated: 2025/07/06 12:19:23 by meid             ###   ########.fr       */
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
        void setName(std::string name);
    };

Zombie* zombieHorde( int N, std::string name );

    
#endif