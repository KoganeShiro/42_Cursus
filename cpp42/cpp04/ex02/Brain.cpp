/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:56:51 by cejin             #+#    #+#             */
/*   Updated: 2024/11/29 09:45:58 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << GREEN
		"Brain DEFAULT constructor is called"
	RESET << std::endl;
	this->ideasCount = 0;
}

Brain::Brain(const Brain &src)
{
	std::cout << GREEN
		"Brain COPY constructor is called"
	RESET << std::endl;
	for (int i = 0; i < src.getIdeaCount(); i++) {
		ideas[i] = src.getIdea(i);
	}
	this->ideasCount = src.getIdeaCount();
}

Brain	&Brain::operator=(const Brain &src)
{
	std::cout << GREEN
		"Brain COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
	if (this != &src) {
		for (int i = 0; i < src.getIdeaCount(); i++) {
			this->ideas[i] = src.getIdea(i);
		}
		this->ideasCount = src.ideasCount;
	}
	return (*this);
}

void Brain::setNewIdea(std::string const &idea)
{
	if (ideasCount < NB_IDEAS) {
		this->ideas[ideasCount] = idea;
		ideasCount++;
	}
	else {
		std::cout << YELLOW
			"The instance has already 100 ideas\n"
			"Starting to overwrite the first one..."
		RESET << std::endl;
		this->ideasCount = 0;
		this->ideas[this->ideasCount] = idea;
		ideasCount++;
	}
}

std::string const Brain::getIdea(int i) const
{
	if (i >= this->ideasCount) {
		std::cout << YELLOW
			"This area of the brain is empty, check an index lower than "
		<< i << RESET << std::endl;
		return ("Try again\n");
	}
	return (this->ideas[i]);
}

int Brain::getIdeaCount() const
{
	return (this->ideasCount);
}

Brain::~Brain()
{
	std::cout << RED
		"Brain Destructor is called"
	RESET << std::endl;
}
