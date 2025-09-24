/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:11:16 by meid              #+#    #+#             */
/*   Updated: 2025/09/24 13:11:20 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Brain_H
# define Brain_H

#include "iostream"

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"
#define ORANGE "\033[38;2;255;165;0m"

class Brain
{
    private :
        std::string _ideas[100];
    public :
        Brain();
        Brain(std::string type);
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();
        std::string getIdea(int index) const;
};


#endif