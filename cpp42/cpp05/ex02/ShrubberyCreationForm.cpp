/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:10:21 by cejin             #+#    #+#             */
/*   Updated: 2024/12/06 18:27:44 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#define gradeSign 145
#define gradeExec 137

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm",  gradeSign, gradeExec) , target(NULL)
{
	std::cout << GREEN
		"ShrubberyCreationForm DEFAULT constructor is called"
	RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm("ShrubberyCreationForm", gradeSign, gradeExec), target(target)
{
	std::cout << GREEN
		"ShrubberyCreationForm constructor is called"
	RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
    : AForm(src.getName(), src.getSignGrade(), src.getExecuteGrade()), target(src.getTarget())
{
	std::cout << GREEN
		"ShrubberyCreationForm COPY constructor is called"
	RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
    std::cout << GREEN
		"ShrubberyCreationForm COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
    if (this != &src) {
        this->AForm::operator=(src);
        this->target = src.getTarget();
    }
	return (*this);	
}


std::string const	&ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string		filename(target + "_shrubbery");
	std::ofstream	outfile;

	if (executor.getGrade() > this->getExecuteGrade())
		throw (GradeTooLowException());
	if (this->getIsSign() == false)
		throw (FormNotSignedException());

	outfile.open(filename.c_str());

	if (!outfile.is_open()) {
		std::cerr <<
			"Shrubbery [" << this->getTarget() <<  "] file : " << target
			<< " could not be open..."
		<< std::endl;
	} else {
        const char* tree = ASCII_TREE;
		for (int i = 0; i < int(std::strlen(tree)); i++)
			outfile << tree[i];
		outfile.close();
        std::cout <<
			"ASCII_TREE written to " << filename << "!"
		<< std::endl;
	}	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED
		"ShrubberyCreationForm Destructor is called"
	RESET << std::endl;
}
