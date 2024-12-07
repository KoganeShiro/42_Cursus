/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:54:16 by cejin             #+#    #+#             */
/*   Updated: 2024/12/05 18:21:21 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("AForm"), isSign(false), signGrade(42), executeGrade(5)
{
    std::cout << GREEN
		"AForm DEFAULT constructor is called"
	RESET << std::endl;
}

AForm::AForm(std::string const &name, int signGrade, int executeGrade)
    : name(name), isSign(false), signGrade(signGrade), executeGrade(executeGrade)
{
    std::cout << GREEN
		"AForm constructor is called"
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

AForm::AForm(AForm const &src) : name(src.name),
                                signGrade(src.signGrade),
                                executeGrade(src.executeGrade)
{
    std::cout << GREEN
		"AForm COPY constructor is called"
	RESET << std::endl;
}

AForm &AForm::operator=(AForm const &src)
{
    std::cout << GREEN
		"AForm COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
	if (this != &src) {
		this->isSign = src.isSign;
	}
	return (*this);
}

std::string const &AForm::getName() const
{
    return (this->name);
}

bool		AForm::getIsSign() const
{
    return (this->isSign);
}

int			AForm::getSignGrade() const
{
    return (this->signGrade);
}

int			AForm::getExecuteGrade() const
{
    return (this->executeGrade);
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
    if (this->isSign) {
        return ;
    }
    if (bureaucrat.getGrade() > this->signGrade) {
        throw GradeTooLowException();
    }
    this->isSign = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too HIGH! 😡");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too LOW! 😡");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form's not signed!! 😱");
}

AForm::~AForm()
{
    std::cout << RED
		"AForm Destructor is called"
	RESET << std::endl;
}

std::ostream &operator<<(std::ostream &out, AForm const &other)
{
	out << CYAN << other.getName() << ", grade to sign : "
    << other.getSignGrade() << ", grade to execute : "
    << other.getExecuteGrade() << ". AForm ";
	if (other.getIsSign()) {
		out << "is signed.";
    }
	else {
	 	out << "isn't signed.";
    }
    out << RESET;
	return out;
}