/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:10:54 by cejin             #+#    #+#             */
/*   Updated: 2024/11/26 10:24:25 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void ClapTrap::updateHitPoints(int damage)
{
	this->hitPoints -= damage;
}

int ClapTrap::getHitPoints(void)
{
	return (this->hitPoints);
}

int ClapTrap::getEnergyPoints(void)
{
	return (this->energyPoints);
}

int ClapTrap::getAttackDamage(void)
{
	return (this->attackDamage);
}

const std::string ClapTrap::getName(void)
{
	return (this->name);
}

void ClapTrap::updateEnergyPoints(void)
{
	this->energyPoints--;
}

void ClapTrap::updateAttackDamage(int atk)
{
	this->attackDamage = atk;
}

void ClapTrap::setClapTrap(std::string const &name,
	int health, int energy, int atk)
{
	this->name = name;
	this->hitPoints = health;
	this->energyPoints = energy;
	this->attackDamage = atk;
}

ClapTrap::ClapTrap() : name("Unknown ClapTrap"),
						hitPoints(10),
						energyPoints(10),
						attackDamage(0)
{
	std::cout << GREEN
		"ClapTrap DEFAULT constructor is called"
	RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) : name(src.name),
						hitPoints(src.hitPoints),
						energyPoints(src.energyPoints),
						attackDamage(src.attackDamage)
{
	std::cout << GREEN
		"ClapTrap COPY constructor is called"
	RESET << std::endl;
}

ClapTrap    &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << GREEN
		"ClapTrap COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
	if (this != &src) {
		this->name = src.name;
		this->hitPoints = src.hitPoints;
		this->attackDamage = src.attackDamage;
		this->energyPoints = src.energyPoints;
	}
	return (*this);
}

ClapTrap::ClapTrap(std::string const &name)
{
	std::cout << GREEN
		"ClapTrap constructor is called"
	RESET << std::endl;
	setClapTrap(name, 10, 10, 0);
}

ClapTrap::ClapTrap(const std::string name, int hitPoints, int energyPoints, int attackDamage) :
name(name), hitPoints(hitPoints), energyPoints(energyPoints), attackDamage(attackDamage)
{
	std::cout << GREEN
		"Set all, constructor is called"
	RESET << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->getHitPoints() <= 0) {
		std::cout <<
			this->name << " wants to attack but is already dead... ⚰️💀💀"
		<< std::endl;
		return ;
	}
	updateEnergyPoints();
	if (energyPoints > 0) {
		std::cout <<
			"With " << this->hitPoints << " HP "
			<< this->name << " attacks " << target
			<< ", causing " << this->attackDamage
			<< " points of damage ! ⚡🗡️"
		<< std::endl;
	}
	else {
		std::cout <<
			"ClapTrap " << this->name
			<< " wants to attack but don't have enough energy 🪫🪫..."
		<< std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints <= 0) {
		std::cout <<
			this->name << " is already dead 😱"
				" you can't attack its corpse like that !"
		<< std::endl;
		return ;
	}
	std::cout <<
		"With " << this->hitPoints << " HP " << this->name << " takes " << amount
		<< " point of damage ! 🫨😵‍💫🤕"
	<< std::endl;
	updateHitPoints(amount);
	if (this->hitPoints <= 0) {
		std::cout <<
			"ClapTrap " << this->name << " is now dead ☠️ 🪦..."
		<< std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	updateEnergyPoints();
	if (energyPoints > 0) {
		this->hitPoints += amount;
		std::cout <<
			this->name << " repair itself " << amount
			<< " HP !\n\t" << this->name << " now have "
			<< this->hitPoints << " 🛠️"
		<< std::endl;
	}
	else {
		std::cout <<
			"ClapTrap " << this->name
			<< " want to repair itself but don't have enough energy 🪫🪫..."
		<< std::endl;
	}
}

ClapTrap::~ClapTrap()
{
	std::cout << RED
		"ClapTrap Destructor is called"
	RESET << std::endl;
}
