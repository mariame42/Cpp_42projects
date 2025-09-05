/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:59:44 by meid              #+#    #+#             */
/*   Updated: 2025/09/03 19:59:45 by meid             ###   ########.fr       */
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
    if (OCCF)
        std::cout << PURPLE << "getRawBits member function called" << RESET << std::endl;
    return(_value);
}

void	Fixed::setRawBits( int const raw )
{
    if (OCCF)
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
    _value = n << _fractional_bits;
    if (OCCF)
        std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
    _value = roundf(f * (1 << _fractional_bits));
    if (OCCF)
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

// ---------------------------- ex02 ----------------------------

bool Fixed::operator>(const Fixed& other) const
{
    return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->_value < other._value);   
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->_value <= other._value);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->_value != other._value);
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed res;
    res.setRawBits(this->_value + other._value);
    return (res);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed res;
    res.setRawBits(this->_value - other._value);
    return (res);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed res;
    long result = (long)this->_value * (long)other._value;
    res.setRawBits(result >> _fractional_bits);
    return res;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    if (other._value == 0)
    {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed(0);
    }

    Fixed res;
    res.setRawBits((this->_value << _fractional_bits) / other._value);
    return res;
}

Fixed Fixed::operator++()
{
   _value++;
    return (*this);
}

Fixed Fixed::operator--()
{
    _value--;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    _value++;
    return (temp);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    _value--;
    return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b ? a : b);
}

// ---------------------------- ex03 ----------------------------

