/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:35:57 by cejin             #+#    #+#             */
/*   Updated: 2024/11/29 09:41:32 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

# define NB_ANIMAL 10

void testDeepCopy() {
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	Dog basic;

    basic.setIdeasInBrain("Original Idea");
    basic.setIdeasInBrain("Original Idea 2");
    {
        Dog tmp = basic;
        tmp.setIdeasInBrain("Modified Idea");
        tmp.setIdeasInBrain("Modified Idea 2");

        std::cout << "Tmp Dog's Ideas:\n";
        tmp.displayBrainIdeas(0);
        tmp.displayBrainIdeas(1);
		tmp.displayBrainIdeas(2);
        tmp.displayBrainIdeas(3);
    }

    std::cout << "Basic Dog's Ideas:\n";
    basic.displayBrainIdeas(0);
    basic.displayBrainIdeas(1);
	basic.displayBrainIdeas(2);
    basic.displayBrainIdeas(3);
}

Animal **createAnimalArray()
{
	Animal	**array = new Animal*[NB_ANIMAL];
	
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

void deleteAnimalArray(Animal **array)
{	
	for (int i = 0; NB_ANIMAL > i; i++) {
		delete array[i];
	}
	delete[] array;
}

int main()
{
	testDeepCopy();
	Animal	**array;

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
