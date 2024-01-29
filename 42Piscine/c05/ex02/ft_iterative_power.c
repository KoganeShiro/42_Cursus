/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:55:12 by cejin             #+#    #+#             */
/*   Updated: 2023/07/15 11:30:58 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;	

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = nb;
	while (power > 1)
	{
		nb = (nb * i);
		power--;
	}
	return (nb);
}
/*
#include <stdio.h>

int	main(void)
{	
	printf("%d", ft_iterative_power(55, 1));
	return (0);
}
*/
