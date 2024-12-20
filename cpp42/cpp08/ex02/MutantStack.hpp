/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:12:39 by cejin             #+#    #+#             */
/*   Updated: 2024/12/20 12:10:12 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
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


template <class T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
	public:
		typedef typename Container::iterator iterator;

		iterator	begin(void);
		iterator	end(void);
};
