/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:52:25 by cejin             #+#    #+#             */
/*   Updated: 2024/11/26 10:25:39 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    FragTrap    z1("Z1");
    ClapTrap	a1("A1");
    ClapTrap	b1("B1");
	ScavTrap	gate("Gate1");

    a1.attack("Gate1");
    gate.guardGate();
    b1.beRepaired(10);
    gate.attack(a1);

    z1.attack("Gate1");
    gate.takeDamage(z1.getAttackDamage());
    b1.attack("Gate1");
    for (int i = 0; i < 3; i++) {
        z1.attack("Gate1");
        gate.takeDamage(z1.getAttackDamage());
        b1.beRepaired(5);
        gate.attack(b1);
    }
    z1.attack("Gate1");
    gate.takeDamage(z1.getAttackDamage());
    z1.highFivesGuys();
}
