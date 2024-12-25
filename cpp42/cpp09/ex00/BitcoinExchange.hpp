/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:21:59 by cejin             #+#    #+#             */
/*   Updated: 2024/12/25 19:06:04 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
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

#define DATA_FILE "data.csv"


/*
If the date used in the input does not exist in your DB then you
must use the closest date contained in your DB.
Be careful to use the lower date and not the upper one.
*/

class BitcoinExchange
{
private:
    std::map<std::string, float> map;
    float	findClosest(std::string &targetDate) const;

public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &src);
    BitcoinExchange &operator=(BitcoinExchange const &src);
    ~BitcoinExchange();

    int    setData(std::string const &fileName);
    void	convertValue(std::string const &fileName);

    class NegativeNumber : public std::exception
    {
        public :
            virtual const char *what() const throw();
    };
    class TooLargeNumber : public std::exception
    {
        public :
            virtual const char *what() const throw();
    };
};
