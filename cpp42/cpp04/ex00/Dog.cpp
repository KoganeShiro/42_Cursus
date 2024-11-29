/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:27:21 by cejin             #+#    #+#             */
/*   Updated: 2024/11/26 17:41:01 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << GREEN
		"Dog DEFAULT constructor is called"
	RESET << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src.type)
{
    std::cout << GREEN
		"Dog COPY constructor is called"
	RESET << std::endl;
}

Dog	&Dog::operator=(const Dog &src)
{
	std::cout << GREEN
		"Dog COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
	if (this != &src) {
		setType(src.type);
	}
	return (*this);
}

Dog::Dog(std::string const &type) : Animal(type)
{
    std::cout << GREEN
		"Dog constructor is called"
	RESET << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << CYAN
		"Woof Woof 🦮"
	RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << RED
		"Dog Destructor is called"
	RESET << std::endl;
}
