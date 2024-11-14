/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:10:58 by echapuis          #+#    #+#             */
/*   Updated: 2023/10/26 11:00:00 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		size;
	char	*tab;

	i = 0;
	size = ft_strlen(s);
	tab = ft_calloc(size + 1, sizeof(char));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		tab[i] = f(i, s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
/*
int	main(void)
{
	char	*phrase = "lorem my friend";

	ft_strmapi(phrase,ft_try(0, 'a'));
	return (0);
}*/
