/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:58:48 by meid              #+#    #+#             */
/*   Updated: 2025/09/19 15:46:29 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_hpp
# define Fixed_hpp

#include <iostream>

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"

// a flag to show when Orthodox Canonical class form is used
// turn it on when we want to see the constructor and destructor messages
#define OCCF 1

class Fixed
{
    private :
        int _value;
        static const int _fractional_bits = 8;

    public :
        Fixed();
        Fixed(const Fixed& other);
        Fixed&	operator=(const Fixed &other);
        ~Fixed();
    
        // the function itself does not modify any member variables of the class. const
        int		getRawBits( void ) const;

        void	setRawBits( int const raw );
    };
    
#endif

// Copy constructor
// The standard way to write a copy constructor in C++ is to define
// a constructor that takes a const reference to an object of the
// same class as its parameter. The const ensures the source object
// isn't modified, while the reference avoids infinite recursion by
// not making a copy of the object to be copied. Inside the constructor,
// you copy the member variables from the source object to the new object being initialized
// ClassName(const ClassName& other);

// Copy assignment operator
// ClassName& operator=(const ClassName& other);