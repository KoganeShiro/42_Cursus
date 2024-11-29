/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:35:57 by cejin             #+#    #+#             */
/*   Updated: 2024/11/27 16:13:27 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

# define NB_ANIMAL 10

void testDeepCopy() {
	const Aanimal* j = new Dog();
	const Aanimal* i = new Cat();

	delete j;//should not create a leak
	delete i;
}

Aanimal **createAnimalArray()
{
	Aanimal	**array = new Aanimal*[NB_ANIMAL];
	
	for (int i = 0; NB_ANIMAL > i; i++) {
		if ((NB_ANIMAL / 2) > i) {
			array[i] = new Dog();
		}
		else {
			array[i] = new Cat();
		}
	}
	return (array);
}

void	initIdeas(Dog *dog)
{
	std::cout << MAGENTA "animal: " <<
		dog->getType() <<
	RESET << std::endl;

	dog->setIdeasInBrain("Let's play !!");
	dog->displayBrainIdeas(0);
	dog->displayBrainIdeas(1);
}

void deleteAnimalArray(Aanimal **array)
{	
	for (int i = 0; NB_ANIMAL > i; i++) {
		delete array[i];
	}
	delete[] array;
}

int main()
{
	testDeepCopy();
	Aanimal	**array;

	array = createAnimalArray();
	initIdeas(static_cast<Dog*>(array[0]));

	for (int i = 0; i < NB_ANIMAL; i++) {
		std::cout << CYAN "animal: " <<
			array[i]->getType() <<
		RESET << std::endl;
		array[i]->makeSound();
	} 
	std::cout << "\n";
	deleteAnimalArray(array);
	return 0;
}
/*
Aanimal animal;     // Direct instantiation (invalid)
Aanimal* animalPtr; // Pointer to abstract class (valid)

Cat cat;
animalPtr = &cat;   // Base class pointer referring to derived class object (valid)
*/