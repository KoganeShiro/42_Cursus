/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:40:18 by echapuis          #+#    #+#             */
/*   Updated: 2023/11/08 15:03:15 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	recur_base(long nb, unsigned int len_base, int *count, char *base)
{
	if (nb >= len_base)
	{
		recur_base(nb / len_base, len_base, count, base);
		*count += ft_putchar_fd(base[nb % len_base], 1);
	}
	else
		*count += ft_putchar_fd(base[nb], 1);
}

int	ft_putnbr_base(unsigned int nb, char *base)
{
	int				count;
	unsigned int	len;

	count = 0;
	len = ft_strlen(base);
	recur_base(nb, len, &count, base);
	return (count);
}
