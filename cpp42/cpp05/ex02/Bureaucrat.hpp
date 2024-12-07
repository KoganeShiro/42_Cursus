/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:31:31 by cejin             #+#    #+#             */
/*   Updated: 2024/12/06 12:44:30 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

# define RED "\033[1;31m"
# define ORANGE "\033[38;2;255;145;5;3m"
# define BGREEN "\033[0m\033[38;2;0;170;0;1m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

#define GRADE_MAX 1
#define GRADE_MIN 150

#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
    std::string name;
    int         grade; // 1 to 150 (lowest)

public:
    Bureaucrat();
    Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &src);
    Bureaucrat &operator=(Bureaucrat const &src);
    ~Bureaucrat();

    std::string const &getName() const;
    int const &getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(AForm &form);

    void executeForm(AForm const &form);

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

std::ostream	&operator<<(std::ostream& out, const Bureaucrat &src);
