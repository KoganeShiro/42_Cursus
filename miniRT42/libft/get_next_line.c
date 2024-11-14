/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:45:06 by cejin             #+#    #+#             */
/*   Updated: 2024/10/18 11:53:18 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	size_t	j;

	j = 0;
	while (src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

void	buff_update(char *buffer)
{
	size_t	i;
	char	*result;

	i = 0;
	result = buffer;
	while (buffer[i] && buffer[i] != '\n')
	{
		result++;
		i++;
	}
	if (buffer[i] == '\n')
	{
		i++;
		result++;
		*buffer = *ft_strcpy(buffer, result);
	}
}

char	*search_in_buff(char *buffer, char *line)
{
	char	*result;

	result = ft_extract_line(buffer);
	if (result == NULL)
	{
		line = ft_strjoin_gnl(line, buffer);
		*buffer = '\0';
	}
	else
	{
		line = ft_strjoin_gnl(line, result);
		free(result);
	}
	return (line);
}

char	*get_next_line_impl(char *buffer, char *line, int fd)
{
	int	nb;

	nb = BUFFER_SIZE;
	line = malloc(1 * sizeof(char));
	if (line == NULL)
		return (NULL);
	line[0] = '\0';
	while (1)
	{
		if (buffer[0] == '\0')
			nb = read(fd, buffer, BUFFER_SIZE);
		if (nb == -1)
			return (free(line), NULL);
		buffer[nb] = '\0';
		line = search_in_buff(buffer, line);
		if (nb < BUFFER_SIZE || ft_check_gnl(buffer))
			break ;
	}
	if (line[0] == '\0')
		return (free(line), NULL);
	buff_update(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	return (get_next_line_impl(buffer, line, fd));
}
