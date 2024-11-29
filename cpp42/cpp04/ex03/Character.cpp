/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:56:24 by cejin             #+#    #+#             */
/*   Updated: 2024/11/28 19:18:30 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("Nobody")
{
	std::cout << GREEN
		"Character DEFAULT constructor is called"
	RESET << std::endl;
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        this->inventory[i] = NULL;
    }
    for (int i = 0; i < FLOOR_SPACE; i++) {
        this->floor[i] = NULL;
    }
}

Character::Character(const Character &src) : name(src.name)
{
    std::cout << GREEN
		"Character COPY constructor is called"
	RESET << std::endl;
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        this->inventory[i] = src.inventory[i];
    }
    for (int i = 0; i < FLOOR_SPACE; i++) {
        this->floor[i] = src.floor[i];
    }
}

Character	&Character::operator=(const Character &src)
{
	std::cout << GREEN
		"Character COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
	if (this != &src) {
		*this = src;
	}
	return (*this);
}

Character::Character(std::string const &name) : name(name)
{
    std::cout << GREEN
		"Character NAME constructor is called"
	RESET << std::endl;
    for (int i = 0; i < INVENTORY_SIZE; ++i) {
        this->inventory[i] = NULL;
    }
    for (int i = 0; i < FLOOR_SPACE; ++i) {
        this->floor[i] = NULL;
    }
}

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    if (m == NULL) {
        std::cout << "Cannot equip a null materia!" << std::endl;
        return;
    }
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (this->inventory[i] == m) {
            std::cout << "This materia is already equipped!" << std::endl;
            return;
        }
    }
    for (int i = 0; i < INVENTORY_SIZE; ++i) {
        if (this->inventory[i] == 0) {
            std::cout << m->getType() << " Equiped" << std::endl;
            this->inventory[i] = m;
            return ;
        }
    }
    std::cout << ORANGE
    "The inventory of " << this->getName() << " is full !\n"
    "You need to unequip/use an element"
    RESET << std::endl;
    delete m;
}

//must NOT delete the AMateria

void Character::unequip(int idx)
{
    static int floorIdx = 0;

    if (idx < 0 || idx > INVENTORY_SIZE) {
        std::cout << YELLOW
            << "Invalid inventory position: " << idx << "🫠🙃"
            << RESET << std::endl;
        return;
    }
    if (this->inventory[idx] == 0) {
        std::cout << YELLOW
            "Hey the inventory " << idx << " position is not set !"
            " You can't unequip something that don't exist 🫠"
        << std::endl;
        return ;
    }
    if (floorIdx > FLOOR_SPACE) {
        std::cout << YELLOW
            "The floor is already full 💀 ! "
        << std::endl;
        return ;
    }
    this->floor[floorIdx] = this->inventory[idx];
    std::cout <<
        "Unequip " << this->floor[floorIdx]->getType() << " at "
        << idx << " index in inventory"
        << " on the floor at index " << floorIdx
    << std::endl;
    floorIdx++;
    this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (this->inventory[idx] == 0) {
        std::cout << YELLOW
            "Hey the inventory " << idx << " position is not set !"
            " You can't use something that don't exist 🙃🙃"
        << std::endl;
    }
    else if (idx < INVENTORY_SIZE && idx >= 0) {
        this->inventory[idx]->use(target);
    }
    else {
        std::cout << ORANGE
            << idx << ": Invalid inventory index !"
        << RESET << std::endl;
    }
}

void Character::getFullInventory() const
{
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (this->inventory[i] != 0) {
            std::cout <<
                "Index: " << i << " | Materia: "
                << this->inventory[i]->getType()
            << std::endl;
        }
        else {
            std::cout <<
                "Index: " << i << " | Materia: "
                ORANGE "Not Set" RESET
            << std::endl;
        }
    }
}

void Character::getInventoryById(int idx)
{
    if (idx < INVENTORY_SIZE && idx >= 0) {
        if (this->inventory[idx] != 0) {
            std::cout <<
                "Index: " << idx << " | Materia: "
                << this->inventory[idx]->getType()
            << std::endl;
        }
        else {
            std::cout <<
                "Index: " << idx << " | Materia: "
                ORANGE "Not Set" RESET
            << std::endl;
        }
        return ;
    }
    std::cout << ORANGE
        "The index [" << idx << "] is not between [0;3] !"
    RESET << std::endl;
}

Character::~Character()
{
	std::cout << RED
		"Character Destructor is called"
	RESET << std::endl;
    for (int i = 0; i < INVENTORY_SIZE; ++i) {
        if (this->inventory[i] != 0) {
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
    }
    for (int i = 0; i < FLOOR_SPACE; ++i) {
        if (this->floor[i] != 0) {
            delete this->floor[i];
            this->floor[i] = NULL;
        }
    }
}
