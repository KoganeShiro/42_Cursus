/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:05:12 by cejin             #+#    #+#             */
/*   Updated: 2023/07/17 12:00:56 by cejin            ###   ########.fr       */
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
	while (i <= (nb / (i)))
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_is_prime(961));
	return (0);
}

#include <stdlib.h>
int	main(int argc, char *argv[])
{
	(void)argc;
	int nb = atoi(argv[1]);
	printf( %d", ft_is_prime(nb));
	return (0);
}
*/
