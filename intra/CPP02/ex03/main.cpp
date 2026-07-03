/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:59:49 by meid              #+#    #+#             */
/*   Updated: 2025/09/22 07:56:36 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
    try {
        Point a(0.0f, 0.0f);
        Point b(1.5f, 2.5f);
        Point c(3.0f, 4.0f);
    
        // Inside
        Point p_inside(1.0f, 1.5f);
        if (bsp(a, b, c, p_inside))
            std::cout << YELLOW << "The point (2.5f, 2.0) is inside the triangle." << RESET << std::endl;
        else
            std::cout << YELLOW << "The point (2.5f, 2.0) is outside the triangle." << RESET << std::endl;
    
        // Outside
        Point p_outside(4.0f, 1.0f);
        if (bsp(a, b, c, p_outside))
            std::cout << YELLOW << "The point (4.0, 1.0) is inside the triangle." << RESET << std::endl;
        else
            std::cout << YELLOW << "The point (4.0, 1.0) is outside the triangle." << RESET << std::endl;
    
        // On the edge
        Point p_on(0.75f, 1.25f); // lies on line AB
        if (bsp(a, b, c, p_on))
            std::cout << YELLOW << "The point (0.75, 1.25) is inside the triangle." << RESET << std::endl;
        else 
            std::cout << YELLOW << "The point (0.75, 1.25) is outside the triangle." << RESET << std::endl;
    }
    catch(const std::exception& e) {
        std::cout << RED << "ERROR: " << e.what() << RESET << std::endl;
    }
    return 0;
}
