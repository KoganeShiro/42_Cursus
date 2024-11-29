/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:27:21 by cejin             #+#    #+#             */
/*   Updated: 2024/11/29 09:36:09 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain)
{
	std::cout << GREEN
		"Dog DEFAULT constructor is called"
	RESET << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src.type), brain(new Brain(*src.brain))
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
		this->brain = new Brain(*src.brain);
	}
	return (*this);
}

Dog::Dog(std::string const &type) : Animal(type), brain(new Brain)
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

void	Dog::setIdeasInBrain(std::string const &idea)
{
	if (this->brain) {
		brain->setNewIdea(idea);
	}
}

void	Dog::displayBrainIdeas(int i) const
{
	if (this->brain) {
		std::cout << "For: " << i
		<< " " ORANGE << this->brain->getIdea(i) << RESET
		<< std::endl;
	}
}

Dog::~Dog()
{
	std::cout << RED
		"Dog Destructor is called"
	RESET << std::endl;
	delete this->brain;
}
