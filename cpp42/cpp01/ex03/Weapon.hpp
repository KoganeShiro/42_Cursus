/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:52:38 by cejin             #+#    #+#             */
/*   Updated: 2024/11/17 16:07:31 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iomanip>
# include <iostream> 
# include <string>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

class Weapon
{
private:
	std::string	type;

public:
	Weapon();
	Weapon(const std::string &weaponType);
	~Weapon();
	const std::string	&getType() const;
	void				setType(const std::string &weaponType);
};


#endif
