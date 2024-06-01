/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:29:32 by cejin             #+#    #+#             */
/*   Updated: 2023/07/12 19:47:50 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	n;

	n = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
	{
		return (1);
	}
	if (nb == 1)
		return (1);
	while (nb != 0)
	{
		n *= nb;
		nb--;
	}
	return (n);
}
/*
#include <stdio.h>
int	 main(void)
{
	printf("%d", ft_iterative_factorial(5));
	return (0);
}
*/
