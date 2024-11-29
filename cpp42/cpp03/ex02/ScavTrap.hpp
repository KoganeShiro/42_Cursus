/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:56:29 by cejin             #+#    #+#             */
/*   Updated: 2024/11/26 09:45:49 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

// inheritance
class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const ScavTrap &src);
	ScavTrap &operator=(const ScavTrap &src);
	ScavTrap(std::string const &name);
	~ScavTrap();

	void guardGate();
	void attack(ClapTrap &target);
};

// Destruction is in reverse order. Why?
	//Because we need to destroy ScavTrap first so we can destroy ClapTrap
	//if we destroy ClapTrap, how can we destroy ScavTrap ?