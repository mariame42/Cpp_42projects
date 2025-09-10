/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:34:46 by meid              #+#    #+#             */
/*   Updated: 2025/09/08 09:44:16 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Animal_hpp
# define Animal_hpp
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

class Animal
{
    protected :
        std::string _type;
    public :
        Animal();
        Animal(std::string);
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        ~Animal();
        virtual const std::string getType() const;
        virtual void makeSound() const;
        virtual void printIdeas() const;
};

#endif
