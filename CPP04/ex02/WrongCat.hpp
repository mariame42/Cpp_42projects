/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:10:09 by meid              #+#    #+#             */
/*   Updated: 2025/09/24 13:13:10 by meid             ###   ########.fr       */
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