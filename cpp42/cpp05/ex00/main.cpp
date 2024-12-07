/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:52:29 by cejin             #+#    #+#             */
/*   Updated: 2024/12/06 18:52:40 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat bob("Bob", GRADE_MAX + 1);
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;
    }
     catch (std::exception& e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat john("John", GRADE_MIN - 1);
        std::cout << john << std::endl;

        john.decrementGrade();
        std::cout << john << std::endl;
        john.decrementGrade();
        std::cout << john << std::endl;
    }
     catch (std::exception& e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat no("No", 0);
    }
     catch (std::exception& e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat stillNo("StillNo", 151);
    }
     catch (std::exception& e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return (0);
}