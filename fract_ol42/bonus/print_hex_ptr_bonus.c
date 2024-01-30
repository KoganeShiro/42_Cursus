/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:23:50 by cejin             #+#    #+#             */
/*   Updated: 2023/11/03 16:00:56 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_printhex(unsigned long nb, char *hex)
{
	int	len;

	len = 0;
	if (nb / 16)
	{
		len += ft_printhex(nb / 16, hex);
		len += ft_printchar(hex[nb % 16]);
	}
	else
		len += ft_printchar(hex[nb % 16]);
	return (len);
}

int	ft_printptr(unsigned long long ptr)
{
	int					len;

	len = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (ptr > 0)
	{
		write(1, "0x", 2);
		len += 2;
	}
	len += ft_printhex(ptr, "0123456789abcdef");
	return (len);
}
