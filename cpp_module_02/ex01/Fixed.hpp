/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:59:02 by meid              #+#    #+#             */
/*   Updated: 2025/09/04 20:28:46 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_hpp
# define Fixed_hpp

#include "iostream"

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"

class Fixed
{
    private :
        int _value;
        static const int _fractional_bits = 8;

    public :
        Fixed();
        Fixed(const int n); //ex01
        Fixed(const float f); //ex01
        Fixed(const Fixed& other);
        ~Fixed();
        Fixed&	operator=(const Fixed &other);
    
        int		getRawBits( void ) const;
        void	setRawBits( int const raw );
        float   toFloat( void ) const; // ex01
        int     toInt( void) const; // ex01

        friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);
        
};


    // • A member function float toFloat( void ) const;
    // that converts the fixed-point value to a floating-point value.

    // • A member function int toInt( void ) const;
    // that converts the fixed-point value to an integer value.

    // And add the following function to the Fixed class files:
    // • An overload of the insertion («) operator that inserts a floating-point representation
    // of the fixed-point number into the output stream object passed as a parameter.
    
#endif