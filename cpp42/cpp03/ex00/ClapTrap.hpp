/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:06:55 by cejin             #+#    #+#             */
/*   Updated: 2024/11/25 14:47:52 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

class ClapTrap
{
private:
	std::string	name;
	int			hitPoints; //health
	int			energyPoints;
	int			attackDamage;

public:
	ClapTrap();
	ClapTrap(const ClapTrap &src);
	ClapTrap &operator = (const ClapTrap &src);
	ClapTrap(std::string const &name);
	~ClapTrap();

	void setClapTrap(std::string const &name, int health, int energy, int atk);
	void updateHitPoints(int damage);
	int getHitPoints(void);
	void updateEnergyPoints(void);
	void updateAttackDamage(int atk);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
