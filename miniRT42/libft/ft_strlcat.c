/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echapuis <echapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:37:04 by echapuis          #+#    #+#             */
/*   Updated: 2023/10/30 18:30:44 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	j;
	size_t	len_dest;
	size_t	len_src;

	j = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (size - 1 < len_dest)
		return (len_src + size);
	while (len_dest + j < size - 1 && src[j])
	{
		dest[len_dest + j] = src[j];
		j++;
	}
	dest[len_dest + j] = '\0';
	return (len_dest + len_src);
}
/*
int	main(void)
{
	char	chaine1[100] = "gollum";
	char	chaine2[] = "hello";
	size_t		result;
	int		nb;

	nb = 21;
	result = strlcat(chaine1, chaine2, nb);
	printf("%s\n", chaine1);
	printf("%ld", result);
	return (0);
}*/
