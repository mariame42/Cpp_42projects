/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:58:56 by meid              #+#    #+#             */
/*   Updated: 2025/09/22 07:45:19 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed b( a );
    Fixed c;
    c = b;
 
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0; 
}

// my main
// put OCCF = 0 to stop seeing the constructor and destructor messages

// int main( void )
// {
//     Fixed a;
//     Fixed b( a );
//     Fixed c;
//     c = b;
//     std::cout << "a.getRawBits() = " << a.getRawBits() << std::endl;
//     std::cout << "b.getRawBits() = " << b.getRawBits() << std::endl;
//     std::cout << "c.getRawBits() = " << c.getRawBits() << std::endl;
//     std::cout << "a.setRawBits(7)" << std::endl;
//     a.setRawBits(7);
//     std::cout << "a.getRawBits() = " << a.getRawBits() << std::endl;
//     std::cout << "b.getRawBits() = " << b.getRawBits() << std::endl;
//     std::cout << "b.setRawBits(10)" << std::endl;
//     b.setRawBits(10);
//     std::cout << "b.getRawBits() = " << b.getRawBits() << std::endl;
//     std::cout << "c.getRawBits() = " << c.getRawBits() << std::endl;
//     return 0;
// }