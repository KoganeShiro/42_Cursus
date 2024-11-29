/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:40:45 by cejin             #+#    #+#             */
/*   Updated: 2024/11/26 17:41:25 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

void	WrongAnimal::setType(std::string const &type)
{
	this->type = type;
}

std::string const	WrongAnimal::getType() const
{
	return (this->type);
}

WrongAnimal::WrongAnimal() : type("Unknown WrongAnimal")
{
	std::cout << GREEN
		"WrongAnimal DEFAULT constructor is called"
	RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : type(src.type)
{
    std::cout << GREEN
		"WrongAnimal COPY constructor is called"
	RESET << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << GREEN
		"WrongAnimal COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
	if (this != &src) {
		setType(src.type);
	}
	return (*this);
}

WrongAnimal::WrongAnimal(std::string const &type) : type(type)
{
    std::cout << GREEN
		"WrongAnimal constructor is called"
	RESET << std::endl;
}

void	WrongAnimal::makeWrongSound() const
{
	std::cout << CYAN
		"Uncomprehensible wrongly sound"
	RESET << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED
		"WrongAnimal Destructor is called"
	RESET << std::endl;
}
