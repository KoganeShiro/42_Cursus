/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:55:41 by cejin             #+#    #+#             */
/*   Updated: 2024/11/27 16:04:27 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Aanimal.hpp"

void	Aanimal::setType(std::string const &type)
{
	this->type = type;
}

std::string const	Aanimal::getType() const
{
	return (this->type);
}

Aanimal::Aanimal() : type("Unknown Animal")
{
	std::cout << GREEN
		"Animal DEFAULT constructor is called"
	RESET << std::endl;
}

Aanimal::Aanimal(const Aanimal &src) : type(src.type)
{
    std::cout << GREEN
		"Aanimal COPY constructor is called"
	RESET << std::endl;
}

Aanimal	&Aanimal::operator=(const Aanimal &src)
{
	std::cout << GREEN
		"Aanimal COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
	if (this != &src) {
		setType(src.type);
	}
	return (*this);
}

Aanimal::Aanimal(std::string const &type) : type(type)
{
    std::cout << GREEN
		"Aanimal constructor is called"
	RESET << std::endl;
}

Aanimal::~Aanimal()
{
	std::cout << RED
		"Aanimal Destructor is called"
	RESET << std::endl;
}
