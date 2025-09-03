/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:59:02 by meid              #+#    #+#             */
/*   Updated: 2025/09/03 21:38:52 by meid             ###   ########.fr       */
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
        static const int fractional_bits = 8;

    public :
        Fixed();
        Fixed(const Fixed& other);
        ~Fixed();
        Fixed&	operator=(const Fixed &other);
        int		getRawBits( void ) const;
        void	setRawBits( int const raw );
    };
    
#endif