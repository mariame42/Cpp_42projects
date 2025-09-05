/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:59:42 by meid              #+#    #+#             */
/*   Updated: 2025/09/03 19:59:43 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// How To Determine if a Point Is in a 2D Triangle
// https://www.baeldung.com/cs/check-if-point-is-in-2d-triangle

//example:
// A(0,0), B(4,0), C(1,3)
// Test point:
// P(1,1)

// For each edge, compute
// cross = (x₂−x₁)(y−y₁) − (y₂−y₁)(x−x₁).
// If all crosses have the same sign (all ≥0 or all ≤0), P is inside.

// Edge AB: A→B = (4,0)
// cross_AB(P) = 4*(1−0) − 0*(1−0) = 4 > 0

// Edge BC: B→C = (−3,3)
// cross_BC(P) = (−3)(1−0) − 3(1−4) = −3 − (−9) = 6 > 0

// Edge CA: C→A = (−1,−3)
// cross_CA(P) = (−1)(1−3) − (−3)(1−1) = (−1)*(−2) − 0 = 2 > 0

char cross(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x, Fixed y)
{
    Fixed cross = (x2 - x1) * (y - y1) - (y2 - y1) * (x - x1);
    if (cross > 0)
        return (1);
    else if (cross < 0)
        return (-1);
    else
        return (0);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    int v, v1, v2;

    v  = cross(a.getX(), a.getY(), b.getX(), b.getY(), point.getX(), point.getY());
    v1 = cross(b.getX(), b.getY(), c.getX(), c.getY(), point.getX(), point.getY());
    v2 = cross(c.getX(), c.getY(), a.getX(), a.getY(), point.getX(), point.getY());

    // All positive or all negative → inside
    if ((v > 0 && v1 > 0 && v2 > 0) || (v < 0 && v1 < 0 && v2 < 0))
        return true;
    return false;
}
