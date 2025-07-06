/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:16:39 by meid              #+#    #+#             */
/*   Updated: 2025/07/06 14:36:01 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WESPON_HPP
#define WESPON_HPP

#include <string>
#include <iostream>

class Weapon {
    private:
        std::string type;
    public:
        Weapon();  // default constructor
        Weapon(std::string str);  // parameterized constructor
        ~Weapon();  // destructor
        const std::string& getType();
        void setType(const std::string &newType);
};




#endif