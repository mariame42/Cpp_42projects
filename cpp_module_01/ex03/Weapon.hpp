/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:16:39 by meid              #+#    #+#             */
/*   Updated: 2025/07/06 15:01:53 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WESPON_HPP
#define WESPON_HPP

#include <string>
#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

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