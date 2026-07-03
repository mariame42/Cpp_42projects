/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:59:35 by meid              #+#    #+#             */
/*   Updated: 2025/09/22 07:45:06 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void testBasicCases() {
    std::cout << "\n=== BASIC CASES ===" << std::endl;
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    a = Fixed(1234.4321f);

    std::cout << "a = " << a << ", as int: " << a.toInt() << ", as float: " << a.toFloat() << std::endl;
    std::cout << "b = " << b << ", as int: " << b.toInt() << ", as float: " << b.toFloat() << std::endl;
    std::cout << "c = " << c << ", as int: " << c.toInt() << ", as float: " << c.toFloat() << std::endl;
    std::cout << "d = " << d << ", as int: " << d.toInt() << ", as float: " << d.toFloat() << std::endl;
}

void testBigNumbers() {
    std::cout << "\n=== BIG NUMBERS TEST ===" << std::endl;

    try {
        Fixed large1(FIXED_MAX);
        std::cout << "FIXED_MAX = " << large1 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error FIXED_MAX: " << e.what() << std::endl;
    }

    try {
        Fixed large2(FIXED_MIN);
        std::cout << "FIXED_MIN = " << large2 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error FIXED_MIN: " << e.what() << std::endl;
    }

    try {
        Fixed tooBig(FIXED_MAX + 1);
        std::cout << "Too big = " << tooBig << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught too big: " << e.what() << std::endl;
    }
}

void testSpecialFloatValues() {
    std::cout << "\n=== SPECIAL FLOAT VALUES TEST ===" << std::endl;

    try {
        Fixed inf(std::numeric_limits<float>::infinity());
        std::cout << "Infinity = " << inf << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught infinity: " << e.what() << std::endl;
    }

    try {
        Fixed ninf(-std::numeric_limits<float>::infinity());
        std::cout << "Negative infinity = " << ninf << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught -infinity: " << e.what() << std::endl;
    }

    try {
        Fixed nan(std::numeric_limits<float>::quiet_NaN());
        std::cout << "NaN = " << nan << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught NaN: " << e.what() << std::endl;
    }
}

void testArithmetic() {
    std::cout << "\n=== ARITHMETIC TESTS ===" << std::endl;
    Fixed a(5);
    Fixed b(2);

    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "a / b = " << (a / b) << std::endl;

    try {
        Fixed divZero = a / Fixed(0);
        std::cout << "a / 0 = " << divZero << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught div by zero: " << e.what() << std::endl;
    }
}

void testIncrementDecrement() {
    std::cout << "\n=== INCREMENT / DECREMENT TESTS ===" << std::endl;
    Fixed x;

    std::cout << "x = " << x << std::endl;
    std::cout << "x++ = " << x++ << ", after = " << x << std::endl;
    std::cout << "++x = " << ++x << ", after = " << x << std::endl;
    std::cout << "x-- = " << x-- << ", after = " << x << std::endl;
    std::cout << "--x = " << --x << ", after = " << x << std::endl;

    try {
        Fixed max(FIXED_MAX);
        ++max;
    } catch (const std::exception& e) {
        std::cout << "Caught pre-increment overflow: " << e.what() << std::endl;
    }

    try {
        Fixed min(FIXED_MIN);
        --min;
    } catch (const std::exception& e) {
        std::cout << "Caught pre-decrement overflow: " << e.what() << std::endl;
    }
}

int main() {
    testBasicCases();
    testBigNumbers();
    testSpecialFloatValues();
    testArithmetic();
    testIncrementDecrement();
    return 0;
}
