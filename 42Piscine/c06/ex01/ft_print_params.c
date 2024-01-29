/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:43:19 by cejin             #+#    #+#             */
/*   Updated: 2023/07/13 11:53:59 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print(char *str)
{
	int	c;

	c = 0;
	while (str[c])
	{
		write(1, &str[c], 1);
		c++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_print(argv[i]);
		write(1, "\n", 1);
		i++;
	}
}
