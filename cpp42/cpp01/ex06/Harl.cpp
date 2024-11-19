/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:44:32 by cejin             #+#    #+#             */
/*   Updated: 2024/11/18 16:24:43 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << CYAN
		"Welcome I'm Harl ! Your personnal assistant 😮‍💨.\nRemember to pay me proprely"
	RESET << std::endl;
}

Harl::~Harl()
{
	std::cout << RED
		"Hey don't turn me off now ! You didn't pay me !!"
	RESET << std::endl;
}

void	Harl::debug( void )
{
	std::cout << GREEN
		DEBUG_MSG
	RESET << std::endl;
}

void	Harl::info( void )
{
	std::cout << BLUE
		INFO_MSG
	RESET << std::endl;
}

void	Harl::warning( void )
{
	std::cout << YELLOW
		WARNING_MSG
	RESET << std::endl;
}

void	Harl::error( void )
{
	std::cout << RED
		ERROR_MSG
	RESET << std::endl;
}

//declaration of an array of pointers
	//to member functions of a class
		//(Class::*fxptr[])()

void	Harl::complain(std::string level)
{
	static void	(Harl::*fxptr[LEVEL_NB])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	static std::string	levelTab[LEVEL_NB] = {
		"DEBUG", "INFO", "WARNING", "ERROR" 
	};
	int	i = 0;

	while (level != levelTab[i] && i < LEVEL_NB) {
		i++;
	}
	switch(i) {
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			(this->*fxptr[0])();
			/* fallthrough */
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			(this->*fxptr[1])();
			/* fallthrough */
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			(this->*fxptr[2])();
			/* fallthrough */
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			(this->*fxptr[3])();
			break ;
		default:
			std::cout << DEFAULT << std::endl;
			break;
	}
}
