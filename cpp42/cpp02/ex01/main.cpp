/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:52:49 by cejin             #+#    #+#             */
/*   Updated: 2024/11/20 17:48:16 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// int	main(void)
// {
// 	Fixed a;
// 	a = Fixed( 1234.4321f );
// 	std::cout << "a is " << a << std::endl;
// 	std::cout << "a is " << a.toInt() << " as integer" << std::endl;

// 	Fixed const b( 10 );
// 	std::cout << "b is " << b << std::endl;
// 	std::cout << "b is " << b.toFloat() << " as float" << std::endl;

// 	Fixed const c( 42.42f );
// 	std::cout << "c is " << c << std::endl;
// 	std::cout << "c is " << c.toInt() << " as integer" << std::endl;

// 	Fixed const d( b );
// 	std::cout << "d is " << d << std::endl;
// 	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	
// 	return 0;
// }

int main( void ) {
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );

a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}
