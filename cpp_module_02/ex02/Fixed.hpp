/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:19:37 by meid              #+#    #+#             */
/*   Updated: 2025/09/04 21:11:55 by meid             ###   ########.fr       */
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
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        Fixed operator++();
        Fixed operator--();
        Fixed& operator++(int); // the `int` is the dummy parameter
        Fixed& operator--(int);
        // “Dummy parameter” just means a parameter that exists
        // only to satisfy the function signature — you don’t actually use it in the function.
};

#endif