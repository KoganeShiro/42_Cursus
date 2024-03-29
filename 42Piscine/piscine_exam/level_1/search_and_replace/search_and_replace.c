/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:40:04 by cejin             #+#    #+#             */
/*   Updated: 2023/07/27 12:01:12 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0;

	if (argc == 4)
	{
		if ((!argv[2][1]) && (!argv[3][1]))
		{
			while (argv[1][i])
			{
				if (argv[1][i] == argv[2][0])
					write(1, &argv[3][0], 1);

				else
					write(1, &argv[1][i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
