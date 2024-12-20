/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:14:58 by cejin             #+#    #+#             */
/*   Updated: 2024/12/16 17:32:32 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>

#define MAX 5

int main()
{
	std::vector<int>	vect(MAX);
	std::deque<int>		deq(MAX);
	std::list<int>		list;

	for (unsigned int i = 0; i < MAX; i++)
	{
		vect.push_back(i);
		deq.push_back(i);
		list.push_back(i);
	}
    
    for (unsigned int i = 0; i < MAX; i++) {
        std::cout << "vec: " << *easyfind(vect, i) << std::endl;
    }
    for (unsigned int i = 0; i < MAX; i++) {
        std::cout << "deq: " << *easyfind(deq, i) << std::endl;
    }
    for (unsigned int i = 0; i < MAX; i++) {
        std::cout << "list: " << *easyfind(list, i) << std::endl;
    }

	try {
        std::cout << *easyfind(vect, 5) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
    try {
        std::cout << *easyfind(deq, 5) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
    try {
        std::cout << *easyfind(list, 5) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
