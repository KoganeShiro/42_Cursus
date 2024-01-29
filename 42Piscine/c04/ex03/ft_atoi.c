/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:29:45 by cejin             #+#    #+#             */
/*   Updated: 2023/07/13 10:26:16 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	sign;
	int	i;
	int	res;

	sign = 1;
	i = 0;
	res = 0;
	while ((str[i] != '\0') && (str[i] == ' '
			|| str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r'))
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res *= sign);
}

/*
#include <stdio.h>
int main()
{
    char str[] = "---++897h005429";
 
    int val = ft_atoi(str);
    printf("%d", val);
}
*/
