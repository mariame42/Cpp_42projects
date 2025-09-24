/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:35:06 by meid              #+#    #+#             */
/*   Updated: 2025/09/08 09:35:07 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main()
// {
//     const Animal* meta = new Animal();
//     const WrongAnimal * wrong = new WrongAnimal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     const WrongAnimal * k = new WrongCat();
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     std::cout << k->getType() << " " << std::endl;
//     i->makeSound(); //will output the cat sound!
//     j->makeSound();
//     k->makeSound();
//     i->printIdeas();
//     meta->makeSound();
//     wrong->makeSound();
// }

int main()
{
    std::cout << "=== EXERCISE 02: ABSTRACT CLASS TEST ===" << std::endl;
    
    // Test 1: Demonstrate that Animal cannot be instantiated directly
    std::cout << "\n--- Test 1: Abstract class demonstration ---" << std::endl;
    std::cout << "Animal class is abstract and cannot be instantiated directly." << std::endl;
    std::cout << "Uncommenting 'Animal animal;' would cause a compilation error." << std::endl;
    
    // Test 2: Polymorphism with abstract base class
    std::cout << "\n--- Test 2: Polymorphism with abstract base class ---" << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << "Dog type: [" << dog->getType() << "]" << std::endl;
    std::cout << "Cat type: [" << cat->getType() << "]" << std::endl;
    
    std::cout << "Dog sound: ";
    dog->makeSound();
    std::cout << "Cat sound: ";
    cat->makeSound();
    
    // Test 3: Array of abstract base class pointers
    std::cout << "\n--- Test 3: Array of abstract base class pointers ---" << std::endl;
    const int animals_num = 6;
    Animal* zoo[animals_num];
    
    // Create animals (half Dog, half Cat)
    for (int idx = 0; idx < animals_num; idx++)
    {
        if (idx < animals_num / 2)
            zoo[idx] = new Cat();
        else
            zoo[idx] = new Dog();
    }
    
    // Test sounds and types through abstract base class pointers
    for (int idx = 0; idx < animals_num; idx++)
    {
        std::cout << "Animal " << idx << " type: [" << zoo[idx]->getType() << "] sound: ";
        zoo[idx]->makeSound();
    }
    
    // Test 4: Brain functionality through abstract base class
    std::cout << "\n--- Test 4: Brain functionality through abstract base class ---" << std::endl;
    std::cout << "Dog ideas (first 3): ";
    for (int i = 0; i < 3; i++)
        std::cout << dog->getIdea(i) << " ";
    std::cout << std::endl;
    
    std::cout << "Cat ideas (first 3): ";
    for (int i = 0; i < 3; i++)
        std::cout << cat->getIdea(i) << " ";
    std::cout << std::endl;
    
    // Test 5: Proper cleanup through abstract base class pointers
    std::cout << "\n--- Test 5: Proper cleanup through abstract base class pointers ---" << std::endl;
    
    // Delete individual animals
    delete dog;
    delete cat;
    
    // Delete array of animals
    for (int idx = 0; idx < animals_num; idx++)
    {
        delete zoo[idx];
    }
    
    std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
    std::cout << "Animal class is successfully abstract - cannot be instantiated directly!" << std::endl;
}