/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:01:02 by echapuis          #+#    #+#             */
/*   Updated: 2023/10/31 12:27:45 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_modif1(int i, int n, char *dest2, char *src2)
{
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
}

void	ft_modif2(int j, char *dest2, char *src2)
{
	while (j)
	{
		j--;
		dest2[j] = src2[j];
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	j;
	char	*dest2;
	char	*src2;

	i = 0;
	dest2 = (char *)dest;
	src2 = (char *)src;
	j = n;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (src > dest)
	{
		ft_modif1(i, n, dest2, src2);
	}
	else
	{
		ft_modif2(j, dest2, src2);
	}
	return (dest);
}
/*
int	main(void)
{
	char phrase[] = "hello pirate";
	int	nb = 3;
	int	j = 0;
	ft_memmove(phrase, phrase + 2, nb);
	while (phrase[j] != '\0')
	{
		write(1, &phrase[j], 1);
		j++;
	}
	return (0);
}*/
