/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:56:28 by cejin             #+#    #+#             */
/*   Updated: 2024/11/22 17:28:52 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : rawBits(0)
{
	std::cout << GREEN
		"Fixed DEFAULT constructor is called"
	RESET << std::endl;
}

//copy the src directly
	//(create and init a new instance)
Fixed::Fixed(const Fixed &src)
{
	std::cout << GREEN
		"Fixed COPY constructor is called"
	RESET << std::endl;
	*this = src;
	//this->rawBits = src.getRawBits();
}

//check if we ever self assign
//copy the value of members of the src
	//(create a new instance, take another instance
		//Takes its content to CHANGE the content of the new instance)
Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cout << GREEN
		"Fixed COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
	if (this != &src) {
		this->rawBits = src.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout <<
		"getRawBits member function called"
	<< std::endl;
	return (this->rawBits);
}

void Fixed::setRawBits(int const raw)
{
	std::cout <<
		"setRawBits member function called"
	<< std::endl;
	this->rawBits = raw;
}

Fixed::~Fixed()
{
	std::cout << RED
		"Fixed Destructor is called"
	RESET << std::endl;
}
