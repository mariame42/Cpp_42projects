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
    if (n > 8388607 || n < -8388608)
        throw std::out_of_range("Integer value out of range for Fixed point representation");
    _value = n << _fractional_bits;
    if (FUNCTIONS_CALLS)
        std::cout << "Int constructor called" << std::endl;
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
// -----     The 4 arithmetic operators: +, -, *, and /.

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed res;
    if ((this->_value > 0 && other._value > 0 && this->_value > INT_MAX - other._value) ||
        (this->_value < 0 && other._value < 0 && this->_value < INT_MIN - other._value)) {
        throw std::overflow_error("Arithmetic overflow in addition");
    }
    res.setRawBits(this->_value + other._value);
    return (res);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed res;
    if ((this->_value > 0 && other._value < 0 && this->_value > INT_MAX + other._value) ||
        (this->_value < 0 && other._value > 0 && this->_value < INT_MIN + other._value)) {
        throw std::overflow_error("Arithmetic overflow in subtraction");
    }
    res.setRawBits(this->_value - other._value);
    return (res);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed res;
    long result = (long)this->_value * (long)other._value; // avoid overflow
    // Check for overflow in multiplication
    if (result > INT_MAX || result < INT_MIN) {
        throw std::overflow_error("Arithmetic overflow in multiplication");
    }
    res.setRawBits(result >> _fractional_bits);            // rescale
    return res;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    if (other._value >> _fractional_bits == 0)
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
    if (_value == INT_MAX) {
        throw std::overflow_error("Increment overflow");
    }
    _value++;
    return (*this);
}

Fixed Fixed::operator--()
{
    if (_value == INT_MIN) {
        throw std::overflow_error("Decrement overflow");
    }
    _value--;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this; // Store the current state
    if (_value == INT_MAX) {
        throw std::overflow_error("Post-increment overflow");
    }
    _value++; // Increment the value
    return (temp); // Return the old state
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this; // Store the current state
    if (_value == INT_MIN) {
        throw std::overflow_error("Post-decrement overflow");
    }
    _value--; // decrement the value
    return (temp); // Return the old state
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