/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:09:40 by cejin             #+#    #+#             */
/*   Updated: 2023/10/25 17:28:33 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_of_digit(int n)
{
	int	result;

	result = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

static char	*is_negatif(int n)
{
	int		i;
	long	number;
	char	*str;

	i = number_of_digit(n);
	number = (long)n;
	if (n < 0)
	{
		str = (char *)malloc((i + 2) * sizeof(char));
		if (str == NULL)
			return (0);
		str[0] = '-';
		str[i + 1] = '\0';
		number = -number;
	}
	while (i > 0)
	{
		str[i] = (number % 10) + '0';
		number = number / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = number_of_digit(n);
	if (n < 0)
	{
		str = is_negatif(n);
		return (str);
	}
	str = (char *)malloc((i + 1) * sizeof(char));
	if (str == 0)
		return (0);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
/*
#include <stdio.h>

int main()
{
	int	n = -0;
	
	printf("digits %d\n", number_of_digit(n));
	printf("itoa, %s\n", ft_itoa(n));
	
	return (0);
}
*/
