/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:26:59 by echapuis          #+#    #+#             */
/*   Updated: 2024/11/07 16:20:45 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>

int	ft_check(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_putnbr_un_fd(va_arg(args, unsigned int), 1));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(args, int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *), "0123456789abcdef"));
	return (0);
}

int	ft_printf(const char *c, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, c);
	i = 0;
	len = 0;
	while (c[i])
	{
		if (c[i] == '%')
		{
			len += ft_check(args, c[i + 1]);
			i++;
		}
		else
		{
			len++;
			write(1, &c[i], 1);
		}
		i++;
	}
	va_end(args);
	return (len);
}
/*
int	main(void)
{
	//char	*ph = "gogollum";
	//void *nb = "0";
	//	n = 42342831;
	// ft_printf("%c\n", lettre);
	printf(":%d\n", ft_printf("%p", "0"));
	printf(":%d", printf("%p", "0"));
	// printf("test:%c\n", lettre);
	// ft_printf("%c", lettre);
	return (0);
}*/
