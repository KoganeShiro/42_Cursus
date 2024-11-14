/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echapuis <echapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:29:22 by echapuis          #+#    #+#             */
/*   Updated: 2023/10/22 17:50:21 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*tab;
	size_t	i;

	i = 0;
	tab = (char *)s;
	while (i < n)
	{
		tab[i] = c;
		i++;
	}
	return (s);
}
/*
int main()
{
	int n = 5;
	char phrase[] = "fuckyeahhhh";
	int c = 100;

	char *result = (char *)ft_memset(phrase, c, n);
	//printf("%p\n",memset(phrase, c, n));
	printf("%s\n", result);
	return (0);
}*/
