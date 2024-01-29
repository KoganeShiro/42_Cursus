/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:19:21 by cejin             #+#    #+#             */
/*   Updated: 2023/10/24 13:11:23 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lil_len;
	size_t	i;
	size_t	j;

	lil_len = 0;
	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (little[lil_len])
		lil_len++;
	while (big[i] && i + lil_len <= len)
	{
		while (big[i + j] == little[j] && little[j])
			j++;
		if (j == lil_len)
			return ((char *)&big[i]);
		i++;
		j = 0;
	}
	return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>

int	main(void)
{
	const char *largestring = "Foo Bar Baz";
	const char *smallstring = "Baz";
	char *ptr;
	char *ptr_true;

	ptr = ft_strnstr(largestring, smallstring, strlen(largestring));
	ptr_true = strnstr(largestring, smallstring, strlen(largestring));
	if (ptr != NULL || ptr_true != NULL) 
	{
		printf("ft_strnstr; '%s' at position %ld\n",
						 smallstring, ptr - largestring);
		printf("strnstr; '%s' at position %ld\n",
						 smallstring, ptr_true - largestring);
	}
	else
		printf("Substring '%s' not found in '%s'\n", smallstring, largestring);
	return (0);
}
*/