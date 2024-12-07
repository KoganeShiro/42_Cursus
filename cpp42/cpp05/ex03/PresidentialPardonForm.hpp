/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:47:16 by cejin             #+#    #+#             */
/*   Updated: 2024/12/06 17:20:59 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

/*
equired grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox.
*/

class PresidentialPardonForm : public AForm
{
	private :
		std::string	target;

	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &src);
		virtual ~PresidentialPardonForm();

		virtual void		execute(Bureaucrat const &executor) const;
		std::string const	&getTarget() const;
		
};