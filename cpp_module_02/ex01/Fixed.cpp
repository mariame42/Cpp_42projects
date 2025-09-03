/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:58:59 by meid              #+#    #+#             */
/*   Updated: 2025/09/03 22:38:37 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    _value = 0;
    std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other._value)
{
    std::cout << BLUE << "Copy constructor called" << RESET << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
        this->_value = other._value;
    }
    std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
    return (*this);
    
}

int		Fixed::getRawBits( void ) const
{
    std::cout << PURPLE << "getRawBits member function called" << RESET << std::endl;
    return(_value);
}

void	Fixed::setRawBits( int const raw )
{
    std::cout << PURPLE << "setRawBits member function called" << RESET << std::endl;
    _value = raw;
}

Fixed::~Fixed()
{
    std::cout << RED << "Destructor called" << RESET << std::endl;
}

// ex01

Fixed::Fixed(const int n)
{
    // In binary, shifting left by 1 bit = multiplying by 2.
    _value = n << _fractional_bits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
    _value = roundf(f * (1 << _fractional_bits));
    std::cout << "Float constructor called" << std::endl;
}

float   Fixed::toFloat( void ) const
{
    return ((float)_value / (1 << _fractional_bits));
}

int     Fixed::toInt( void) const
{
    return ((_value >> _fractional_bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return (os);
}
