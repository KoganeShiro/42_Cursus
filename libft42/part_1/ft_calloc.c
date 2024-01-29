/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:34:28 by cejin             #+#    #+#             */
/*   Updated: 2023/10/21 10:55:00 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
#include <stdio.h>
#include <stdlib.h>
# include <string.h>

int	main()
{
		size_t nmemb = 10;
		size_t size = 1;

		int *std_calloc_arr = calloc(nmemb, size);
		int *ft_calloc_arr = ft_calloc(nmemb, size);

		if (std_calloc_arr != NULL && ft_calloc_arr != NULL) {
			printf("  calloc result: ");
			for (size_t i = 0; i < nmemb; i++) printf("%d ", std_calloc_arr[i]);
			printf("\nft calloc result: ");
			for (size_t i = 0; i < nmemb; i++) printf("%d ", ft_calloc_arr[i]);
			free(std_calloc_arr);
			free(ft_calloc_arr);
		} else {
			printf("Memory allocation failed.\n");
		}

		return 0;
}
*/