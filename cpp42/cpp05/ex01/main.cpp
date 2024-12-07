/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:52:29 by cejin             #+#    #+#             */
/*   Updated: 2024/12/06 19:00:59 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 150);

        Form form1("Form1", 50, 25);
        Form form2("Form2", 75, 100);

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        bob.signForm(form1);
        alice.signForm(form1);
        alice.signForm(form2);
        bob.signForm(form2);

        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;


    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}