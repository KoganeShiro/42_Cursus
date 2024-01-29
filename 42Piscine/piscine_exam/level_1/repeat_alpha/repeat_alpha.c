/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:01:54 by cejin             #+#    #+#             */
/*   Updated: 2023/07/27 10:34:15 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0;
	int	nb_letters;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				nb_letters = argv[1][i] - 'a';
				while (nb_letters >= 0)
				{
					write(1, &argv[1][i], 1);
					nb_letters--;
				}
			}
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				nb_letters = argv[1][i] - 'A';
				while (nb_letters >= 0)
                                {
					write(1, &argv[1][i], 1);
					nb_letters--;
				}
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
