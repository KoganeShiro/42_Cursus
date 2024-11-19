/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:17:58 by cejin             #+#    #+#             */
/*   Updated: 2024/11/17 16:31:41 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	type = "Unknown type of weapon...";
}

Weapon::Weapon(const std::string &weaponType)
{
	type = weaponType;
	std::cout <<
		GREEN "Found: " + this->type + "is on the floor !" RESET
	<< std::endl;
}

const std::string&	Weapon::getType() const
{
	return (type);
}

void	Weapon::setType(const std::string &weaponType)
{
	type = weaponType;
}

Weapon::~Weapon()
{
	std::cout <<
		RED + this->type + ": has been DESTROYED" RESET
	<< std::endl;
}
