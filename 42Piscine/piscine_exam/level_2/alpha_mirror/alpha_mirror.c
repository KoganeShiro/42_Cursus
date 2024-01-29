/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:25:17 by cejin             #+#    #+#             */
/*   Updated: 2023/07/27 15:41:20 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0;
	char	l;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				l = 'z' - (argv[1][i] - 'a');
				write(1, &l, 1);
			}
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				l = 'Z' - (argv[1][i] - 'A');
				write(1, &l, 1);
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
