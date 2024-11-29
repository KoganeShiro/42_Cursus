/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:34:48 by cejin             #+#    #+#             */
/*   Updated: 2024/11/28 18:08:56 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

std::string const	&Cure::getType() const
{
	return (this->type);
}

Cure::Cure() : AMateria("cure")
{
	std::cout << GREEN
		"Cure DEFAULT constructor is called"
	RESET << std::endl;
}

Cure::Cure(const Cure &src) : AMateria(src.type)
{
    std::cout << GREEN
		"Cure COPY constructor is called"
	RESET << std::endl;
}

Cure	&Cure::operator=(const Cure &src)
{
	std::cout << GREEN
		"Cure COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
	if (this != &src) {
		*this = src;
	}
	return (*this);
}

Cure    *Cure::clone() const
{
    Cure *clone;
    
    clone = new Cure(*this);
    return (clone);
}

void    Cure::use(ICharacter &target)
{
    std::cout << BGREEN
        "* heals " << target.getName() <<"’s wounds *"
    RESET << std::endl;
}

Cure::~Cure()
{
	std::cout << RED
		"Cure Destructor is called"
	RESET << std::endl;
}
