/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:04:53 by echapuis          #+#    #+#             */
/*   Updated: 2024/03/08 15:38:48 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*chaine;

	i = 0;
	chaine = (char *)s;
	while (i < n)
	{
		if (chaine[i] == (char)c)
			return ((char *)chaine + i);
		++i;
	}
	return (NULL);
}
/*
int	main(void)
{
	char phrase[] = "hellYeahdeadOfDead";
	int	m = 100;
	size_t	n = 12;

	memchr(phrase, m, n);
	printf("%s", phrase);
	return (0);
}*/
