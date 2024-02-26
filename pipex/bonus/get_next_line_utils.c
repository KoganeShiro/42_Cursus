/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:45:48 by cejin             #+#    #+#             */
/*   Updated: 2023/11/17 20:15:26 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char *buffer, char *tmp)
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
	free(buffer);
	return (line);
}

int	ft_strchr(char *buffer, int new_line_ptr)
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

int	ft_strlen(char *buffer)
{
	int	i;

	i = 0;
	if (buffer == NULL)
		return (0);
	while (buffer[i] != '\0')
		i++;
	return (i);
}
