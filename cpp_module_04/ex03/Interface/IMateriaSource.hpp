/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:10:27 by meid              #+#    #+#             */
/*   Updated: 2025/10/06 12:53:30 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMateriaSource_hpp
# define IMateriaSource_hpp

#include "iostream"
#include "../abstract/AMateria.hpp"
#include "../derived_concrete_classes/Character.hpp"
#include "../main.hpp"

class IMateriaSource
{
    public:
        IMateriaSource();
        IMateriaSource(const IMateriaSource& other);
        IMateriaSource& operator=(const IMateriaSource& other);

        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif