/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:56:35 by cejin             #+#    #+#             */
/*   Updated: 2024/12/20 12:11:19 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#define NO_SPAN YELLOW "No span could be found" RESET

Span::Span(unsigned int n): N(n)
{
    std::cout << GREEN
		"Span DEFAULT constructor is called (Max int to be store=" << n << ")"<<
	RESET << std::endl;
}

Span::Span(Span const &src): std::vector<int>(src), N(src.N)
{
    std::cout << GREEN
		"Span COPY constructor is called"
	RESET << std::endl;
}

Span	&Span::operator=(Span const &src)
{
    std::cout << GREEN
		"Span COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
	*static_cast<std::vector<int> *>(this) = src;
    if (this != &src) {
	    this->N = src.N;
    }
	return (*this);
}

void    Span::addNumber(int n)
{
	if (this->N <= this->size())
		throw (std::out_of_range(NO_SPACE));
	this->push_back(n);
}

unsigned int	Span::shortestSpan()
{
	unsigned int	minSpan;

	minSpan = UINT_MAX;
	if (this->size() < 2) {
		throw (std::domain_error(NO_SPAN));
    }
	std::sort(this->begin(), this->end());
	for (unsigned int i = 1; i < this->size(); i++) {
		minSpan = std::min(minSpan,
            static_cast<unsigned int>(std::abs((*this)[i] - (*this)[i - 1])));	
    }
    return (minSpan);
}

unsigned int	Span::longestSpan()
{
	if (this->size() < 2) {
		throw (std::domain_error(NO_SPAN));
    }
	return (*std::max_element(this->begin(),
        this->end()) - *std::min_element(this->begin(), this->end()));
}

Span::~Span()
{
	std::cout << RED
		"Span Destructor is called"
	RESET << std::endl;
}