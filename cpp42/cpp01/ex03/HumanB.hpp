/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:00:55 by cejin             #+#    #+#             */
/*   Updated: 2024/11/17 15:57:30 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	Weapon  *weapon;
	std::string name;

public:
	HumanB(const std::string &name);
	~HumanB();

	void	setWeapon(Weapon &weapon);
	void	attack();
};

#endif