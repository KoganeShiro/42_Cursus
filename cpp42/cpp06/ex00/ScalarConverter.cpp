/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:05:53 by cejin             #+#    #+#             */
/*   Updated: 2024/12/10 11:41:43 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << GREEN
		"ScalarConverter DEFAULT constructor is called"
	RESET << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
    (void)src;
    std::cout << GREEN
		"ScalarConverter COPY constructor is called"
	RESET << std::endl;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
    (void)src;
    std::cout << GREEN
		"ScalarConverter COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
    return (*this);
}

static void convertToChar(double value, std::stringstream &output, char *end, const std::string &input)
{
    long lValue = static_cast<long>(value);
    if (end == input.c_str() || lValue < CHAR_MIN || lValue > CHAR_MAX) {
        output << IMPOSSIBLE;
        return;
    }
    if (lValue < 0 || lValue > 127 || !isprint(lValue)) {
        output << NON_DISPLAYABLE;
    }
    else {
        output << '\'' << static_cast<char>(lValue) << '\'';
    }
}

static void convertToInt(double value, std::stringstream &output, char *end, const std::string &input)
{
    long lValue = static_cast<long>(value);
    if (end == input.c_str() || lValue < INT_MIN || lValue > INT_MAX) {
        output << IMPOSSIBLE;
    }
    else {
        output << static_cast<int>(value);
    }
}

static void convertToFloat(double value, std::stringstream &output, char *end, const std::string &input)
{
    if (end == input.c_str() || errno == ERANGE || ((value < -FLT_MAX || value > FLT_MAX) && !isinf(value))) {
        output << IMPOSSIBLE;
    }
    else if (static_cast<float>(value) == ceilf(static_cast<float>(value)) && !isinf(value)) {
        output << std::fixed << std::setprecision(0) << static_cast<float>(value) << ".0f";
    }
    else {
        output << static_cast<float>(value) << "f";
    }
}

static void convertToDouble(double value, std::stringstream &output, char *end, const std::string &input)
{
    if (end == input.c_str() || errno == ERANGE) {
        output << IMPOSSIBLE;
    }
    else if (value == ceil(value) && !isinf(value)) {
        output << std::fixed << std::setprecision(0) << value << ".0";
    }
    else {
        output << value;
    }
}

static void isNumber(const std::string &input)
{
    bool    flag = false;

    if (input == "nan" || input == "nanf" || input == "inf"
            || input == "inff" || input == "-inf" || input == "+inf"
            || input == "-inff" || input == "+inff") {
                return ;
    }
    std::string::const_iterator it = input.begin();
    while (it != input.end()) {
        if (std::isdigit(*it) != true && *it != '.' && *it != 'f'
                && *it != '-' && *it != '+') {
            if (flag == false) {
                flag = true;
            }
            else {
                std::cout << ORANGE "Input not a number !" RESET << std::endl;
                return ;
            }
        }
        it++;
    }
}

void ScalarConverter::convert(const std::string &input)
{
    std::stringstream convertInput[4];
    char *end;
    double value = strtod(input.c_str(), &end);
    
    std::cout << "input value: [" << input << "]" << std::endl;
    if (input.length() == 1 && isprint(input[0]) && !std::isdigit(input[0])) {
        value = static_cast<double>(input[0]);
        std::cout << "char: '" << input << "'" << std::endl;
        std::cout << "int: " <<value << std::endl;
        std::cout << "float: " << value << ".0f" << std::endl;
        std::cout << "double: " << value << ".0" << std::endl;
        return ;
    }
    isNumber(input);
    convertToChar(value, convertInput[CHAR], end, input);
    convertToInt(value, convertInput[INT], end, input);
    convertToFloat(value, convertInput[FLOAT], end, input);
    convertToDouble(value, convertInput[DOUBLE], end, input);

    std::cout << "char: " << convertInput[CHAR].str() << std::endl;
    std::cout << "int: " << convertInput[INT].str() << std::endl;
    std::cout << "float: " << convertInput[FLOAT].str() << std::endl;
    std::cout << "double: " << convertInput[DOUBLE].str() << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << RED
		"ScalarConverter Destructor is called"
	RESET << std::endl;
}
