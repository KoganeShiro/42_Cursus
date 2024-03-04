/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 utils.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: cejin <marvin@42.fr>						+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/02/15 17:50:01 by cejin			   #+#	  #+#			  */
/*	 Updated: 2024/02/23 14:55:45 by cejin			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "pipex.h"

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

void	*ft_calloc(int str_len, int size)
{
	char			*str;
	unsigned int	n;
	unsigned int	i;

	n = str_len * size;
	str = malloc(n);
	if (str == NULL)
		return (0);
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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

char	*ft_strjoin(char *s, char *add)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(s) + ft_strlen(add);
	res = ft_calloc(len + 2, sizeof(char));
	if (res == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '/';
	i++;
	while (add[j] != '\0')
	{
		res[i + j] = add[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}
