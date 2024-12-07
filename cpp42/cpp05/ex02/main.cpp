/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:52:29 by cejin             #+#    #+#             */
/*   Updated: 2024/12/06 17:39:57 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 150);
        Bureaucrat alice("Alice", 50);
        Bureaucrat charlie("Charlie", 1);

        ShrubberyCreationForm shrubbery("Home");
        ShrubberyCreationForm shrubbery1("test");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << "=================================" << std::endl;
        std::cout << "Testing ShrubberyCreationForm:" << std::endl;
        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);
        alice.executeForm(shrubbery);
        alice.signForm(shrubbery);
        charlie.signForm(shrubbery1);
        charlie.executeForm(shrubbery);
        alice.executeForm(shrubbery1);
        std::cout << "=================================" << std::endl;

        std::cout << "=================================" << std::endl;
        std::cout << "Testing RobotomyRequestForm:" << std::endl;
        bob.signForm(robotomy);
        bob.executeForm(robotomy);
        alice.executeForm(robotomy);
        alice.signForm(robotomy);
        charlie.signForm(robotomy);
        charlie.executeForm(robotomy);
        std::cout << "=================================" << std::endl;

        std::cout << "=================================" << std::endl;
        std::cout << "Testing PresidentialPardonForm:" << std::endl;
        alice.signForm(pardon);
        alice.executeForm(pardon);
        charlie.signForm(pardon);
        charlie.executeForm(pardon);
        std::cout << "=================================" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}