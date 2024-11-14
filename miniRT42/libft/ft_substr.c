/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:44:47 by echapuis          #+#    #+#             */
/*   Updated: 2023/10/26 16:29:08 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (start > ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	i = start;
	while (s[i] && (i - start) < len)
		++i;
	result = malloc((i - start + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = start;
	while (s[i] && i - start < len)
	{
		result[i - start] = s[i];
		i++;
	}
	result[i - start] = '\0';
	return (result);
}
/*
int	main(void)
{
		char	phrase[] = "gollum_amigos";
		int		d = 3;
		size_t	e = 420000000LL;
		char *result = ft_substr(phrase, d, e);

		printf("%s", result);
		free(result);
		return (0);
}*/
