/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:08:22 by cejin             #+#    #+#             */
/*   Updated: 2023/10/20 17:49:03 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*src1;
	char	*src2;

	i = 0;
	src1 = (char *)s1;
	src2 = (char *)s2;
	while (i < n)
	{
		if (src1[i] != src2[i])
			return ((unsigned char)src1[i] - (unsigned char)src2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	char str1[] = "Hello, world"; // Array of size 100 
	char str2[] = "Hello, world";

    int mine = ft_memcmp(str1, str2, 15); 
	int true = memcmp(str1, str2, 15);
	
    printf("memcmp; %d\n", true);
    printf("ft_memmove; %d\n", mine);
  
    return 0; 
}
*/