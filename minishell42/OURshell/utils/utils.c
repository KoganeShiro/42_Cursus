/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:37:56 by vharatyk          #+#    #+#             */
/*   Updated: 2024/05/12 15:24:45 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ')
		return (true);
	else
		return (false);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen((char *)src));
}

static int	_which_sign(char *n, int i)
{
	int	sign;

	sign = 1;
	if (n[i] == '+' || n[i] == '-')
	{
		if (n[i] == '-')
			sign = -1;
		i++;
	}
	return (sign);
}

int	ft_atoi(char *n)
{
	int			i;
	long long	res;
	int			sign;

	i = 0;
	sign = 1;
	res = 0;
	while (is_space(n[i]))
		i++;
	sign = _which_sign(n, i);
	if (n[i] == '+' || n[i] == '-')
		i++;
	while (n[i] >= '0' && n[i] <= '9')
	{
		res = res * 10 + (n[i] - '0');
		i++;
	}
	if (res > 255)
		res = res % 256;
	if (sign == -1)
		res = 256 - res;
	return (res);
}
