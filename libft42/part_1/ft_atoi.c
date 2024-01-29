/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:00:30 by cejin             #+#    #+#             */
/*   Updated: 2023/10/21 14:45:23 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	res;

	sign = 1;
	i = 0;
	res = 0;
	while ((nptr[i] != '\0') && (nptr[i] == ' '
			|| nptr[i] == '\n' || nptr[i] == '\t' || nptr[i] == '\v'
			|| nptr[i] == '\f' || nptr[i] == '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= (-1);
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
		return (0);
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res *= sign);
}
/*
#include <stdlib.h>
#include <stdio.h>
int main()
{
    char nptr[] = "  -89700k5429";
 
    int val = ft_atoi(nptr);
    int true = atoi(nptr);
    printf("atoi, %d", true);
    printf("\nft_atoi, %d\n", val);
}
*/