/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:54:16 by cejin             #+#    #+#             */
/*   Updated: 2024/12/06 18:57:23 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Form"), isSign(false), signGrade(42), executeGrade(5)
{
    std::cout << GREEN
		"Form DEFAULT constructor is called"
	RESET << std::endl;
}

Form::Form(std::string const &name, int signGrade, int executeGrade)
    : name(name), isSign(false), signGrade(signGrade), executeGrade(executeGrade)
{
    std::cout << GREEN
		"Form constructor is called"
	RESET << std::endl;
    if (signGrade < GRADE_MAX) {
		throw (GradeTooHighException());
    }
	else if (signGrade > GRADE_MIN) {
		throw (GradeTooLowException());
    }

	if (executeGrade < GRADE_MAX) {
		throw (GradeTooHighException());
    }
	else if (executeGrade > GRADE_MIN) {
		throw (GradeTooLowException());
    }
}

Form::Form(Form const &src) :
    name(src.name), signGrade(src.signGrade), executeGrade(src.executeGrade)
{
    std::cout << GREEN
		"Form COPY constructor is called"
	RESET << std::endl;
}

Form &Form::operator=(Form const &src)
{
    std::cout << GREEN
		"Form COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
	if (this != &src) {
		this->isSign = src.isSign;
	}
	return (*this);
}

std::string const &Form::getName() const
{
    return (this->name);
}

bool		Form::getIsSign() const
{
    return (this->isSign);
}

int			Form::getSignGrade() const
{
    return (this->signGrade);
}

int			Form::getExecuteGrade() const
{
    return (this->executeGrade);
}

void		Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > this->signGrade) {
        throw (GradeTooLowException());
    }
    this->isSign = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade too HIGH! 😡");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade too LOW! 😡");
}

Form::~Form()
{
    std::cout << RED
		"Form Destructor is called"
	RESET << std::endl;
}

std::ostream &operator<<(std::ostream &out, Form const &other)
{
	out << CYAN << other.getName() << ", grade to sign : "
    << other.getSignGrade() << ", grade to execute : "
    << other.getExecuteGrade() << ". Form ";
	if (other.getIsSign()) {
		out << "is signed.";
    }
	else {
	 	out << "isn't signed.";
    }
    out << RESET;
	return out;
}