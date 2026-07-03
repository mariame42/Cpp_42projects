/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:26:05 by meid              #+#    #+#             */
/*   Updated: 2025/11/08 21:42:31 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base::~Base() {}

Base *generate(void)
{
    static bool seeded = false;
    if (!seeded) { std::srand(static_cast<unsigned int>
        (std::chrono::high_resolution_clock::now().time_since_epoch().count()));
        seeded = true; }

    int r = static_cast<int>( std::rand() % 3);
    if (r == 0)
        return new A();
    else if (r == 1)
        return new B();
    else
        return new C();
}

// dynamic_cast checks the actual type of the object at runtime using
// Run-Time Type Information (RTTI) to ensure the conversion is valid.
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << RED << "your allowed to send only A B C classes" << RESET << std::endl;
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (...) {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch (...) {
            try {
                (void)dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }
            catch (...) {
                std::cout << RED << "your allowed to send only A B C classes" << RESET << std::endl;
            }
        }
    }
}