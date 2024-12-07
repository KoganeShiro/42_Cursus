/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:37:13 by cejin             #+#    #+#             */
/*   Updated: 2024/12/06 18:56:30 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    std::string const name;
    bool isSign;
    int const signGrade;
    int const executeGrade;

public:
    Form();
    Form(std::string const &name, int signGrade, int executeGrade);
    Form &operator=(Form const &src);
    Form(Form const &src);
    ~Form();

    std::string const	&getName() const;
    bool				getIsSign() const;
    int					getSignGrade() const;
    int					getExecuteGrade() const;
    void				beSigned(Bureaucrat const &bureaucrats);

    class GradeTooHighException : public std::exception
    {
        public :
            virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public :
            virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Form const &src);
