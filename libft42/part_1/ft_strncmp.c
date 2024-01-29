/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:15:51 by cejin             #+#    #+#             */
/*   Updated: 2023/10/27 15:10:14 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && i < n && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>
#include <string.h>
int main () {
   char str1[20];
   char str2[20];

   strcpy(str1, "test\200");
   strcpy(str2, "test\0");

   printf("strncmp; %d", strncmp(str1, str2, 6));
   printf("\nft_strncmp, %d\n", ft_strncmp(str1, str2, 6));
}
*/