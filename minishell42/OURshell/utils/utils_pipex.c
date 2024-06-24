/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:06:30 by vharatyk          #+#    #+#             */
/*   Updated: 2024/06/23 17:45:37 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*src;

	src = (char *)s;
	i = 0;
	while (n != 0)
	{
		src[i] = 0;
		i++;
		n--;
	}
	return ;
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (ft_strlen(s2) == 1)
		return (s1[i] - s2[i]);
	while (s1[i] == s2[i] && s1[i] && i < n)
	{
		i++;
		n--;
	}
	return (s1[i] - s2[i]);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[i] == s2[i] && s1[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*result;

	result = (char *)s;
	i = 0;
	while (result[i])
	{
		if (result[i] == (char)c)
			return (&result[i]);
		i++;
	}
	if (result[i] == (char)c)
		return (&result[i]);
	return (0);
}

char	*pipex_join(char *s, char *add, char in_between)
{
	char	*res;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (ft_strlen(s) == 0 || ft_strlen(add) == 0)
		return (ft_strdup("no path"));
	res = ft_calloc(ft_strlen(s) + ft_strlen(add) + 2, sizeof(char));
	if (res == NULL)
		return (NULL);
	while (s[++i] != '\0')
		res[i] = s[i];
	if (in_between != '\0')
		res[i++] = in_between;
	while (add[++j] != '\0')
		res[i + j] = add[j];
	res[i + j] = '\0';
	return (res);
}
