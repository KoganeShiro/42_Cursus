/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:50:56 by cejin             #+#    #+#             */
/*   Updated: 2024/12/19 18:12:04 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <climits>

# define RED "\033[1;31m"
# define ORANGE "\033[38;2;255;145;5;3m"
# define BGREEN "\033[0m\033[38;2;0;170;0;1m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

#define NO_SPACE YELLOW "Too much elements in container, No space left !" RESET

class Span : public std::vector<int>
{
private:
    unsigned int N;    

public:
    Span();
    Span(unsigned int n); //max of n int to be store
    Span(Span const &src);
    Span &operator=(Span const &src);

    virtual ~Span();

    void addNumber(int n);
    unsigned int shortestSpan();
    unsigned int longestSpan();

    template <typename Iterator>
    void	addRange(Iterator begin, Iterator end)
    {
        if (distance(begin, end) + this->size() > this->N) {
            throw (std::out_of_range(NO_SPACE));
        }
        this->insert(this->end(), begin, end);
    }
};
