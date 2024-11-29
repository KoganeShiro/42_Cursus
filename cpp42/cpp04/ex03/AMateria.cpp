/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:29:53 by cejin             #+#    #+#             */
/*   Updated: 2024/11/28 18:08:33 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("Unknown materia")
{
	std::cout << GREEN
		"AMateria DEFAULT constructor is called"
	RESET << std::endl;
}

AMateria::AMateria(const AMateria &src) : type(src.type)
{
    std::cout << GREEN
		"AMateria COPY constructor is called"
	RESET << std::endl;
}

AMateria	&AMateria::operator=(const AMateria &src)
{
	std::cout << GREEN
		"AMateria COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
	if (this != &src) {
		*this = src;
	}
	return (*this);
}

AMateria::AMateria(std::string const &type) : type(type)
{
    std::cout << GREEN
		"AMateria constructor is called"
	RESET << std::endl;
}

AMateria::~AMateria()
{
	std::cout << RED
		"AMateria Destructor is called"
	RESET << std::endl;
}
