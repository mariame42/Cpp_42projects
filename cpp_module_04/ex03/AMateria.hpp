/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:11:11 by meid              #+#    #+#             */
/*   Updated: 2025/09/10 21:11:12 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class AMateria
{
    public:
        AMateria();
        AMateria(std::string const &type);


        std::string const & getType() const;//Returns the materia type
        virtual AMateria* clone() const = 0;
        // virtual void use(ICharacter& target);

        AMateria(const AMateria& other);
        AMateria& operator=(const AMateria& other);
        ~AMateria();
};

#endif