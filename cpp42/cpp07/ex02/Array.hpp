/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:14:35 by cejin             #+#    #+#             */
/*   Updated: 2024/12/16 14:52:07 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

# define RED "\033[1;31m"
# define ORANGE "\033[38;2;255;145;5;3m"
# define BGREEN "\033[0m\033[38;2;0;170;0;1m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

#define OUT_OF_RANGE YELLOW "Index out of bounds !" RESET

#define MAX_VAL 7

template <typename T>
class Array
{
private:
    T      *array;
    unsigned int arrLen;

public:
    Array();
    Array(unsigned int n); //create array of n element
    Array(const Array &src);
    Array	&operator=(const Array &src);
    ~Array();

    // std::exception if not within bounds
    T		&operator[](unsigned int index);
	T const &operator[](unsigned int index) const;

    unsigned int size() const;
};
