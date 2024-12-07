/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:16:30 by cejin             #+#    #+#             */
/*   Updated: 2024/12/06 18:28:06 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#define gradeSign 72
#define gradeExec 45

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", gradeSign, gradeExec) , target(NULL)
{
	std::cout << GREEN
		"RobotomyRequestForm DEFAULT constructor is called"
	RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : AForm("RobotomyRequestForm", gradeSign, gradeExec), target(target)
{
	std::cout << GREEN
		"RobotomyRequestForm constructor is called"
	RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
    : AForm(src.getName(), src.getSignGrade(), src.getExecuteGrade()), target(src.getTarget())
{
	std::cout << GREEN
		"RobotomyRequestForm COPY constructor is called"
	RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
    std::cout << GREEN
		"RobotomyRequestForm COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
    if (this != &src) {
        this->AForm::operator=(src);
        this->target = src.getTarget();
    }
	return (*this);	
}


std::string const	&RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
		throw (GradeTooLowException());
	if (this->getIsSign() == false)
		throw (FormNotSignedException());

    if (rand() % 2) {
        std::cout << CYAN "*BRrrRRr* " << this->target
        <<  " has been robotomized successfully ! 😄" RESET
        << std::endl;
    }
    else {
        std::cout << CYAN "*CRrrRRr BOOM* " << this->target
        <<  " robotomize has failed ! 😔" RESET
        << std::endl;
    }
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED
		"RobotomyRequestForm Destructor is called"
	RESET << std::endl;
}
