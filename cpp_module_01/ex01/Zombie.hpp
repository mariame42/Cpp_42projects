/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:16:13 by meid              #+#    #+#             */
/*   Updated: 2025/10/17 13:13:32 by meid             ###   ########.fr       */
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
        std::string name;

    public:
        Zombie();  // default constructor
        Zombie(const std::string name);  // parameterized constructor
        ~Zombie();  // destructor
        void announce(void) const;
        void setName(const std::string name);
    };

Zombie* zombieHorde(int N, std::string name);

    
#endif