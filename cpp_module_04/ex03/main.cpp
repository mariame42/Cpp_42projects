/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:10:46 by meid              #+#    #+#             */
/*   Updated: 2025/10/02 20:47:55 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstract/AMateria.hpp"
#include "derived/Cure.hpp"
#include "derived/Ice.hpp"
#include "Interface/ICharacter.hpp"
#include "derived/Character.hpp"
#include "Interface/IMateriaSource.hpp"

int main(void)
{
    ICharacter *lola = new Character("lola");
    AMateria *cure_por = new Cure();
    cure_por->use(*lola );

    ICharacter *Bob = new Character("Bob");
    AMateria *ice_cube = new Ice();
    ice_cube->use(*Bob);
}


// int main(void)
// {
//     std::cout << "makefile works" << std::endl;
// }

// int main()
// {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     ICharacter* me = new Character("me");
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);
//     delete bob;
//     delete me;
//     delete src;
//     return 0;
// }