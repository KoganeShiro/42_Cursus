/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:51:44 by cejin             #+#    #+#             */
/*   Updated: 2024/11/27 16:03:27 by cejin            ###   ########.fr       */
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

class Aanimal
{
protected:
	std::string	type;

public:
    Aanimal();
	Aanimal(const Aanimal &src);
	Aanimal &operator=(const Aanimal &src);
	Aanimal(std::string const &name);
    virtual ~Aanimal();

	virtual void	makeSound() const = 0;
	void	setType(std::string const &type);
	std::string const	getType() const;
};
