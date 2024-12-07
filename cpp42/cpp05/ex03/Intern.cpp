/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:25:52 by cejin             #+#    #+#             */
/*   Updated: 2024/12/06 18:45:08 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#define NB_OF_FORM 3

Intern::Intern()
{
	std::cout << GREEN
		"Intern DEFAULT constructor is called"
	RESET << std::endl;
}

Intern::Intern(Intern const &src)
{
	std::cout << GREEN
		"Intern COPY constructor is called"
	RESET << std::endl;
    (void)src;
}

Intern &Intern::operator=(Intern const &src)
{
    std::cout << GREEN
		"Intern COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
    (void)src;
	return (*this);	
}

static AForm *shrubberyForm(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *robotomyForm(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *presidentialForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) const
{
	AForm *(*allForm[])(std::string const &formTarget) = {&shrubberyForm, &robotomyForm, &presidentialForm};
	std::string forms[] = {"shrubbery", "robotomy", "pardon"};

	for (int i = 0; i < NB_OF_FORM; i++) {
		if (formName == forms[i]) {
			std::cout <<
                GREEN "Intern creates " << formName << RESET
            << std::endl;
			return (allForm[i](target));
		}
	}
	std::cout <<
    YELLOW "Intern could not create form named: " << formName << RESET
    << std::endl;
	return (NULL);
}

Intern::~Intern()
{
	std::cout << RED
		"Intern Destructor is called"
	RESET << std::endl;
}
