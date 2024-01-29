/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:10:18 by event             #+#    #+#             */
/*   Updated: 2023/07/08 16:13:34 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	compteur_char;

	compteur_char = 0;
	while (str[compteur_char] != '\0')
	{
		write (1, &str[compteur_char], 1);
		compteur_char++;
	}
}
