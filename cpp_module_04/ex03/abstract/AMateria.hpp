/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:11:11 by meid              #+#    #+#             */
/*   Updated: 2025/09/10 22:05:39 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMateria_HPP
# define AMateria_HPP

#include <iostream>

class ICharacter; // Forward declaration

// An interface is a type of class-like structure (in some programming languages) that:
// Contains only method declarations (no method implementations).
// Cannot hold instance fields (except constants in some languages).
// Defines a contract that other classes must follow.

// The A at the start usually stands for “Abstract”, meaning this class
// is abstract and is meant to be inherited from, not instantiated directly.
// “Materia” is actually a Latin word meaning “matter” or “substance,” and
// in some games or programming contexts, it’s used as a special term for magical or elemental items

class AMateria
{
    protected:
        std::string _type;
    
    public:
        AMateria();
        AMateria(std::string const &type);
        AMateria(const AMateria& other);
        AMateria& operator=(const AMateria& other);
        virtual ~AMateria();

        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target) = 0;
};

#endif