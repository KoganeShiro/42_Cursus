/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:51:44 by cejin             #+#    #+#             */
/*   Updated: 2024/11/26 17:55:54 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

class Animal
{
protected:
	std::string	type;

public:
    Animal();
	Animal(const Animal &src);
	Animal &operator=(const Animal &src);
	Animal(std::string const &name);
    virtual ~Animal();

	virtual void	makeSound() const;
	void	setType(std::string const &type);
	std::string const	getType() const;
};
