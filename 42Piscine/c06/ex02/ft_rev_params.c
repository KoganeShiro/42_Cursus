/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:11:16 by cejin             #+#    #+#             */
/*   Updated: 2023/07/13 18:35:27 by cejin            ###   ########.fr       */
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
	return ;
}

int	main(int argc, char *argv[])
{
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		ft_print(argv[i]);
		write(1, "\n", 1);
		i--;
	}
}
