/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:35:06 by meid              #+#    #+#             */
/*   Updated: 2025/10/06 11:08:33 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "type: " << j->getType() << std::endl;
    std::cout << "type: " << i->getType() << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    
    std::cout << "\n--- WrongAnimal/WrongCat test ---" << std::endl;
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* k = new WrongCat();
    
    std::cout << "type: " << wrong->getType() << std::endl;
    std::cout << "type: " << k->getType() << std::endl;
    wrong->makeSound();
    k->makeSound();

    delete meta;
    delete j;
    delete i;
    delete wrong;
    delete k;
}