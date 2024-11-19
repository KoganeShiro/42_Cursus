/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:29:09 by cejin             #+#    #+#             */
/*   Updated: 2024/11/16 15:04:48 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*horde;
	int		i = 0;

	horde = new Zombie[N];
	while (i < N)
	{
		horde[i].set_name(name);
		horde[i].announce();
		i++;
	}
	return (horde);
}
