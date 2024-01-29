/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:44:15 by cejin             #+#    #+#             */
/*   Updated: 2023/07/27 10:12:38 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	a = atoi(argv[1]);
	int	b = atoi(argv[2]);

	if (argc == 3)
	{
		printf("a = %d b = %d\n", a, b);
		ft_swap(&a, &b);
		printf("After swap\na = %d b = %d", a, b);
	}
	return (0);
}
