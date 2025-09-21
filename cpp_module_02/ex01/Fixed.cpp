/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:58:59 by meid              #+#    #+#             */
/*   Updated: 2025/09/21 17:41:55 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// ---------------------------- ex00 ----------------------------

Fixed::Fixed()
{
    _value = 0;
    if (OCCF)
        std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other._value)
{
    if (OCCF)
        std::cout << BLUE << "Copy constructor called" << RESET << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
        this->_value = other._value;
    }
    if (OCCF)
        std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
    return (*this);
    
}

int		Fixed::getRawBits( void ) const
{
    if (FUNCTIONS_CALLS)
        std::cout << PURPLE << "getRawBits member function called" << RESET << std::endl;
    return(_value);
}

void	Fixed::setRawBits( int const raw )
{
    if (FUNCTIONS_CALLS)
        std::cout << PURPLE << "setRawBits member function called" << RESET << std::endl;
    _value = raw;
}

Fixed::~Fixed()
{
    if (OCCF)
        std::cout << RED << "Destructor called" << RESET << std::endl;
}

// ---------------------------- ex01 ----------------------------

Fixed::Fixed(const int n)
{
    // In binary, shifting left by 1 bit = multiplying by 2.
    if (n > 8388607 || n < -8388608)
        throw std::out_of_range("Integer value out of range for Fixed point representation");
    _value = n << _fractional_bits;
    if (FUNCTIONS_CALLS)
        std::cout << GREEN << "Int constructor called" << RESET << std::endl;
}

// Floats are stored in memory using a special format (sign, exponent, mantissa),
// so we can’t just shift their bits like integers.
// Instead, we multiply the float by 256, which achieves the same scaling effect
// as shifting would for integers.
Fixed::Fixed(const float f)
{
    if (std::isnan(f)) {
        throw std::invalid_argument("Cannot convert NaN to Fixed point");
    }
    if (std::isinf(f)) {
        throw std::overflow_error("Cannot convert infinity to Fixed point");
    }
    if (f > 8388607.0f || f < -8388608.0f) {
        throw std::overflow_error("Float value out of range for Fixed point representation");
    }
    _value = roundf(f * (1 << _fractional_bits));
    if (FUNCTIONS_CALLS)
        std::cout << GREEN << "Float constructor called" << RESET << std::endl;
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
