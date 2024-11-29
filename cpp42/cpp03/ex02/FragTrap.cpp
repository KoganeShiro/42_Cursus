/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:48:07 by cejin             #+#    #+#             */
/*   Updated: 2024/11/26 10:04:04 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Unknown FragTrap", 100, 100, 30)
{
	std::cout << GREEN
		"FragTrap DEFAULT constructor is called"
	RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << GREEN
		"FragTrap COPY constructor is called"
	RESET << std::endl;
}

FragTrap    &FragTrap::operator=(const FragTrap &src)
{
	std::cout << GREEN
		"FragTrap COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
	if (this != &src) {
		setClapTrap(getName(), getHitPoints(),
			getEnergyPoints(), getAttackDamage());
	}
	return (*this);
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << GREEN
		"FragTrap constructor is called"
	RESET << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << YELLOW <<
		this->getName() << " high five ✋ ! yeah 😎"
	RESET << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << RED
		"FragTrap Destructor is called"
	RESET << std::endl;
}
