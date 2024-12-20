/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:56:04 by cejin             #+#    #+#             */
/*   Updated: 2024/12/20 12:17:06 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#define SIZE 100000

void    otherTest(Span sp)
{
	sp = Span(SIZE);
	std::vector<int> vect;
	for (unsigned int i = 1; i <= SIZE; i++) {
		vect.push_back(i);
    }
	try {
		sp.addRange(vect.begin(), vect.end());
		std::cout << "add range of vec of size: " << SIZE << std::endl;
    	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	sp = Span(42);
	try {
		std::cout << "add range of vec of size: " << SIZE << std::endl;
		sp.addRange(vect.begin(), vect.end());
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	sp.addNumber(1);
	try {
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
    	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int main()
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
	std::cout << "Add number: 6\nAdd number: 3\nAdd number: 17" << std::endl;
	std::cout << "Add number: 9\nAdd number: 11" << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    try {
		std::cout << "\nAdd number: 4" << std::endl;
		sp.addNumber(4);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

    otherTest(sp);
    return (0);
}