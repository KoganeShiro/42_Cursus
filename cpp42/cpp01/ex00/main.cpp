/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:29:07 by cejin             #+#    #+#             */
/*   Updated: 2024/11/16 12:57:26 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv)
{
	Zombie	*zombie;

	if (argc == 3) {
		std::cout <<
			BLUE "Store on the Heap" RESET
		<< std::endl;
		zombie = newZombie(argv[1]);
		zombie->announce();
		delete zombie;

		std::cout <<
			BLUE "Store on the Stack" RESET
		<< std::endl;
		randomChump(argv[2]);
	}
	else {
		std::cout <<
			RED "Usage: ./Zombie 1st_name 2nd_name" RESET
		<< std::endl;
		return (0);
	}
	return (0);
}
