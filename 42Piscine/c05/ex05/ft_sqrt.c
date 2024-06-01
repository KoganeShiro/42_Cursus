/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:48:35 by cejin             #+#    #+#             */
/*   Updated: 2023/07/17 09:14:27 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	sqrt;

	sqrt = 1;
	if (nb > 2147395600)
		return (0);
	if (nb > 0)
	{
		while (sqrt * sqrt < nb)
			sqrt++;
		if (sqrt * sqrt == nb)
			return (sqrt);
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d", ft_sqrt(1000000));
	return (0);
}

#include <stdlib.h>
int	main(int argc, char **argv)
{
	int	nb;

	nb = atoi(argv[1]);
	(void)argc;
	printf("La racine carre de : %d a pour resultat : %d", nb, ft_sqrt(nb));
	return (0);
}
*/
