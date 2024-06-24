/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:45:48 by cejin             #+#    #+#             */
/*   Updated: 2024/06/21 13:05:51 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin_gnl(char *buffer, char *tmp)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = ft_calloc((ft_strlen(tmp) + ft_strlen(buffer) + 1), sizeof(char));
	if (!line)
		return (free(buffer), NULL);
	while (buffer && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	while (tmp[j] != '\0')
	{
		line[i + j] = tmp[j];
		j++;
	}
	line[i + j] = '\0';
	if (buffer != NULL)
		free(buffer);
	return (line);
}

int	ft_strchr_gnl(char *buffer, int new_line_ptr)
{
	int	i;

	i = 0;
	if (buffer && buffer[i] == '\0')
		return (0);
	while (buffer && buffer[i] != '\0')
	{
		if (buffer[i] == new_line_ptr)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *buffer)
{
	int	i;

	i = 0;
	if (buffer == NULL)
		return (-1);
	while (buffer[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(int str_len, int size)
{
	char			*str;
	unsigned int	n;
	unsigned int	i;

	n = str_len * size;
	str = malloc(n);
	if (str == NULL)
		exit(1);
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
