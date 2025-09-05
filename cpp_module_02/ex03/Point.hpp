/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:59:57 by meid              #+#    #+#             */
/*   Updated: 2025/09/03 19:59:58 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Point_hpp
# define Point_hpp

#include "iostream"
#include "cmath"
#include "Fixed.hpp"

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"

// Orthodox Canonical class form
#define OCCF 0

class Point
{
    private :
        Fixed const _x;
        Fixed const _y;

    public :
        Point();
        Point(const float x, const float y);
        Point(const Point& other);
        Point& operator=(const Point &other);
        ~Point();
        Fixed getX() const;
        Fixed getY() const;
        
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif