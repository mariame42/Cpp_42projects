/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:08:41 by meid              #+#    #+#             */
/*   Updated: 2025/09/23 20:16:22 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_h
# define WrongCat_h

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public :
        WrongCat();
        WrongCat(std::string type);
        WrongCat(const WrongCat& other);
        WrongCat& operator=(const WrongCat& other);
        const std::string getType() const;
        void makeSound() const;
        ~WrongCat();
};

#endif