/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:16:52 by cejin             #+#    #+#             */
/*   Updated: 2024/12/16 17:26:51 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>

# define RED "\033[1;31m"
# define ORANGE "\033[38;2;255;145;5;3m"
# define BGREEN "\033[0m\033[38;2;0;170;0;1m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

#define ERROR YELLOW "Nothing found in container..." RESET

/*
* find the first occurrence
* of the second parameter in the first parameter
*/
template <typename T>
typename T::iterator easyfind(T &container, int ref)
{
    typename T::iterator	find;
    
    find = std::find(container.begin(), container.end(), ref);
	if (find == container.end()) {
		throw (std::runtime_error(ERROR));
    }
	return (find);
}