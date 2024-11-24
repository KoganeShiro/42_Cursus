/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:53:04 by cejin             #+#    #+#             */
/*   Updated: 2024/11/23 10:33:25 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cmath>

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
	
	Fixed(const int value);
	Fixed(const float value);
	
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	bool	operator<(Fixed const &n2) const; //n1 == this
	bool	operator>(Fixed const &n2) const; //n1 == this
	bool	operator<=(Fixed const &n2) const; //n1 == this
	bool	operator>=(Fixed const &n2) const; //n1 == this
	bool	operator==(Fixed const &n2) const; //n1 == this
	bool	operator!=(Fixed const &n2) const; //n1 == this

	Fixed	operator+(Fixed const &n2) const;
	Fixed	operator-(Fixed const &n2) const;
	Fixed	operator*(Fixed const &n2) const;
	Fixed	operator/(Fixed const &n2) const;

	Fixed&	operator++(void); //pre increment
	Fixed&	operator--(void);
	Fixed	operator++(int); //post increment (int is a dummy parameter)
	Fixed	operator--(int);

	static Fixed const	&min(Fixed const &n1, Fixed const &n2);
	static Fixed const	&max(Fixed const &n1, Fixed const &n2);
	static Fixed		&min(Fixed &n1, Fixed &n2);
	static Fixed		&max(Fixed &n1, Fixed &n2);
};

std::ostream	&operator<<(std::ostream& out, const Fixed &src);
