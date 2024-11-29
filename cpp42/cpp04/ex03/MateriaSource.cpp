/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:50:29 by cejin             #+#    #+#             */
/*   Updated: 2024/11/28 19:14:37 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << GREEN
		"MateriaSource DEFAULT constructor is called"
	RESET << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++) {
        this->learnInventory[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
    std::cout << GREEN
		"MateriaSource COPY constructor is called"
	RESET << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++) {
        this->learnInventory[i] = src.learnInventory[i];
    }
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &src)
{
	std::cout << GREEN
		"MateriaSource COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
	if (this != &src) {
		*this = src;
	}
	return (*this);
}

// learnMateria(AMateria*)
// Copies the Materia passed as a parameter and store it in memory so it can be cloned
// later. Like the Character, the MateriaSource can know at most 4 Materias. They
// are not necessarily unique.

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m) {
		return ;
	}
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (this->learnInventory[i] == 0) {
			this->learnInventory[i] = m;
			return ;
		}
	}
	std::cout << ORANGE
    "The learnInventory of MateriaSource is full !"
    RESET << std::endl;
}


// createMateria(std::string const &)
// Returns a new Materia. The latter is a copy of the Materia previously learned by
// the MateriaSource whose type equals the one passed as parameter. Returns 0 if
// the type is unknown.

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (type != "ice" && type != "cure") {
		std::cout << ORANGE <<
		type << " is not a correct type !"
		RESET << std::endl;
		return (0);
	}
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (this->learnInventory[i]->getType() == type) {
			return (this->learnInventory[i]->clone());
		}
	}
	std::cout << ORANGE
    "The " << type << " type is not in the learnInventory"
    RESET << std::endl;
	return (0);
}

MateriaSource::~MateriaSource()
{
	std::cout << RED
		"MateriaSource Destructor is called"
	RESET << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (this->learnInventory[i] != 0) {
            delete this->learnInventory[i];
			this->learnInventory[i] = NULL;
        }
    }
}
