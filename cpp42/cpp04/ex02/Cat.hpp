/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:29:58 by cejin             #+#    #+#             */
/*   Updated: 2024/11/27 15:58:28 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Aanimal.hpp"
#include "Brain.hpp"

# define RED "\033[1;31m"
# define ORANGE "\033[38;2;255;145;5;3m"
# define BGREEN "\033[0m\033[38;2;0;170;0;1m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

class Cat : public Aanimal
{
private:
	Brain	*brain;

public:
	Cat();
	Cat(const Cat &src);
	Cat &operator=(const Cat &src);
	Cat(std::string const &name);
	~Cat();

	void	makeSound() const;
	void	setIdeasInBrain(std::string const &idea);
	void	displayBrainIdeas(int i) const;
};
