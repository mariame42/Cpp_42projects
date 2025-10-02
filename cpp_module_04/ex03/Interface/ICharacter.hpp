/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 22:09:56 by meid              #+#    #+#             */
/*   Updated: 2025/09/10 22:12:00 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICharacter_hpp
# define ICharacter_hpp

#include "iostream"

class AMateria; // Forward declaration

class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0; virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

#endif