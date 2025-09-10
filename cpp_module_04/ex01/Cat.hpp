/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:34:54 by meid              #+#    #+#             */
/*   Updated: 2025/09/08 09:46:46 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_hpp
# define Cat_hpp

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private :
        Brain *_Brain;
    public :
        Cat();
        // Cat(std::string);
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        ~Cat();
        const std::string getType() const;
        void makeSound() const;
        void printIdeas() const;
};

#endif