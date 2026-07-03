/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:59:54 by meid              #+#    #+#             */
/*   Updated: 2025/09/03 19:59:55 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
    if (OCCF)
        std::cout << GREEN << "Default constructor called For Point class" << RESET << std::endl;
}

Point::Point(float x, float y) : _x(x), _y(y)
{
    if (OCCF)
        std::cout << GREEN << "Parametric constructor called For Point class" << RESET << std::endl;
}

Point::Point(const Point& other) : _x(other._x), _y(other._y)
{
    if (OCCF)
        std::cout << BLUE << "Copy constructor called For Point class" << RESET << std::endl;
}

Point& Point::operator=(const Point &other)
{
    if (this != &other)
    {
        // _x and _y are const and cannot be assigned to after initialization
        std::cerr << "Error: Assignment operator cannot be used on const members." << std::endl;
    }
    if (OCCF)
        std::cout << YELLOW << "Copy assignment operator called For Point class" << RESET << std::endl;
    return (*this);
    
}

Point::~Point()
{
    if (OCCF)
        std::cout << RED << "Destructor called For Point class" << RESET << std::endl;
}

Fixed Point::getX() const
{
    return (_x);
}

Fixed Point::getY() const
{
    return (_y);
}

