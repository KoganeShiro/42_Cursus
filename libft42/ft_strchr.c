/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:12:17 by cejin             #+#    #+#             */
/*   Updated: 2023/10/20 17:49:37 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*result;

	result = (char *)s;
	i = 0;
	while (result[i])
	{
		if (result[i] == (char)c)
			return (&result[i]);
		i++;
	}
	if (result[i] == (char)c)
		return (&result[i]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
 
 
int main(void)
{
	char str1[40] = "tripouille";
	int ch = 't';
	
	char *ptr = ft_strchr(str1, ch + 256);  
	printf( "ft_strchr, '%d'\n", ptr - str1 + 1 );
	char *ptr2 = strchr(str1, ch + 256);
	printf( "strchr, '%d'\n", ptr2 - str1 + 1 );
}
*/