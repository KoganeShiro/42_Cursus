/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:05:12 by cejin             #+#    #+#             */
/*   Updated: 2023/07/13 12:05:24 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print(char *tab)
{
	int	i;

	i = 0;
	while (tab[i] != '\0')
	{
		write(1, &tab[i], 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc >= 1)
		ft_print(argv[0]);
	write(1, "\n", 1);
}
