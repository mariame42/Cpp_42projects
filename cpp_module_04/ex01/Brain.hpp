/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:09:06 by meid              #+#    #+#             */
/*   Updated: 2025/10/06 11:28:19 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Brain_H
# define Brain_H

#include "iostream"
#include "main.hpp"

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