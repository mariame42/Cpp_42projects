/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:59:05 by meid              #+#    #+#             */
/*   Updated: 2025/09/21 14:27:28 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <limits>

void testBasicCases() {
    std::cout << "\n=== BASIC CASES ===" << std::endl;
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    a = Fixed(1234.4321f);
    
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    std::cout << "a is " << a.toFloat() << " as float" << std::endl;
    std::cout << "b is " << b.toFloat() << " as float" << std::endl;
}

void testBigNumbers() {
    std::cout << "\n=== BIG NUMBERS TEST ===" << std::endl;

    try {
        Fixed largeInt1(2147483647);
        std::cout << "INT_MAX: " << largeInt1 << " (raw: " << largeInt1.getRawBits() << ")" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        Fixed largeInt2(-2147483647); // INT_MIN + 1 (to avoid ambiguity)
        std::cout << "INT_MIN: " << largeInt2 << " (raw: " << largeInt2.getRawBits() << ")" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        Fixed largeInt3(1000000000);
        std::cout << "1 billion: " << largeInt3 << " (raw: " << largeInt3.getRawBits() << ")" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void testSpecialFloatValues() {
    std::cout << "\n=== SPECIAL FLOAT VALUES TEST ===" << std::endl;

    try {
        Fixed inf1(std::numeric_limits<float>::infinity());
        std::cout << "Positive infinity: " << inf1 << " (raw: " << inf1.getRawBits() << ")" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        Fixed inf2(-std::numeric_limits<float>::infinity());
        std::cout << "Negative infinity: " << inf2 << " (raw: " << inf2.getRawBits() << ")" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
        Fixed nan(std::numeric_limits<float>::quiet_NaN());
        std::cout << "NaN: " << nan << " (raw: " << nan.getRawBits() << ")" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

int main() {
    testBasicCases();
    testBigNumbers();
    testSpecialFloatValues();
    return 0;
}