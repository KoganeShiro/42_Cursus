/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:30:17 by cejin             #+#    #+#             */
/*   Updated: 2024/11/29 09:48:03 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Aanimal("Cat"), brain(new Brain)
{
	std::cout << GREEN
		"Cat DEFAULT constructor is called"
	RESET << std::endl;
}

Cat::Cat(const Cat &src) : Aanimal(src.type), brain(new Brain(*src.brain))
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
		this->brain = new Brain(*src.brain);
	}
	return (*this);
}

Cat::Cat(std::string const &type) : Aanimal(type), brain(new Brain)
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

void	Cat::setIdeasInBrain(std::string const &idea)
{
	if (this->brain) {
		brain->setNewIdea(idea);
	}
}

void	Cat::displayBrainIdeas(int i) const
{
	if (this->brain) {
		std::cout << "For: " << i
		<< " " ORANGE << this->brain->getIdea(i) << RESET
		<< std::endl;
	}
}

Cat::~Cat()
{
	std::cout << RED
		"Cat Destructor is called"
	RESET << std::endl;
	delete this->brain;
}
