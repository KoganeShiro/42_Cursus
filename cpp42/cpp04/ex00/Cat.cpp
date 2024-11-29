/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:30:17 by cejin             #+#    #+#             */
/*   Updated: 2024/11/26 17:40:54 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << GREEN
		"Cat DEFAULT constructor is called"
	RESET << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src.type)
{
    std::cout << GREEN
		"Cat COPY constructor is called"
	RESET << std::endl;
}

Cat	&Cat::operator=(const Cat &src)
{
	std::cout << GREEN
		"Cat COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
	if (this != &src) {
		setType(src.type);
	}
	return (*this);
}

Cat::Cat(std::string const &type) : Animal(type)
{
    std::cout << GREEN
		"Cat constructor is called"
	RESET << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << CYAN
		"Meow Meow 🐈"
	RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << RED
		"Cat Destructor is called"
	RESET << std::endl;
}
