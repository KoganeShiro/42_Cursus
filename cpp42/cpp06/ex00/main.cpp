/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:46:32 by cejin             #+#    #+#             */
/*   Updated: 2024/12/10 13:23:52 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main()
{
    ScalarConverter::convert("");
    std::cout << "----------------------" << std::endl;
    ScalarConverter::convert("1");
    std::cout << "----------------------" << std::endl;
    ScalarConverter::convert("5.4f");
    std::cout << "----------------------" << std::endl;
    ScalarConverter::convert("6.3");
    std::cout << "----------------------" << std::endl;
    ScalarConverter::convert("inf");
    std::cout << "----------------------" << std::endl;
    ScalarConverter::convert("nanf");
    std::cout << "----------------------" << std::endl;
    ScalarConverter::convert("n");
    std::cout << "----------------------" << std::endl;
    ScalarConverter::convert("2147483648");
    std::cout << "----------------------" << std::endl;
    ScalarConverter::convert("-2147483648");
    std::cout << "----------------------" << std::endl;
    ScalarConverter::convert("hello");
}