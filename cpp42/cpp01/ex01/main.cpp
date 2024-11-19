/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:01:02 by cejin             #+#    #+#             */
/*   Updated: 2024/11/16 15:02:20 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define MAX_ZOMBIES 110
#define MIN_ZOMBIES 10

#define true 1
#define false 0

static int	is_number(char *nb)
{
	for (int i = 0; nb[i] != '\0'; i++) {
		if (!(nb[i] >= '0' && nb[i] <= '9')) {
			return (false);
		}
	}
	return (true);
}

static void	create_horde(char *nb, Zombie *&horde, char *name)
{
	int	N;

	N = atoi(nb);
	if (N >= MIN_ZOMBIES && N <= MAX_ZOMBIES) {
	horde = zombieHorde(N, name);
	} else {
		std::cout <<
			YELLOW "This number cannot create an horde..." RESET
		<< std::endl;
	}
}

int main(int argc, char **argv)
{
	Zombie	*horde = NULL;

	if (argc == 3) {
		if (is_number(argv[1]) == true) {
			create_horde(argv[1], horde, argv[2]);
			delete[] horde;
		}
		else {
			std::cout <<
				RED "Please type a NUMBER (> 0) !" RESET
			<< std::endl;
		}
	}
	else {
		std::cout <<
			RED "Usage: ./zombieHorde <Nb of Zombie> <NAME>" RESET
		<< std::endl;
		return (0);
	}
	return (0);
}
