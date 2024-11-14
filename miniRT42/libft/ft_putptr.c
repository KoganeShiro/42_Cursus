/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:02:18 by echapuis          #+#    #+#             */
/*   Updated: 2023/11/08 14:59:55 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	recur_ptr(size_t nb, size_t len_base, int *count, char *base)
{
	if (nb >= len_base)
	{
		recur_ptr(nb / len_base, len_base, count, base);
		*count += ft_putchar_fd(base[nb % len_base], 1);
	}
	else
		*count += ft_putchar_fd(base[nb], 1);
}

int	ft_putptr(void *nb, char *base)
{
	int		count;
	size_t	len;
	size_t	n;

	count = 0;
	if (nb == NULL)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	n = (size_t)nb;
	len = ft_strlen(base);
	recur_ptr(n, len, &count, base);
	return (count + 2);
}
