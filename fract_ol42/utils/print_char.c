/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:26:19 by cejin             #+#    #+#             */
/*   Updated: 2023/11/03 16:00:44 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

int	ft_printchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(const char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
//	const char c = '\n';
	const char *str = "\0";

	ft_printf("ft_printf: %s\n", str);
	printf("printf: %s\n", str);
	return (0);
}
*/
