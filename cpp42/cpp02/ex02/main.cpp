/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:52:49 by cejin             #+#    #+#             */
/*   Updated: 2024/11/23 10:38:58 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include "Fixed.hpp"

void	_comparison_test()
{
	Fixed a;
	Fixed d(100.5f);
	Fixed res = a < d;

	std::cout << "a: " << a << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "true: " << true << std::endl;
	std::cout << a << " < "<< d << ": " << res << std::endl;
	res = a >= d;
	std::cout << a << " >= "<< d << ": " << res << std::endl;
	res = a != d;
	std::cout << a << " != "<< d << ": " << res << std::endl;
	res = a == a;
	std::cout << a << " == "<< a << ": " << res << std::endl;
}

void	_arithmetic_test()
{
	Fixed resultAdd = Fixed(5) + Fixed(2);
	Fixed resultMinus = Fixed(5) - Fixed(2);
	Fixed resultMul = Fixed(5.05f) * Fixed(2); //10.1
	Fixed resultDivide = Fixed(9) / Fixed(3);

	std::cout << "5 + 2 = " << resultAdd << std::endl;
	std::cout << "5 - 2 = " << resultMinus << std::endl;
	std::cout << "5.05 * 2 = " << resultMul << std::endl;
	std::cout << "9 / 3 = " << resultDivide << std::endl;
}

void	_increment_test()
{
	Fixed a;

	std::cout << "Initial value of a: " << a << std::endl;
	std::cout << "Pre-increment a: " << ++a << std::endl;
	std::cout << "After pre-increment, a: " << a << std::endl;
	std::cout << "Post-increment a: " << a++ << std::endl;
	std::cout << "After post-increment, a: " << a << "\n" << std::endl;

	std::cout << "Initial value of a: " << a << std::endl;
	std::cout << "Pre-decrement a: " << --a << std::endl;
	std::cout << "After pre-decrement, a: " << a << std::endl;
	std::cout << "Post-decrement a: " << a-- << std::endl;
	std::cout << "After post-decrement, a: " << a << std::endl;
}

void	_min_max_test()
{
	Fixed a;
	Fixed b(5.05f * 2);
	Fixed c(5);
	Fixed d(100.5f);

	std::cout << "Max of " << a << " and " << b << " is " BLUE << Fixed::max(a, b) << RESET << std::endl;
	std::cout << "Max of " << a << " and " << d << " is " BLUE << Fixed::max(a, d) << RESET << std::endl;
	std::cout << "Min of " << b << " and " << c << " is " BLUE << Fixed::min(b, c) << RESET << std::endl;
	std::cout << "Min of " << a << " and " << d << " is " BLUE << Fixed::min(a, d) << RESET << std::endl;

	Fixed const e(200);
	Fixed const f(50);
	
	std::cout << "Max of const " << e << " and const " << f << " is " << Fixed::max(e, f) << std::endl;
	std::cout << "Min of const " << e << " and const " << f << " is " << Fixed::min(e, f) << std::endl;
}

// int main(void)
// {
// 	std::cout << "======COMPARISON=====" << std::endl;
// 	_comparison_test();
// 	std::cout << "\n" << std::endl;
// 	std::cout << "=====ARITHMETIC====" << std::endl;
// 	_arithmetic_test();
// 	std::cout << "\n" << std::endl;
// 	std::cout << "=====INCREMENT======" << std::endl;
// 	_increment_test();
// 	std::cout << "\n" << std::endl;
// 	std::cout << "=====MIN_MAX=====" << std::endl;
// 	_min_max_test();

// 	return 0;
// }

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}
