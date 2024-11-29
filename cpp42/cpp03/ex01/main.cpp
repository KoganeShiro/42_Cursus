/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:46:40 by cejin             #+#    #+#             */
/*   Updated: 2024/11/26 09:36:46 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ClapTrap	a1("A1");
    ClapTrap	b1("B1");
	ScavTrap	gate("Gate1");

	a1.attack("Gate1");
    b1.beRepaired(10);

    gate.guardGate();
    gate.attack(a1);

    b1.attack("Gate1");
    gate.attack(b1);
    b1.attack("Gate1");
    gate.attack(b1);
	return (0);
}
