/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echapuis <echapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:15:47 by echapuis          #+#    #+#             */
/*   Updated: 2023/10/24 11:59:39 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*tab1;
	char	*tab2;

	i = 0;
	tab1 = (char *)dest;
	tab2 = (char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		tab1[i] = tab2[i];
		i++;
	}
	return (dest);
}
/*
int main()
{
	int nb = 3;
	char phrase[] = "ayaya";
	char phrase2[] = "popopo";
	
	ft_memcpy(phrase, phrase2, nb);
	//memcpy(phrase, phrase2, nb);
	printf("%s\n", phrase);

	return (0);
}*/
