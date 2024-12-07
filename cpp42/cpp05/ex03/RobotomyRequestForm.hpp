/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:10:49 by cejin             #+#    #+#             */
/*   Updated: 2024/12/06 17:20:52 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

/*
Required grades: sign 72, exec 45
Makes some drilling noises.
Then, informs that <target> has been robotomized successfully 50% of the time.
Otherwise, informs that the robotomy failed.
*/

class RobotomyRequestForm : public AForm
{
	private :
		std::string	target;

	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &src);
		virtual ~RobotomyRequestForm();

		virtual void		execute(Bureaucrat const &executor) const;
		std::string const	&getTarget() const;
		
};