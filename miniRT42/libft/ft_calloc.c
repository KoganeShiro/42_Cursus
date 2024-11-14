/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:04:28 by echapuis          #+#    #+#             */
/*   Updated: 2023/10/26 11:00:11 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	tab = malloc(size * nmemb);
	if (!tab)
		return (NULL);
	ft_bzero(tab, size * nmemb);
	return (tab);
}
/*
int	main(void)
{
	int n = 4;
	int j = 0;
	char phrase[] = "heyfriend";

	ft_calloc(phrase, n);
	while (j < 9)
	{
		write(1, &phrase[j], 1);
		j++;
	}
	printf("%s\n", phrase);
//	printf("%s\n", bzero(phrase, n));
	return (0);
}*/
