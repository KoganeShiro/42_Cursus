/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:55:07 by cejin             #+#    #+#             */
/*   Updated: 2024/12/10 13:13:19 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << GREEN
		"Serializer DEFAULT constructor is called"
	RESET << std::endl;
}

Serializer::Serializer(Serializer const &src)
{
    (void)src;
    std::cout << GREEN
		"Serializer COPY constructor is called"
	RESET << std::endl;
}

Serializer &Serializer::operator=(Serializer const &src)
{
    (void)src;
    std::cout << GREEN
		"Serializer COPY ASSIGNEMENT OPERATOR is called"
	RESET << std::endl;
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}

Serializer::~Serializer()
{
    std::cout << RED
		"Serializer Destructor is called"
	RESET << std::endl;
}
