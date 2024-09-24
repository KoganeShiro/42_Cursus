/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:28:39 by cejin             #+#    #+#             */
/*   Updated: 2024/09/23 16:32:30 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

int main(void)
{
	std::string	cmd;
	PhoneBook	phoneBook;

	std::cout << "Welcome to your Phone Book ☎️!"<< std::endl;
	while (1)
	{
		std::cout << "To navigate, type (ADD, SEARCH or EXIT): ";
		std::cin >> cmd;
		if (cmd == "ADD") {
			phoneBook.add_contact();
		}
		else if (cmd == "SEARCH") {
			phoneBook.search_contact();
		}
		else if (cmd == "EXIT") {
			phoneBook.exit_phone();
			break ;
		}
		else {
			std::cout << "PLS 🥲, type only ADD, SEARCH or EXIT" << std::endl << std::endl;
		}
	}
}