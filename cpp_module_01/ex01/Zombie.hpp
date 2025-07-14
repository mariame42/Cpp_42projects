/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:16:13 by meid              #+#    #+#             */
/*   Updated: 2025/07/14 13:05:41 by meid             ###   ########.fr       */
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