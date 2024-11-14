/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:14:35 by echapuis          #+#    #+#             */
/*   Updated: 2023/11/07 17:29:03 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	recur(long nb, int fd, int *count)
{
	if (nb >= 10)
	{
		recur(nb / 10, fd, count);
		*count += ft_putchar_fd(nb % 10 + '0', fd);
	}
	else
		*count += ft_putchar_fd(nb + '0', fd);
}

int	ft_putnbr_un_fd(unsigned int n, int fd)
{
	unsigned int	nb;
	int				count;

	nb = n;
	count = 0;
	recur(nb, fd, &count);
	return (count);
}
