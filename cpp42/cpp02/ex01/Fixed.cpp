/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:56:28 by cejin             #+#    #+#             */
/*   Updated: 2024/11/20 17:51:43 by cejin            ###   ########.fr       */
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

/*
	//We shift the integer value left by 8 bits (fractionalBits)
	//Example with value = 5:
	//Before: 0000 0000 0000 0101
	//After:  0000 0101 0000 0000
	//Why? Because we want to reserve the last 8 bits for decimal values
	//This way the number is effectively multiplied by 2^8 (256)
*/
Fixed::Fixed(const int value)
{
	std::cout << GREEN
		"Fixed INT constructor is called"
	RESET << std::endl;
	this->rawBits = value << Fixed::fractionalBits;
}

/*
	//Since a float already has integer and decimal parts
	//We multiply by 2^8 (256) to move the decimal point 8 positions right
	//Example with value = 5.5:
	//5.5 * 256 = 1408 (binary: 0000 0101 1000 0000)
	//The last 8 bits (1000 0000) represent the decimal 0.5 * 256 = 128
	//This gives us the same format as the integer version
*/
Fixed::Fixed(const float value)
{
	std::cout << GREEN
		"Fixed FLOAT constructor is called"
	RESET << std::endl;
	this->rawBits = roundf(value * (1 << Fixed::fractionalBits));
}

int Fixed::getRawBits(void) const
{
	// std::cout <<
	// 	"getRawBits member function called"
	// << std::endl;
	return (this->rawBits);
}

void Fixed::setRawBits(int const raw)
{
	std::cout <<
		"setRawBits member function called"
	<< std::endl;
	this->rawBits = raw;
}

//Fixed point to float requires division
//do the inverse of the float constructor
float	Fixed::toFloat(void) const
{
	return (float(this->rawBits)
		/ float(1 << Fixed::fractionalBits));
}

//Fixed point to int requires removing fractional bits
//do the inverse of the int constructor
int		Fixed::toInt(void) const
{
	return (this->rawBits >> Fixed::fractionalBits);
}

Fixed::~Fixed()
{
	std::cout << RED
		"Fixed Destructor is called"
	RESET << std::endl;
}

std::ostream&	operator<<(std::ostream& out, const Fixed& src)
{
	out << src.toFloat();
	return (out);
}
