/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:22:05 by cejin             #+#    #+#             */
/*   Updated: 2023/10/20 17:47:00 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
 
int main()
{
    char str[] = "teste";
 
    char chr = '\0';

    char* ptr = strrchr(str, chr);
	char* ptr2 = ft_strrchr(str, chr);
 
    if (ptr || ptr2) {
        printf("strrchr; %c in %s is at index %ld",
               chr, str, ptr - str);
		printf("\nft_strrchr; %c in %s is at index %ld\n",
               chr, str, ptr2 - str);
    }
    else {
        printf("%c is not present in %s ", chr, str);
    }
    return 0;
}
*/