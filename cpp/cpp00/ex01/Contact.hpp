/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:14:58 by cejin             #+#    #+#             */
/*   Updated: 2024/09/23 16:34:39 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

public:
	Contact();
	~Contact();

//encapsulation
	void	setFirstName(const std::string &firstName);
	void	setLastName(const std::string &lastName);
	void	setNickname(const std::string &nickname);
	void	setPhoneNumber(const std::string &phoneNumber);
	void	setDarkestSecret(const std::string &darkestSecret);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

	void	print_contact(int index) const;
};

#endif