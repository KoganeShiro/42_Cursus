/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:12:23 by cejin             #+#    #+#             */
/*   Updated: 2024/11/25 14:51:33 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap	a1("A1");
	ClapTrap	b1("B1");

	a1.attack("B1");
	b1.beRepaired(2);
	b1.beRepaired(10);
	b1.beRepaired(20);
	std::cout <<
		BLUE "A building is collapsing on the ClapTraps !" RESET
	<< std::endl;
	b1.takeDamage(10);
	a1.takeDamage(10);
	std::cout <<
		BLUE "B1, manage to go out of the collapsed building" RESET
	<< std::endl;
	for (int i = 0; i < 7; i++) {
		b1.attack("Collapsed building");
	}
	b1.beRepaired(1);
	return (0);
}
