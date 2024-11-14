/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:52:17 by cejin             #+#    #+#             */
/*   Updated: 2023/10/23 12:01:45 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	available_space;
	size_t	i;

	i = 0;
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	available_space = size - len_d - 1;
	if (len_d >= size)
		return (len_s + size);
	while (i < available_space && src[i] != '\0')
	{
		dst[len_d + i] = src[i];
		i++;
	}
	dst[len_d + i] = '\0';
	return (len_d + len_s);
}

/*
#include <bsd/string.h>
#include <stdio.h>
#include <stdlib.h>

int    main(int argc, char *argv[])
{
    char            *dest1;
    char            *dest2;
    unsigned int    size;
    unsigned int    n;
    if (3 < argc)
    {
        n = atoi(argv[3]);
        size = strlen(argv[1]) + strlen(argv[2]) + 1;
        dest1 = malloc(size * sizeof(char));
        dest2 = malloc(size * sizeof(char));
        strcpy(dest1, argv[1]);
        strcpy(dest2, argv[1]);
        printf("src = '%s', dest = '%s', n = %d\n\\/\n",
	argv[2], argv[1], n);
        printf("strlcat = '%zu', dest = '%s'\n",
	strlcat(dest1, argv[2], n),dest1);
        printf("ft_strlcat = '%zu', dest = '%s'\n",
	ft_strlcat(dest2, argv[2], n),dest2);
    }
    else
        printf("required 's1' 's2' 'n'\n");
}
*/
