/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:59:44 by meid              #+#    #+#             */
/*   Updated: 2025/09/22 07:44:12 by meid             ###   ########.fr       */
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
    if (n > FIXED_MAX || n < FIXED_MIN)
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
    // NaN = a special floating-point value defined by the IEEE-754 standard that represents
    // "Not a Number" (like results of invalid operations, e.g., 0.0 / 0.0).
    if (std::isnan(f)) {
        throw std::invalid_argument("Cannot convert NaN to Fixed point");
    }
    if (std::isinf(f)) {
        throw std::overflow_error("Cannot convert infinity to Fixed point");
    }
    if (f > (float)FIXED_MAX || f < (float)FIXED_MIN) {
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
    if ((this->_value > 0 && other._value < 0 && this->_value > (long long)INT_MAX + other._value) ||
        (this->_value < 0 && other._value > 0 && this->_value < (long long)INT_MIN + other._value)) {
        throw std::overflow_error("Arithmetic overflow in subtraction");
    }
    res.setRawBits(this->_value - other._value);
    return (res);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed res;
    long long product = (long long)this->_value * (long long)other._value;
    long long raw = product >> _fractional_bits;              // rescale first
    if (raw > INT_MAX || raw < INT_MIN)
        throw std::overflow_error("Arithmetic overflow in multiplication");
    res.setRawBits((int)raw);
    return res;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    if (other._value == 0)
        throw std::runtime_error("Division by zero");

    Fixed res;
    long long numerator = ((long long)this->_value << _fractional_bits);
    long long raw = numerator / (long long)other._value;
    if (raw > INT_MAX || raw < INT_MIN)
        throw std::overflow_error("Arithmetic overflow in division");
    res.setRawBits((int)raw);
    return res;
}

// replace pre-increment
Fixed Fixed::operator++()
{
    long long scaled_max = (long long)FIXED_MAX * (1LL << _fractional_bits);
    if ((long long)_value >= scaled_max) {
        throw std::overflow_error("Increment overflow");
    }
    ++_value;
    return *this;
}

// replace pre-decrement
Fixed Fixed::operator--()
{
    long long scaled_min = (long long)FIXED_MIN * (1LL << _fractional_bits);
    if ((long long)_value <= scaled_min) {
        throw std::overflow_error("Decrement overflow");
    }
    --_value;
    return *this;
}

// replace post-increment
Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    long long scaled_max = (long long)FIXED_MAX * (1LL << _fractional_bits);
    if ((long long)_value >= scaled_max) {
        throw std::overflow_error("Post-increment overflow");
    }
    ++_value;
    return temp;
}

// replace post-decrement
Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    long long scaled_min = (long long)FIXED_MIN * (1LL << _fractional_bits);
    if ((long long)_value <= scaled_min) {
        throw std::overflow_error("Post-decrement overflow");
    }
    --_value;
    return temp;
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