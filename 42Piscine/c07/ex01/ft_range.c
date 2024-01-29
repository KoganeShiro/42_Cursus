/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:32:08 by cejin             #+#    #+#             */
/*   Updated: 2023/07/17 17:35:27 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*table;
	int	i;
	int	range;

	range = max - min;
	i = 0;
	table = (int *)malloc(range * sizeof(int));
	if (min >= max)
		return (0);
	while (min < max)
	{
		table[i] = min;
		min++;
		i++;
	}
	return (table);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	int max;
	int min;
	int *tab;
	int range;
	int i;

	if (2 < argc)
	{
		min = atoi(argv[1]);
		max = atoi(argv[2]);
		range = max - min;
		tab = ft_range(min, max);
		if (tab && 0 < range)
		{
			i = 0;
			while (i < range)
			{
				printf("%d", tab[i++]);
				if (i < range)
					printf(" ");
			}
			printf("\n");
		}
		else
			printf("NULL\n");
	}
	else
		printf("Didn't put min or/and max");
	return (0);
}
*/
