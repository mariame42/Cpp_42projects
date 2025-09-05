/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:59:35 by meid              #+#    #+#             */
/*   Updated: 2025/09/04 20:36:24 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iomanip>

// int main( void )
// {
//     Fixed       a;
//     Fixed const b ( Fixed( 5.05f ) * Fixed( 2 ) );

//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max( a, b ) << std::endl;
//     return 0;
// }

// ============================================================================
// COMPREHENSIVE FIXED-POINT DEMONSTRATION
// ============================================================================

int main( void ) {
    std::cout << "\n=== FIXED-POINT vs FLOAT COMPARISON ===" << std::endl;
    
    // PRECISION COMPARISON (0.1 + 0.2 problem)
    std::cout << "\nPRECISION COMPARISON (0.1 + 0.2):" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    
    float f1 = 0.1f;
    float f2 = 0.2f;
    float f3 = f1 + f2;
    
    Fixed fixed1(0.1f);
    Fixed fixed2(0.2f);
    Fixed fixed3 = fixed1 + fixed2;  // Using our operator!
    
    std::cout << "Float: 0.1 + 0.2 = " << f3 << std::endl;
    std::cout << "Float (full precision): 0.1 + 0.2 = " << std::fixed << std::setprecision(20) << f3 << std::endl;
    std::cout << "Fixed: 0.1 + 0.2 = " << std::setprecision(20) << fixed3 << std::endl;
    std::cout << "Expected: 0.3" << std::endl;
    
    // REAL USE CASE: MONEY CALCULATIONS
    std::cout << "\nREAL USE CASE: MONEY CALCULATIONS:" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    
    // Using floats (normal calculation)
    float price_float = 19.99f;
    float tax_rate_float = 0.08f;  // 8% tax
    float quantity_float = 3.0f;
    
    float subtotal_float = price_float * quantity_float;
    float tax_float = subtotal_float * tax_rate_float;
    float total_float = subtotal_float + tax_float;
    
    // Using Fixed class
    Fixed price_fixed(19.99f);
    Fixed tax_rate_fixed(0.08f);  // 8% tax
    Fixed quantity_fixed(3);
    
    Fixed subtotal_fixed = price_fixed * quantity_fixed;
    Fixed tax_fixed = subtotal_fixed * tax_rate_fixed;
    Fixed total_fixed = subtotal_fixed + tax_fixed;
    
    std::cout << "FLOAT CALCULATIONS:" << std::endl;
    std::cout << "Price: $" << price_float << std::endl;
    std::cout << "Quantity: " << quantity_float << std::endl;
    std::cout << "Subtotal: $" << subtotal_float << std::endl;
    std::cout << "Tax (8%): $" << tax_float << std::endl;
    std::cout << "Total: $" << total_float << std::endl;
    
    std::cout << "\nFIXED CALCULATIONS:" << std::endl;
    std::cout << "Price: $" << price_fixed << std::endl;
    std::cout << "Quantity: " << quantity_fixed.toInt() << std::endl;
    std::cout << "Subtotal: $" << subtotal_fixed << std::endl;
    std::cout << "Tax (8%): $" << tax_fixed << std::endl;
    std::cout << "Total: $" << total_fixed << std::endl;
    
    // COMPARISON: Which is more accurate?
    std::cout << "\nCOMPARISON:" << std::endl;
    std::cout << "Float total: $" << total_float << std::endl;
    std::cout << "Fixed total: $" << total_fixed << std::endl;
    std::cout << "Difference: $" << (total_float - total_fixed.toFloat()) << std::endl;
    
    return 0;
}

