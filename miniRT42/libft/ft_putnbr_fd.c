/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:10:28 by echapuis          #+#    #+#             */
/*   Updated: 2023/11/07 17:28:54 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	recursivite(long nb, int fd, int *count)
{
	if (nb >= 10)
	{
		recursivite(nb / 10, fd, count);
		*count += ft_putchar_fd(nb % 10 + '0', fd);
	}
	else
		*count += ft_putchar_fd(nb + '0', fd);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	nb;
	int	count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar_fd('-', fd);
		recursivite((long)nb * (-1), fd, &count);
	}
	else
		recursivite(nb, fd, &count);
	return (count);
}
