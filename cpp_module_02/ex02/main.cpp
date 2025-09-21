/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:59:35 by meid              #+#    #+#             */
/*   Updated: 2025/09/21 14:57:08 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iomanip>

int main( void )
{
    Fixed       a;
    Fixed const b ( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}


// int main()
// {
//     Fixed a(10.5f);
//     Fixed b(2);

//     // Comparison operators
//     std::cout << "a > b : " << (a > b) << std::endl;
//     std::cout << "a < b : " << (a < b) << std::endl;
//     std::cout << "a >= b: " << (a >= b) << std::endl;
//     std::cout << "a <= b: " << (a <= b) << std::endl;
//     std::cout << "a == b: " << (a == b) << std::endl;
//     std::cout << "a != b: " << (a != b) << std::endl;

//     // Arithmetic operators
//     Fixed sum = a + b;
//     Fixed diff = a - b;
//     Fixed prod = a * b;
//     Fixed quot = a / b;

//     std::cout << "a + b = " << sum << std::endl;
//     std::cout << "a - b = " << diff << std::endl;
//     std::cout << "a * b = " << prod << std::endl;
//     std::cout << "a / b = " << quot << std::endl;

//     // Increment / Decrement
//     Fixed c = a;
//     std::cout << "c before ++c: " << c << std::endl;
//     std::cout << "++c: " << ++c << std::endl;
//     std::cout << "c after ++c: " << c << std::endl;

//     c = a;
//     std::cout << "c before c++: " << c << std::endl;
//     std::cout << "c++: " << c++ << std::endl;
//     std::cout << "c after c++: " << c << std::endl;

//     c = a;
//     std::cout << "c before --c: " << c << std::endl;
//     std::cout << "--c: " << --c << std::endl;

//     c = a;
//     std::cout << "c before c--: " << c << std::endl;
//     std::cout << "c--: " << c-- << std::endl;
//     std::cout << "c after c--: " << c << std::endl;

//     // Min / Max
//     std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
//     std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;

//     return 0;
// }
