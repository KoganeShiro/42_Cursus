/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:31:20 by cejin             #+#    #+#             */
/*   Updated: 2024/12/06 18:59:51 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Anonymous Bureaucrat"), grade(150)
{
	std::cout << GREEN
		"Bureaucrat DEFAULT constructor is called"
	RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name)
{
	std::cout << GREEN
		"Bureaucrat constructor is called"
	RESET << std::endl;
	if (grade < GRADE_MAX) {
		throw(GradeTooHighException());
	}
	else if (grade > GRADE_MIN) {
		throw(GradeTooLowException());
	}
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : name(src.name), grade(src.grade)
{
	std::cout << GREEN
		"Bureaucrat COPY constructor is called"
	RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
	std::cout << GREEN
		"Bureaucrat COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
	if (this != &src) {
		*this = src;
	}
	return (*this);
}

std::string const &Bureaucrat::getName() const
{
	return (this->name);
}

int const &Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->grade <= GRADE_MAX) {
		throw(GradeTooHighException());
	}
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade >= GRADE_MIN) {
		throw(GradeTooLowException());
	}
	this->grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return (YELLOW "Grade too HIGH! 😡" RESET);
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return (YELLOW "Grade too LOW! 😡" RESET);
}

void Bureaucrat::signForm(AForm &form)
{
	if (form.getIsSign()) {
		std::cout << YELLOW << this->getName() << "  couldn’t sign "
		<< form.getName() << " because it is already signed !" RESET << std::endl;
	}
	try {
		form.beSigned(*this);
		std::cout << BGREEN << this->getName() << " signed "
			<< form.getName() << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << this->getName()
			<< " couldn’t sign " << form.getName()
		<< " because: " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try {
		std::cout << BGREEN << this->getName() << " executed "
			<< form.getName() << RESET << std::endl;
		form.execute(*this);
	}
	catch (std::exception &e) {
		std::cout << this->getName()
			<< " couldn’t execute " << form.getName()
		<< " because: " << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED
		"Bureaucrat Destructor is called"
	RESET << std::endl;
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat &src)
{
	out << CYAN;
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	out << RESET;
	return (out);
}