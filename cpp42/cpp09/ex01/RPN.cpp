/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:32:08 by cejin             #+#    #+#             */
/*   Updated: 2024/12/26 14:36:26 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
    std::cout << GREEN
		"RPN DEFAULT constructor is called"
	RESET << std::endl;
}

RPN::RPN(RPN const &src): stack(src.stack)
{
    std::cout << GREEN
		"RPN COPY constructor is called"
	RESET << std::endl;
}

RPN	&RPN::operator=(RPN const &src)
{
    std::cout << GREEN
		"RPN COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
    if (this != &src) {
	    this->stack = src.stack;
    }
	return (*this);
}

void printStack(std::stack<int> s) {
    std::stack<int> tempStack = s;

    std::cout << "Stack contents (from top to bottom):" << std::endl;
    while (!tempStack.empty()) {
        std::cout << tempStack.top() << std::endl;
        tempStack.pop();
    }
}

void RPN::compute(std::string const &expression)
{
    std::cout <<
        "EXPRESSION: " << CYAN << expression << RESET
    << std::endl;
    try {
        std::istringstream stream(expression);
        std::string token;
        while (stream >> token) {
            if (isdigit(token[0])) {
                int num = atoi(token.c_str());
                if (num > 9) {
                    throw Error(YELLOW "Can't handle this number!" RESET);
                }
                stack.push(num);
            } else if (token == "+") {
                add();
            } else if (token == "-") {
                subtract();
            } else if (token == "*") {
                multiply();
            } else if (token == "/") {
                divide();
            } else {
                throw Error(YELLOW "Invalid token: " + token + RESET);
            }
        }
        if (!stack.empty()) {
            std::cout << "Result: " << BGREEN << stack.top() << RESET << std::endl;
        }
        else {
            throw Error(YELLOW "Error: No result in stack." RESET);
        }
    } catch (const RPN::Error &e) {
        std::cerr << e.what() << std::endl;
    }
    while (!stack.empty()) {
        stack.pop();
    }
}


void RPN::add()
{
    if (stack.size() < 2) {
        throw (Error(YELLOW "Error: Not enough operands for addition." RESET));
    }
    int a = stack.top(); stack.pop();
    int b = stack.top(); stack.pop();
    // std::cout << "-----ADD--------" << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << "___________________________________" << std::endl;
    stack.push(a + b);
}

void RPN::subtract()
{
    if (stack.size() < 2) {
        throw (Error(YELLOW "Error: Not enough operands for subtraction." RESET));
    }
    int a = stack.top(); stack.pop();
    int b = stack.top(); stack.pop();
    // std::cout << "-----SUB--------" << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << "___________________________________" << std::endl;
    stack.push(b - a);
}

void RPN::multiply()
{
    if (stack.size() < 2) {
        throw (Error(YELLOW "Error: Not enough operands for multiplication." RESET));
    }
    int a = stack.top(); stack.pop();
    int b = stack.top(); stack.pop();
    // std::cout << "-----MULT--------" << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << "___________________________________" << std::endl;
    stack.push(a * b);
}

void RPN::divide() {
    if (stack.size() < 2) {
        throw (Error(YELLOW "Error: Not enough operands for division." RESET));
    }
    int a = stack.top(); stack.pop();
    int b = stack.top(); stack.pop();
    if (a == 0) {
        throw (Error(YELLOW "Error: Division by zero." RESET));
    }
    // std::cout << "-----DIV--------" << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << "___________________________________" << std::endl;
    stack.push(b / a);
}

RPN::Error::Error(std::string const &msg) : msg("Error: " + msg)
{}

RPN::Error::~Error() throw()
{}

const char *RPN::Error::what() const throw()
{
	return (this->msg.c_str());
}

RPN::~RPN()
{
	std::cout << RED
		"RPN Destructor is called"
	RESET << std::endl;
}
