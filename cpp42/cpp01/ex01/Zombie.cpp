/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:29:12 by cejin             #+#    #+#             */
/*   Updated: 2024/11/16 15:04:48 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->name = "Unknown Zombie";
}

void	Zombie::set_name(const std::string &name)
{
	this->name = name;
}

void	Zombie::announce(void) const
{
	std::cout <<
		this->name + ": Grrrr, BraiiiiiiinnnzzzZ..."
	<< std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name + ": Die" << std::endl;
}
