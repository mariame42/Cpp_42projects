/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 22:09:56 by meid              #+#    #+#             */
/*   Updated: 2025/09/10 22:12:00 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Character_hpp
# define Character_hpp

#include <iostream>
#include <string>
#include "../Interface/ICharacter.hpp"
#include "../abstract/AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria* _inventory[4];
        static const int _maxSlots = 4;

    public:
        Character();
        Character(std::string const &name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        ~Character();

        // ICharacter interface implementation
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif