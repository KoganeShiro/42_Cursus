/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:36:49 by cejin             #+#    #+#             */
/*   Updated: 2024/01/23 14:59:56 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_duplicate(char **av, int index)
{
	int	i;
	int	*element;

	i = 0;
	while (av[i] != NULL)
		i++;
	element = ft_calloc(i, sizeof(int));
	if (element == NULL)
		return (0);
	i = 0;
	while (av[i] != NULL)
	{
		element[i] = ft_atol(av[i]);
		i++;
	}
	i = 0;
	while (i < index)
	{
		if (element[i] == element[index])
			return (free(element), 1);
		i++;
	}
	return (free(element), 0);
}

int	ft_is_alpha(char *av)
{
	int	i;

	i = 0;
	while (av[i] != '\0')
	{
		if ((!(av[i] >= '0' && av[i] <= '9'))
			&& av[i] != '-' && av[i] != '+')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t str_len, size_t size)
{
	char	*str;
	size_t	n;
	size_t	i;

	n = str_len * size;
	str = malloc(n);
	if (str == NULL)
		return (0);
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
