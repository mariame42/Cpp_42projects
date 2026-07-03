/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:11:04 by meid              #+#    #+#             */
/*   Updated: 2025/09/10 22:03:42 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cure_H
# define Cure_H

#include "iostream"
#include "../abstract/AMateria.hpp"
#include "../Interface/ICharacter.hpp"

class Cure : public AMateria
{
  public:
    Cure();
    Cure(const Cure& other);
    Cure& operator=(const Cure& other);
    ~Cure();

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif