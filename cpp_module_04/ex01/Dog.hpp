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
#include "Brain.hpp"

class Dog : public Animal
{
    private :
        Brain *_Brain;
    public :
        Dog();
        // Dog(std::string);
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();
        const std::string getType() const;
        void makeSound() const;
        void printIdeas() const;
};

#endif