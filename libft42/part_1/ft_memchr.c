/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:02:24 by cejin             #+#    #+#             */
/*   Updated: 2023/10/21 14:14:56 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*src;

	i = 0;
	src = (char *)s;
	while (i < n)
	{
		if (src[i] == (char)c)
			return ((void *)(src + i));
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    char search[] = "TechOnTheNet";
    char *ptr;
    char *ptr2;
	char c = 'e';

    ptr = (char*)memchr(search, c, strlen(search));
    ptr2 = (char*)ft_memchr(search, c, strlen(search));

    if (ptr != NULL && ptr2 != NULL)
	{
		printf("memchr;  %ld.\n", 1+(ptr-search));
		printf("ft_memchr; %ld.\n", 1+(ptr2-search));
	}
    else printf("%d was not found.\n", c);

    return 0;
}
*/