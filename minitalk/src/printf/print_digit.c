/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:26:21 by cejin             #+#    #+#             */
/*   Updated: 2024/06/02 16:00:21 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

int	ft_printnbr(int n)
{
	int		len;
	long	nb;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		len += ft_printchar('-');
	}
	if (nb >= 10)
	{
		len += ft_printnbr(nb / 10);
		len += ft_printchar(nb % 10 + '0');
	}
	else
		len += ft_printchar(nb % 10 + '0');
	return (len);
}

int	ft_printunsigned(unsigned int n)
{
	int				len;
	unsigned long	nb;

	len = 0;
	nb = n;
	if (nb >= 10)
	{
		len += ft_printnbr(nb / 10);
		len += ft_printchar(nb % 10 + '0');
	}
	else
		len += ft_printchar(nb % 10 + '0');
	return (len);
}

/*
 #include <stdio.h>
 
int	main()
{
	unsigned int i = -2147483648;
	ft_printf("ft_printf : %u\n", i);
	printf("printf : %u\n", i);
}
*/
