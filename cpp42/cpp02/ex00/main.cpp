/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:52:49 by cejin             #+#    #+#             */
/*   Updated: 2024/11/20 16:25:40 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// int	main( void )
// {
// 	Fixed a;
// 	a.setRawBits(0);
// 	std::cout << "a = " << a.getRawBits() << std::endl; // Default constructor

// 	Fixed b(a);
// 	std::cout << "b = " << b.getRawBits() << std::endl; // Copy constructor

// 	Fixed c;
// 	c = b;
// 	std::cout << "c = " << c.getRawBits() << std::endl; // Copy assignment operator
// 	return 0;
// }

int main( void ) {
Fixed a;
Fixed b( a );
Fixed c;
c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
return 0;
}