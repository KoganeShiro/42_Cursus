/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:33:29 by cejin             #+#    #+#             */
/*   Updated: 2024/06/02 15:59:45 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_atou(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

int	ft_strlen(char *mes)
{
	int	i;

	i = 0;
	if (mes == NULL)
		return (0);
	while (mes[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t str_len, size_t size)
{
	char	*str;
	size_t	i;
	size_t	n;

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

/*
char	*ft_strjoin(char *str, int add)
{
	int		i;

	i = 0;
	str[i] = add;
	str[i + 1] = '\0';
	return (str);
}
*/

char	*ft_strjoin(char *str, int add)
{
	int		i;
	char	*res;
	int		len;

	i = 0;
	len = ft_strlen(str);
	res = ft_calloc(len + 2, sizeof(char));
	if (res == NULL)
		return (NULL);
	while (str != NULL && str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = add;
	res[i + 1] = '\0';
	free(str);
	return (res);
}
