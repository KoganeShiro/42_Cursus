/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:41:56 by cejin             #+#    #+#             */
/*   Updated: 2024/11/28 15:40:56 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << GREEN
		"WrongCat DEFAULT constructor is called"
	RESET << std::endl;
	this->setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	std::cout << GREEN
		"WrongCat COPY constructor is called"
	RESET << std::endl;
	*this = src;
}

WrongCat	&WrongCat::operator=(const WrongCat &src)
{
	std::cout << GREEN
		"WrongCat COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
	if (this != &src) {
		this->setType(src.type);
	}
	return (*this);
}

WrongCat::WrongCat(std::string const &type)
{
	std::cout << GREEN
		"WrongCat constructor is called"
	RESET << std::endl;
	this->setType(type);
}

void	WrongCat::makeWrongSound() const
{
	std::cout << CYAN
		"Miouf Miouf 🐾"
	RESET << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << RED
		"WrongCat Destructor is called"
	RESET << std::endl;
}
