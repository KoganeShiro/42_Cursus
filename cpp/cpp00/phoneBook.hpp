/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:03:23 by cejin             #+#    #+#             */
/*   Updated: 2024/09/23 16:38:58 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class PhoneBook
{
private:
	Contact _contact[8];

public:
	PhoneBook();
	~PhoneBook();
	
	void	add_contact(void);
	//display saved contact in 4 columns:
	//index, first name, last name and nickname (10 char max)
	//a pipe separate the columns, if char > 10 last char is .
	//user input the index, show all info line by line
	void	search_contact(void);
	void	print_contact(void);
	void	exit_phone(void);
}

#endif