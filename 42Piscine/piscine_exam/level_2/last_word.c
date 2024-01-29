/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:06:50 by cejin             #+#    #+#             */
/*   Updated: 2023/07/27 18:33:30 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	last_word(char *str)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && str[i + 1] >= '!' && str[i + 1] <= '~')
			j = i + 1;
		i++;
	}
	while (str[j] >= '!' && str[j] <= '~')
	{
		write(1, &str[j], 1);
		j++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}

/*
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0;

	if (argc == 2)
	{
		while (argv[1][i + 1])
			i++;
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' && argv[1][i] == '\t')
				i--;
			while ((argv[1][i] == 'a' && argv[1][i] == 'z')
					|| (argv[1][i] == 'A' && argv[1][i] == 'Z'))
			{
				write(1, &argv[1][i], 1);
				i--;
			}
		}
		write(1, "\n", 1);
	}
	return (0);
}*/
