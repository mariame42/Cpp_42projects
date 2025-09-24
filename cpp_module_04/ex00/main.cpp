/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:35:06 by meid              #+#    #+#             */
/*   Updated: 2025/09/24 12:46:23 by meid             ###   ########.fr       */
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
    // Basic polymorphism test as specified in the subject
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
    // WrongAnimal/WrongCat test to show non-virtual behavior
    std::cout << "\n--- WrongAnimal/WrongCat test ---" << std::endl;
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* k = new WrongCat();
    
    std::cout << wrong->getType() << " " << std::endl;
    std::cout << k->getType() << " " << std::endl;
    wrong->makeSound();
    k->makeSound(); // This calls WrongAnimal's makeSound, not WrongCat's
    
    // Clean up memory
    delete meta;
    delete j;
    delete i;
    delete wrong;
    delete k;
}