/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:05:34 by cejin             #+#    #+#             */
/*   Updated: 2024/12/26 14:26:14 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stack>
#include <ctime>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cctype>

# define RED "\033[1;31m"
# define ORANGE "\033[38;2;255;145;5;3m"
# define BGREEN "\033[0m\033[38;2;0;170;0;1m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

/*
take an inverted Polish mathematical expression as argument:
    `(3 + 4) * 5` would be `3 4 + 5 *`

Each number should be less than 10
You don't have to handle bracket or decimal
If something is wrong, put an ERROR message
*/


class RPN
{
private:
    std::stack<int>	stack;
    //void    addToStack(int n);
    void    multiply();
    void    divide();
    void    add();
    void    subtract();

public:
    RPN();
    RPN(const RPN& src);
    RPN& operator=(const RPN& src);
    ~RPN();

    void compute(std::string const &expression);

    class Error : public std::exception
    {
        private:
            std::string	msg;

        public :
            Error(std::string const &msg);
            virtual ~Error() throw();
            virtual const char *what() const throw();
    };
};
