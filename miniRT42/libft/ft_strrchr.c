/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echapuis <echapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:13:59 by echapuis          #+#    #+#             */
/*   Updated: 2024/03/08 16:00:25 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i - 1] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
/*
int main()
{
	char phrase[30] = "ooddddllehh";
	int	c = 100;
	printf("%s",ft_strrchr(phrase, c));
	return (0);
}*/
