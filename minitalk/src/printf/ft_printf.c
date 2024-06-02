/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:55:52 by cejin             #+#    #+#             */
/*   Updated: 2024/06/02 16:00:28 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

int	printf_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (format == 's')
		len += ft_printstr(va_arg(args, const char *));
	else if (format == '%')
		len += ft_printchar('%');
	else if (format == 'p')
		len += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_printunsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_printhex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		len += ft_printhex(va_arg(args, unsigned int), "0123456789ABCDEF");
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			len += printf_format(args, format[i + 1]);
			i++;
		}
		else
			len += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
/*
#include <stdio.h>

int	main(void)
{
//	unsigned int u = 10;
//	char *str = NULL;
//	char c = 'c';
//	int i = 5;
//	unsigned long x = −92;

	int len = ft_printf("ft_printf: %p\n", "5");
	ft_printf("ft_printf len : %%%\n\n", len);
//	int true_len = printf("   printf: %p\n", "5");
//	printf("   printf len : %i\n", true_len);
	return (0);
}
*/
