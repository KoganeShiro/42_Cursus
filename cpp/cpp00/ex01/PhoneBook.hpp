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
# define PHONEBOOK_HPP

# include <iostream>
# include <cctype>
# include <iomanip>
# include <cstdlib>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contacts[8];
	int		_contact_count;
	int		_overflow_flag;

public:
	PhoneBook();
	~PhoneBook();
	
	void	add_contact(void);
	void	search_contact(void) const;
	void	print_contact_list(void) const;
	void	exit_phone(void) const;
};

#endif
