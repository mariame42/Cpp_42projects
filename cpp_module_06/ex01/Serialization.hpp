/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:25:47 by meid              #+#    #+#             */
/*   Updated: 2025/11/07 19:47:40 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include <iostream>
#include <stdint.h>

struct Data { int id; std::string name; };

class Serialization
{
    private:
        Serialization(/* args */);
        ~Serialization();
        Serialization(const Serialization &);
        Serialization &operator=(const Serialization &);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif