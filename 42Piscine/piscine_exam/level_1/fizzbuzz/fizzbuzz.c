/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:51:59 by cejin             #+#    #+#             */
/*   Updated: 2023/07/27 14:23:35 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_writenbr(int nb)
{
	if (nb > 9)
	{
		ft_writenbr(nb / 10);
	}
	write(1, &"0123456789"[nb % 10], 1);
}

void	ft_fizzbuzz(void)
{
	int	i = 1;

	while (i <= 100 )
	{
		if ((i % 5 == 0) && (i % 3 == 0))
		{
			write(1, "fizzbuzz", 8);
		}
		else if (i % 3 == 0)
		{
			write(1, "fizz", 4);
		}
		else if (i % 5 == 0)
		{
			write(1, "buzz", 4);
		}
		else
			ft_writenbr(i);
		write(1, "\n", 1);
		i++;
	}
}

int	main(void)
{
	ft_fizzbuzz();
	return(0);
}
