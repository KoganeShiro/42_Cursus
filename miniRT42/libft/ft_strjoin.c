/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:03:32 by echapuis          #+#    #+#             */
/*   Updated: 2023/10/31 13:01:13 by echapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*chaine;

	i = 0;
	j = 0;
	chaine = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1 * sizeof(char));
	if (!chaine)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		chaine[i] = s1[i];
		i++;
	}
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		chaine[i] = s2[j];
		j++;
		i++;
	}
	chaine[i] = '\0';
	return (chaine);
}
/*
int	main(void)
{
	char    strs[] = "tripouille";
	char	str[] = "42";
	char    *res = ft_strjoin(strs,str);
	printf("[%s]\n",res);

	return (0);
}*/
