/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:32:50 by cejin             #+#    #+#             */
/*   Updated: 2023/07/27 17:37:05 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strrev(char *str)
{
	char	tmp;
	int	last;
	int	first;

	while (str[last + 1])
		last++;
	while (last > first)
	{
		tmp = str[last];
		str[last] = str[first];
		str[first] = tmp;
		first++;
		last--;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%s", ft_strrev(argv[1]));	
	}
	return (0);
}*/
