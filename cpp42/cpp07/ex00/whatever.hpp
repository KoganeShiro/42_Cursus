/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:20:09 by cejin             #+#    #+#             */
/*   Updated: 2024/12/16 11:34:12 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

# define RED "\033[1;31m"
# define ORANGE "\033[38;2;255;145;5;3m"
# define BGREEN "\033[0m\033[38;2;0;170;0;1m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

//template function

template <typename T>
void swap(T &a,T &b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
const T min(const T &a, const T &b)
{
    if (a == b) {
        std::cout <<
            RED << a << " is equal to " << b << "\nNo min" RESET
        << std::endl;
        return (a);
    }
	if (a < b) {
        return (a);
    }
    else {
        return (b);
    }
}

template <typename T>
const T max(const T &a, const T &b)
{
    if (a == b) {
        std::cout <<
            RED << a << " is equal to " << b << "\nNo max" RESET
        << std::endl;
        return (a);
    }
	if (a < b) {
        return (b);
    }
    else {
        return (a);
    }
}
