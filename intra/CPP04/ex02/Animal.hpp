/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:34:46 by meid              #+#    #+#             */
/*   Updated: 2025/10/06 11:33:39 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Animal_hpp
# define Animal_hpp
#include <iostream>

#include "main.hpp"

class Animal
{
    protected :
        std::string _type;
    public :
        Animal();
        Animal(std::string);
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();
        virtual const std::string getType() const;
        virtual void makeSound() const = 0;
        virtual void printIdeas() const = 0;
        virtual std::string getIdea(int index) const = 0;
};

#endif
