/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:46:56 by cejin             #+#    #+#             */
/*   Updated: 2024/11/28 18:10:07 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

std::string const	&Ice::getType() const
{
	return (this->type);
}

Ice::Ice() : AMateria("ice")
{
	std::cout << GREEN
		"Ice DEFAULT constructor is called"
	RESET << std::endl;
}

Ice::Ice(const Ice &src) : AMateria(src.type)
{
    std::cout << GREEN
		"Ice COPY constructor is called"
	RESET << std::endl;
}

Ice	&Ice::operator=(const Ice &src)
{
	std::cout << GREEN
		"Ice COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
	if (this != &src) {
		*this = src;
	}
	return (*this);
}

Ice    *Ice::clone() const
{
    Ice *clone;
    
    clone = new Ice(*this);
    return (clone);
}

void    Ice::use(ICharacter &target)
{
    std::cout << BGREEN
        "* shoots an ice bolt at " << target.getName() << " *"
    RESET << std::endl;
}

Ice::~Ice()
{
	std::cout << RED
		"Ice Destructor is called"
	RESET << std::endl;
}
