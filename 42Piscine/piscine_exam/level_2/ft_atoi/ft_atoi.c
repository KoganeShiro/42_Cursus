/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:53:21 by cejin             #+#    #+#             */
/*   Updated: 2023/07/27 15:13:06 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	res;

	i = 0;
	negative = 1;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v')
			|| (str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
	{
		i++;
	}
	if (str[i] == '-')
	{
		negative = -1;
	}
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * negative);
}
/*
#include <stdio.h>

int	main()
{
	char	str[] = " 1235f123";
	printf("%d\n", ft_atoi(str));
	return (0);
}*/
