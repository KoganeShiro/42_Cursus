/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:47:38 by cejin             #+#    #+#             */
/*   Updated: 2024/12/11 12:02:24 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
    std::cout << RED
		"Base Destructor is called"
	RESET << std::endl;
}

//Generate randomly A, B or C class
Base * generate(void)
{
	int random = rand() % 3;

	if (random == 0) {
		return (new A());
	}
	else if (random == 1) {
		return (new B());
	}
	return (new C());
}

//Identify the base by the pointer
void identify(Base* p)
{
	if (dynamic_cast<A*>(p)) {
		std::cout << CYAN "A" RESET << std::endl;
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << CYAN "B" RESET << std::endl;
	}
	else if (dynamic_cast<C*>(p)) {
		std::cout << CYAN "C" RESET << std::endl;
	}
	else {
		std::cout <<
			YELLOW "Unable to identify the base..." RESET
		<< std::endl;
	}
}

//Identify the base by the reference
void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << GREEN "A" RESET << std::endl;
	}
	catch (std::exception &e) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << GREEN "B" RESET  << std::endl;
		}
		catch (std::exception &e) {
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << GREEN "C" RESET << std::endl;
			}
			catch (std::exception &e) {
				std::cout <<
					YELLOW "Unable to identify the base..." RESET
				<<std::endl;
			}
			
		}
	}
}
