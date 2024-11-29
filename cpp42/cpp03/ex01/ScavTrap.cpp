/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:57:46 by cejin             #+#    #+#             */
/*   Updated: 2024/11/26 10:24:29 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Unknown ScavTrap", 100, 50, 20)
{
	std::cout << GREEN
		"ScavTrap DEFAULT constructor is called"
	RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << GREEN
		"ScavTrap COPY constructor is called"
	RESET << std::endl;
}

ScavTrap    &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << GREEN
		"ScavTrap COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
	if (this != &src) {
		setClapTrap(getName(), getHitPoints(),
			getEnergyPoints(), getAttackDamage());
	}
	return (*this);
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << GREEN
		"ScavTrap constructor is called"
	RESET << std::endl;
}

void	ScavTrap::attack(ClapTrap &target)
{
	if (this->getHitPoints() <= 0) {
		std::cout <<
			this->getName() << " wants to attack but is already dead... ⚰️💀💀"
		<< std::endl;
		return ;
	}
	this->updateEnergyPoints();
	if (this->getEnergyPoints() > 0) {
		std::cout <<
			"With " << this->getHitPoints() << " HP "
			<< this->getName() << " attacks " << target.getName()
			<< ", causing " << this->getAttackDamage()
			<< " points of damage ! ⚡🗡️"
		<< std::endl;
		target.takeDamage(this->getAttackDamage());
	}
	else {
		std::cout <<
			"ClapTrap " << this->getName()
			<< " wants to attack but don't have enough energy 🪫🪫..."
		<< std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << MAGENTA <<
		this->getName() << " is now in Gate keeper mode"
	RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << RED
		"ScavTrap Destructor is called"
	RESET << std::endl;
}
