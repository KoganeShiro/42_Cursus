/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:55:38 by cejin             #+#    #+#             */
/*   Updated: 2024/11/16 11:14:51 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string name)
{
	this->name = name;
}

void	Zombie::announce(void) const
{
	std::cout <<
		this->name + ": BraiiiiiiinnnzzzZ..."
	<< std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name + ": Die" << std::endl;
}
