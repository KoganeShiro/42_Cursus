/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:18:21 by cejin             #+#    #+#             */
/*   Updated: 2024/12/06 18:27:11 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#define gradeSign 25
#define gradeExec 5

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", gradeSign, gradeExec) , target(NULL)
{
	std::cout << GREEN
		"PresidentialPardonForm DEFAULT constructor is called"
	RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
    : AForm("PresidentialPardonForm", gradeSign, gradeExec), target(target)
{
	std::cout << GREEN
		"PresidentialPardonForm constructor is called"
	RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
    : AForm(src.getName(), src.getSignGrade(), src.getExecuteGrade()), target(src.getTarget())
{
	std::cout << GREEN
		"PresidentialPardonForm COPY constructor is called"
	RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
    std::cout << GREEN
		"PresidentialPardonForm COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
    if (this != &src) {
        this->AForm::operator=(src);
        this->target = src.getTarget();
    }
	return (*this);	
}


std::string const	&PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
		throw (GradeTooLowException());
	if (this->getIsSign() == false)
		throw (FormNotSignedException());

    std::cout << CYAN <<
        this->target << " has been pardoned by Zaphod Beeblebrox"
    RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED
		"PresidentialPardonForm Destructor is called"
	RESET << std::endl;
}
