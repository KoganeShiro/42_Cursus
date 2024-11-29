/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:55:41 by cejin             #+#    #+#             */
/*   Updated: 2024/11/26 17:30:23 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

void	Animal::setType(std::string const &type)
{
	this->type = type;
}

std::string const	Animal::getType() const
{
	return (this->type);
}

Animal::Animal() : type("Unknown Animal")
{
	std::cout << GREEN
		"Animal DEFAULT constructor is called"
	RESET << std::endl;
}

Animal::Animal(const Animal &src) : type(src.type)
{
    std::cout << GREEN
		"Animal COPY constructor is called"
	RESET << std::endl;
}

Animal	&Animal::operator=(const Animal &src)
{
	std::cout << GREEN
		"Animal COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
	if (this != &src) {
		setType(src.type);
	}
	return (*this);
}

Animal::Animal(std::string const &type) : type(type)
{
    std::cout << GREEN
		"Animal constructor is called"
	RESET << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << CYAN
		"Uncomprehensible sound"
	RESET << std::endl;
}

Animal::~Animal()
{
	std::cout << RED
		"Animal Destructor is called"
	RESET << std::endl;
}
