/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:32:47 by echapuis          #+#    #+#             */
/*   Updated: 2023/10/25 16:58:00 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_contains(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	if (j == 0)
		return (ft_strdup(""));
	if (set == NULL)
		return ((char *)s1);
	while (ft_contains(set, s1[i]))
		i++;
	while (ft_contains(set, s1[j - 1]))
		j--;
	return (ft_substr(s1, i, (j - i)));
}
/*
int	main(void)
{
	char	*phrase;
	char	*phrase2;

	phrase = "lorem ipsum dolor sit amet";
	phrase2 = "te";
	printf("%s", ft_strtrim(phrase, phrase2));
	return (0);
}*/
