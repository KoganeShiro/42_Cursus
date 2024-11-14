/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echapuis <echapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:56:38 by echapuis          #+#    #+#             */
/*   Updated: 2023/10/24 11:25:35 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*tab;
	size_t	i;

	tab = (char *)s;
	i = 0;
	while (i < n)
	{
		tab[i] = '\0';
		i++;
	}
}
/*
int main()
{
	int n = 4;
	int j = 0;
	char phrase[] = "heyfriend";

	ft_bzero(phrase, n);
	while (j < 9)
	{
		write(1, &phrase[j], 1);
		j++;	
	}
	printf("%s\n", phrase);
//	printf("%s\n", bzero(phrase, n));
	return (0);
*/
