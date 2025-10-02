/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:10:54 by meid              #+#    #+#             */
/*   Updated: 2025/09/10 22:07:16 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Ice_H
# define Ice_H

#include "iostream"
#include "../abstract/AMateria.hpp"
#include "../Interface/ICharacter.hpp"

class Ice : public AMateria
{
  public:
    Ice();
    Ice(const Ice& other);
    Ice& operator=(const Ice& other);
    ~Ice();

    AMateria* clone() const;
    void use(ICharacter& target);
};

# endif