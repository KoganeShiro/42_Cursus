/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:36:04 by cejin             #+#    #+#             */
/*   Updated: 2023/07/19 10:15:06 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*table;

	i = 0;
	table = malloc ((max - min) * sizeof(int));
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (table == NULL)
		return (-1);
	while (min < max)
	{
		table[i] = min;
		min++;
		i++;
	}
	*range = table;
	return (i);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])

int    main(int argc, char *argv[])
{
    int    min;
    int    max;
    int    *tab;
    int    range;
    int    i;

    if (2 < argc)
    {
        min = atoi(argv[1]);
        max = atoi(argv[2]);
        range = ft_ultimate_range(&tab, min, max);
        printf("range = %d\n", range);
        if (tab && 0 < range)
        {
            i = 0;
            while (i < range)
            {
                printf("%d", tab[i++]);
                if (i < range)
                    printf(", ");
            }
            printf("\n");
        }
        else
            printf("NULL\n");
    }
    else
        printf("required 'min' 'max'\n");
    return (0);
}*/
