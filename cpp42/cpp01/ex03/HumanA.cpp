/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:49:03 by cejin             #+#    #+#             */
/*   Updated: 2024/11/17 16:25:40 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

//use of member initializer list
//bc we are using &weapon, using
	//the assignment with '='
	//inside the constructor body would
	//attempt to assign to an already-initialized

HumanA::HumanA(const std::string &name, Weapon &weapon) : name(name), weapon(weapon) {}

void	HumanA::attack()
{
	std::cout <<
		CYAN +
			this->name + " attacks with their" + weapon.getType()
		+ RESET
	<< std::endl;
}

HumanA::~HumanA()
{
	std::cout <<
		RED + this->name + ": Died" RESET
	<< std::endl;
}
