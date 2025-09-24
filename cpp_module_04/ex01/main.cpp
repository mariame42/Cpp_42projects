/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:35:06 by meid              #+#    #+#             */
/*   Updated: 2025/09/24 13:14:20 by meid             ###   ########.fr       */
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
    std::cout << "=== EXERCISE 01: BRAIN CLASS TEST ===" << std::endl;
    
    // Test 1: Basic polymorphism as specified in subject
    std::cout << "\n--- Test 1: Basic polymorphism ---" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j; // should not create a leak
    delete i;
    
    // Test 2: Array of animals (half Dog, half Cat)
    std::cout << "\n--- Test 2: Array of animals ---" << std::endl;
    const int animals_num = 6;
    Animal* zoo[animals_num];
    
    // Create animals
    for (int idx = 0; idx < animals_num; idx++)
    {
        if (idx < animals_num / 2)
            zoo[idx] = new Cat();
        else
            zoo[idx] = new Dog();
    }
    
    // Test sounds and types
    for (int idx = 0; idx < animals_num; idx++)
    {
        std::cout << "Animal " << idx << " type: [" << zoo[idx]->getType() << "] sound: ";
        zoo[idx]->makeSound();
    }
    
    // Delete all animals (should call proper destructors)
    std::cout << "\n--- Deleting array of animals ---" << std::endl;
    for (int idx = 0; idx < animals_num; idx++)
    {
        delete zoo[idx];
    }
    
    // Test 3: Deep copy verification
    std::cout << "\n--- Test 3: Deep copy verification ---" << std::endl;
    Dog originalDog;
    Dog copiedDog(originalDog);
    
    std::cout << "Original Dog ideas (first 3): ";
    for (int i = 0; i < 3; i++)
        std::cout << originalDog.getIdea(i) << " ";
    std::cout << std::endl;
    
    std::cout << "Copied Dog ideas (first 3): ";
    for (int i = 0; i < 3; i++)
        std::cout << copiedDog.getIdea(i) << " ";
    std::cout << std::endl;
    
    // Test 4: Assignment operator deep copy
    std::cout << "\n--- Test 4: Assignment operator deep copy ---" << std::endl;
    Cat cat1;
    Cat cat2;
    cat2 = cat1;
    
    std::cout << "Cat1 ideas (first 3): ";
    for (int i = 0; i < 3; i++)
        std::cout << cat1.getIdea(i) << " ";
    std::cout << std::endl;
    
    std::cout << "Cat2 ideas (first 3): ";
    for (int i = 0; i < 3; i++)
        std::cout << cat2.getIdea(i) << " ";
    std::cout << std::endl;
    
    // Test 5: Memory leak prevention test
    std::cout << "\n--- Test 5: Memory leak prevention ---" << std::endl;
    Animal* testAnimals[4];
    testAnimals[0] = new Dog();
    testAnimals[1] = new Cat();
    testAnimals[2] = new Dog();
    testAnimals[3] = new Cat();
    
    // Delete through base class pointers (should call proper destructors)
    for (int idx = 0; idx < 4; idx++)
    {
        delete testAnimals[idx];
    }
    
    std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
}