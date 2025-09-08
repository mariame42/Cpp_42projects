/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:35:00 by meid              #+#    #+#             */
/*   Updated: 2025/09/08 09:46:37 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef Dog_hpp
# define Dog_hpp

#include "Animal.hpp"

class Dog : public Animal
{
    public :
        Dog();
        Dog(std::string);
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();
        void makeSound();
};

#endif