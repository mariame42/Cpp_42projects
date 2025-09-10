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
    // const Animal* meta = new Animal();
    // const WrongAnimal * wrong = new WrongAnimal();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // const WrongAnimal * k = new WrongCat();
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // std::cout << k->getType() << " " << std::endl;
    // i->makeSound(); //will output the cat sound!
    // j->makeSound();
    // k->makeSound();
    // i->printIdeas();
    // meta->makeSound();
    // wrong->makeSound();
    int animals_num = 20;
    int i = 0;
    Animal* zoo[animals_num];
    while (i < animals_num)
    {
        if (i < animals_num / 2)
            zoo[i] = new Cat();
        else
            zoo[i] = new Dog();
        i++;
    }
    i = 0;
    while (i < animals_num)
    {
        delete zoo[i];
        i++;
    }
}