/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:37:13 by cejin             #+#    #+#             */
/*   Updated: 2024/12/06 18:58:07 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "Bureaucrat.hpp"

# define RED "\033[1;31m"
# define ORANGE "\033[38;2;255;145;5;3m"
# define BGREEN "\033[0m\033[38;2;0;170;0;1m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

class Bureaucrat;

class AForm
{
private:
    std::string const name;
    bool isSign;
    int const signGrade;
    int const executeGrade;

public:
    AForm();
    AForm(std::string const &name, int signGrade, int executeGrade);
    AForm &operator=(AForm const &src);
    AForm(AForm const &src);
    virtual ~AForm();

    std::string const	&getName() const;
    bool				getIsSign() const;
    int					getSignGrade() const;
    int					getExecuteGrade() const;
    void				beSigned(Bureaucrat const &bureaucrats);

    virtual void		execute(Bureaucrat const &executor) const = 0;

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

    class FormNotSignedException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, AForm const &src);
