/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:53:04 by cejin             #+#    #+#             */
/*   Updated: 2024/11/20 14:48:04 by cejin            ###   ########.fr       */
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

class Fixed
{
private:
	int					rawBits; //fixedPointValue
	static const int	fractionalBits = 8;

public:
	Fixed(); //Default
	Fixed(const Fixed &copy); //Copy of the Default
	Fixed &operator = (const Fixed &src); // Copy assignment operator overload
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};
