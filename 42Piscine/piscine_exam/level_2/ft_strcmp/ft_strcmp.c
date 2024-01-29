/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:47:20 by cejin             #+#    #+#             */
/*   Updated: 2023/07/27 16:00:43 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int    ft_strcmp(char *s1, char *s2)
{
	int	i = 0;
	int	j = 0;

	while (s1[i] && s1[i] == s2[j])
	{
		j++;
		i++;
	}
	return (s1[i] - s2[j]);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("La diff entre %s et %s est de %d",
				argv[1], argv[2], ft_strcmp(argv[1], argv[2]));
	}
	return (0);
}*/
