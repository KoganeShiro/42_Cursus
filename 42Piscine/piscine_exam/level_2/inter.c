/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:56:13 by cejin             #+#    #+#             */
/*   Updated: 2023/07/27 18:04:26 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	iter(char *str, char c, int len)
{
	int	i;

	i = 0;
	while (str[i] && (i < len || len == -1))
		if (str[i++] == c)
			return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			if (!iter(argv[1], argv[1][i], i) && iter(argv[2], argv[1][i], -1))
				write(1, &argv[1][i], 1);
			i += 1;
		}
	}
	write(1, "\n", 1);
	return (0);
}



/*
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0;

	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (argv[2][i] == argv[1][i])
			{
				write(1, &argv[2][i], 1);
			}
			i++;
		}
		write(1, "\n", 1);
		return (0);
	}
}*/
