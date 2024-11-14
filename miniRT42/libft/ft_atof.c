/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:55:56 by cejin             #+#    #+#             */
/*   Updated: 2024/11/13 15:19:05 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

int	is_whitespaces(char c)
{
	if ((c >= '\t'
			&& c <= '\r') || c == ' ')
	{
		return (true);
	}
	return (false);
}

int	skip_whitespaces(char *value)
{
	int		i;

	i = 0;
	if (value == NULL || value[i] == '\0')
		return (-1);
	while (is_whitespaces(value[i]) == true)
	{
		i++;
	}
	return (i);
}

static int	_what_sign(char value, int *i)
{
	int	sign;

	sign = 1;
	if (value == '-' || value == '+')
		(*i)++;
	if (value == '-')
		sign = -1;
	return (sign);
}

bool	is_nb(char value)
{
	if ((value != '\0')
		&& (value >= '0' && value <= '9'))
	{
		return (true);
	}
	return (false);
}

//return error if we encounter an unexpected char
float	ft_atof(char *value)
{
	int		i;
	int		sign;
	long	res;
	float	decimal;
	float	pow;

	i = 0;
	sign = _what_sign(value[i], &i);
	res = 0;
	pow = 1;
	decimal = 0;
	while (value[i] != '.' && is_nb(value[i]) == true)
		res = res * 10 + (value[i++] - '0');
	if (value[i] == '.')
		i++;
	while (is_nb(value[i]) == true)
	{
		pow /= 10;
		decimal = decimal + (value[i] - '0') * pow;
		i++;
	}
	return ((res + decimal) * sign);
}
