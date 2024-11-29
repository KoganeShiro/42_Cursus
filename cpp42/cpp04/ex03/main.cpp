/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:28:55 by cejin             #+#    #+#             */
/*   Updated: 2024/11/28 19:20:48 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

// int main() {
//     MateriaSource* src = new MateriaSource();
//     src->learnMateria(new Cure());
    
//     Character* me = new Character("me");
    
//     AMateria* tmp;
//     tmp = src->createMateria("cure");
//     if (tmp) {
//         me->equip(tmp);
//     }
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
    
//     delete me;
//     delete src;
//     return 0;
// }

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
    me->use(3, *bob);

    //full the floor
    for (int i = 0; i < FLOOR_SPACE; i++)
    {
        if (i % 2)
            tmp = src->createMateria("ice");
        else
            tmp = src->createMateria("cure");
        me->unequip(i % 2);
        me->equip(tmp);
    }

	delete bob;
	delete me;
	delete src;
	return 0;
}
