/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:26:21 by meid              #+#    #+#             */
/*   Updated: 2025/11/07 17:26:22 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
    Base *base = generate();
    Base *base1 = generate();
    Base *base2 = generate();
    Base *base3 = generate();
    Base *base4 = generate();
    Base *base5 = generate();
    Base *base6 = generate();
    Base *base7 = generate();
    Base *base8 = generate();
    Base *base9 = generate();
    identify(base);
    identify(base1);
    identify(base2);
    identify(base3);
    identify(base4);
    identify(base5);
    identify(base6);
    identify(base7);
    identify(base8);
    identify(base9);
    identify(*base);
    delete base;
    delete base1;
    delete base2;
    delete base3;
    delete base4;
    delete base5;
    delete base6;
    delete base7;
    delete base8;
    delete base9;
    return 0;
}

