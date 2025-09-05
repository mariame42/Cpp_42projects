/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:59:16 by meid              #+#    #+#             */
/*   Updated: 2025/09/04 21:21:12 by meid             ###   ########.fr       */
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

// -----     The 6 comparison operators: >, <, >=, <=, ==, and !=.
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


// -----     The 4 arithmetic operators: +, -, *, and /.

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
    long result = (long)this->_value * (long)other._value; // avoid overflow
    res.setRawBits(result >> _fractional_bits);            // rescale
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
    // Rescale to maintain fractional precision
    res.setRawBits((this->_value << _fractional_bits) / other._value);
    return res;
}

// • The 4 increment/decrement (pre-increment and post-increment,
// pre-decrement and post-decrement) operators, which will increase
//  or decrease the fixed-point value by the smallest representable ε,
// such that 1 + ε > 1.

// Pre-increment / Pre-decrement (++x / --x)
// Modify the object first, then return a reference to the updated object.

// 2. Post-increment / Post-decrement (x++ / x--)
// Return the original value first, then modify the object.

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
    Fixed temp = *this; // Store the current state
    _value++; // Increment the value
    return (temp); // Return the old state
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this; // Store the current state
    _value--; // Increment the value
    return (temp); // Return the old state
}


// Add these four public overloaded member functions to your class:
// • A static member function min that takes two references to fixed-point numbers as
// parameters, and returns a reference to the smallest one.

// • A static member function min that takes two references to constant fixed-point
// numbers as parameters, and returns a reference to the smallest one.

// • A static member function max that takes two references to fixed-point numbers as
// parameters, and returns a reference to the greatest one.
// • A static member function max that takes two references to constant fixed-point
// numbers as parameters, and returns a reference to the greatest one.

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