/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:55:54 by cejin             #+#    #+#             */
/*   Updated: 2024/11/17 16:35:41 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name)
{
	this->name = name;
	this->weapon = NULL;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack()
{
	if (weapon != NULL) {
		std::cout <<
			CYAN +
				this->name + " attacks with their" + weapon->getType()
			+ RESET
		<< std::endl;
	}
	else {
		std::cout <<
			BLUE + this->name +
				 " attacks with...\nnothing.\nWait that's illegal !"
			RESET
		<< std::endl;
	}
}

HumanB::~HumanB()
{
	std::cout <<
		RED + this->name + ": Died" RESET
	<< std::endl;
}
