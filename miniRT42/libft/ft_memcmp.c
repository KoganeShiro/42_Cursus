/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echapuis <echapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:59:29 by echapuis          #+#    #+#             */
/*   Updated: 2023/10/21 12:32:14 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*ch1;
	char	*ch2;

	i = 0;
	ch1 = (char *)s1;
	ch2 = (char *)s2;
	if (n == 0)
		return (0);
	while ((ch1[i] == ch2[i]) && i < n - 1)
		i++;
	return ((unsigned char)ch1[i] - (unsigned char)ch2[i]);
}
/*
int main()
{
	char phrase1[30] = "hell";
	char phrase2[30] = "yeaaahh";
	int	nb = 3;

	printf("%d", ft_memcmp(phrase1, phrase2, nb));
	return (0);
}*/
