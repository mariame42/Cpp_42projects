/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:59:02 by meid              #+#    #+#             */
/*   Updated: 2025/09/22 07:27:53 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_hpp
# define Fixed_hpp

#include "iostream"
#include "cmath"

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"

static const bool OCCF = 1;
static const bool FUNCTIONS_CALLS = 1;
static const int FIXED_MAX = 8388607;
static const int FIXED_MIN = -8388608;


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

#endif