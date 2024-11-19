/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:18:16 by cejin             #+#    #+#             */
/*   Updated: 2024/11/17 16:36:03 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

/*
In which case do you think it would be best
	to use a pointer to Weapon?
		---> Weapon in HumanB because it can be == NULL
				we can also reassign a var with a pointer
	And a reference to Weapon? Why?
		---> for HumanA bc ref cannot be == NULL
				we can't reassign a var with ref
Think about it before starting this exercise
*/

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		HumanB jim("Jim");
		//jim.attack();
		Weapon club = Weapon("crude spiked club");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
