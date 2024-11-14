/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:45:48 by cejin             #+#    #+#             */
/*   Updated: 2024/10/18 11:54:13 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_check_gnl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*chaine;

	i = 0;
	j = 0;
	chaine = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!chaine)
		return (NULL);
	while (s1 != NULL && s1[i])
	{
		chaine[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		chaine[i] = s2[j];
		j++;
		i++;
	}
	free(s1);
	chaine[i] = '\0';
	return (chaine);
}

char	*ft_extract_line(char *s)
{
	int		i;
	char	*result;

	if (!s)
		return (0);
	result = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (result == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		result[i] = s[i];
		if (s[i] == '\n')
		{
			result[i + 1] = '\0';
			return (result);
		}
		i++;
	}
	return (free(result), NULL);
}
