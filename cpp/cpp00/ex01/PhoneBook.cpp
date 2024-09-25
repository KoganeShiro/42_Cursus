/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:03:52 by cejin             #+#    #+#             */
/*   Updated: 2024/09/23 17:04:03 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_contact_count = 0;
	_overflow_flag = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::add_contact(void)
{
	std::string input;

	if (_contact_count == 8) {
		std::cout << "PhoneBook is full. Overwriting oldest contact." << std::endl;
		_contact_count = 0;
		_overflow_flag = 1;
	}
	while (1) {
		std::cout << "Enter First Name: ";
		if (std::getline(std::cin, input) && !input.empty()) {
			_contacts[_contact_count].setFirstName(input);
			break;
		}
		else
			continue;
	}
	while (1) {
		std::cout << "Enter Last Name: ";
		if (std::getline(std::cin, input) && !input.empty()) {
			_contacts[_contact_count].setLastName(input);
			break;
		}
		else
			continue;
	}
	while (1) {
		std::cout << "Enter Nickname: ";
		if (std::getline(std::cin, input) && !input.empty()) {
			_contacts[_contact_count].setNickname(input);
			break;
		}
		else
			continue;
	}
	while (1) {
		std::cout << "Enter Phone Number: ";
		if (std::getline(std::cin, input) && !input.empty()) {
			_contacts[_contact_count].setPhoneNumber(input);
			break;
		}
		else
			continue;
	}
	while (1) {
		std::cout << "Enter Darkest Secret: ";
		if (std::getline(std::cin, input) && !input.empty()) {
			_contacts[_contact_count].setDarkestSecret(input);
			break;
		}
		else
			continue;
	}

	_contact_count++;
	std::cout << "Contact added successfully!" << std::endl;
	std::cout << std::endl;
	return ;
}

void	PhoneBook::search_contact(void) const
{
	std::string	index;
	int			intdex;

	if (_contact_count == 0)
	{
		std::cout << "No contacts to display." << std::endl;
		return ;
	}
	print_contact_list();
	std::cout << "Type the index of the contact you want to view: ";
	std::getline(std::cin, index);
	intdex = atoi(index.c_str());
	if (index.length() == 1 && index[0] >= '0' && index[0] <= '7') {
		_contacts[intdex].print_contact(intdex);
	}
	else {
		std::cout << "Please enter a valid number 😠. Try again from start 🙃" << std::endl;
	}
	std::cout << std::endl;
}

void	PhoneBook::print_contact_list(void) const
{
	int	contact_count;

	std::cout << std::endl;
	std::cout << std::right << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;

	if (_overflow_flag == 1)
		contact_count = 8;
	else
		contact_count = _contact_count;
	for (int i = 0; i < contact_count; i++)
	{
		std::cout << std::right << std::setw(10) << i << "|"
				  << std::right << std::setw(10) << (_contacts[i].getFirstName().length() > 10 ? _contacts[i].getFirstName().substr(0, 9) + "." : _contacts[i].getFirstName()) << "|"
				  << std::right << std::setw(10) << (_contacts[i].getLastName().length() > 10 ? _contacts[i].getLastName().substr(0, 9) + "." : _contacts[i].getLastName()) << "|"
				  << std::right << std::setw(10) << (_contacts[i].getNickname().length() > 10 ? _contacts[i].getNickname().substr(0, 9) + "." : _contacts[i].getNickname()) << std::endl;
	}
	std::cout << std::endl;
	return ;
}

void	PhoneBook::exit_phone(void) const
{
	std::cout << "Proccessing to delete all the data..." << std::endl;
	std::cout << "Exiting PhoneBook...Goodbye !" << std::endl;
	return ;
}
