/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:33:48 by cejin             #+#    #+#             */
/*   Updated: 2023/07/17 09:19:21 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 3;
	if ((nb == 2) || (nb == 3))
		return (1);
	if ((nb <= 1) || (nb % 2 == 0))
		return (0);
	while (i < (nb / i))
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (2);
	i = nb;
	while (!ft_is_prime(i))
	{
		i++;
	}
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_is_prime(75));
	printf("%d", ft_find_next_prime(75));
	return (0);
}

#include <stdlib.h>

int	main(int argc, char *argv[])
{
	(void)argc;
	int nb = atoi(argv[1]);
	printf("Le nombre premier le plus proche de %d est %d",
	nb, ft_find_next_prime(nb));
}
*/
