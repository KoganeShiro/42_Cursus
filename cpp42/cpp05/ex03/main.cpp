/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:52:29 by cejin             #+#    #+#             */
/*   Updated: 2024/12/06 18:44:08 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 150);
        Bureaucrat alice("Alice", 50);
        Bureaucrat charlie("Charlie", 1);

        Intern  intern;

        AForm *shrubbery(intern.makeForm("shrubbery", "tree"));
        AForm *robotomy(intern.makeForm("robotomy", "robot"));
        AForm *pardon(intern.makeForm("pardon", "got pardon"));

        if (shrubbery == NULL || robotomy == NULL || pardon == NULL) {
            return (0);
        }

        std::cout << "=================================" << std::endl;
        std::cout << "Testing ShrubberyCreationForm:" << std::endl;
        bob.signForm(*shrubbery);
        bob.executeForm(*shrubbery);
        alice.executeForm(*shrubbery);
        alice.signForm(*shrubbery);
        charlie.executeForm(*shrubbery);
        std::cout << "=================================" << std::endl;

        std::cout << "=================================" << std::endl;
        std::cout << "Testing RobotomyRequestForm:" << std::endl;
        bob.signForm(*robotomy);
        bob.executeForm(*robotomy);
        alice.executeForm(*robotomy);
        alice.signForm(*robotomy);
        charlie.signForm(*robotomy);
        charlie.executeForm(*robotomy);
        std::cout << "=================================" << std::endl;

        std::cout << "=================================" << std::endl;
        std::cout << "Testing PresidentialPardonForm:" << std::endl;
        alice.signForm(*pardon);
        alice.executeForm(*pardon);
        charlie.signForm(*pardon);
        charlie.executeForm(*pardon);
        std::cout << "=================================" << std::endl;
        delete shrubbery;
        delete robotomy;
        delete pardon;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}