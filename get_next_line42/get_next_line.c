/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:45:06 by cejin             #+#    #+#             */
/*   Updated: 2023/11/17 20:12:50 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*start_newline;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i] || buffer[i] == '\0')
		return (free(buffer), NULL);
	if (buffer[i] == '\n')
		i++;
	start_newline = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (start_newline == NULL)
		return (free(buffer), NULL);
	j = 0;
	while (buffer[i])
		start_newline[j++] = buffer[i++];
	start_newline[j++] = '\0';
	free(buffer);
	return (start_newline);
}

char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer && buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc((i + 1), sizeof(char));
	if (!line)
		return (free(buffer), NULL);
	i = 0;
	while (buffer && buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

char	*read_file(int fd, char *buffer)
{
	char	*tmp_buff;
	int		byte_read;

	byte_read = 1;
	if (!buffer)
		buffer = ft_calloc(1, 1);
	tmp_buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (tmp_buff == NULL)
		return (NULL);
	while (byte_read > 0 && !ft_strchr(tmp_buff, '\n'))
	{
		byte_read = read(fd, tmp_buff, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(tmp_buff), free(buffer), NULL);
		tmp_buff[byte_read] = '\0';
		buffer = ft_strjoin(buffer, tmp_buff);
	}
	free(tmp_buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buffer = NULL;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	line = extract_line(buffer);
	buffer = find_next_line(buffer);
	if (!line && !buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (line);
}

/*
#include <stdio.h>

int	main()
{
	int		fd;
	char	*line;
	char	*file = "test.txt";

	fd = open(file, O_RDONLY);
	if (fd == -1)
		printf("Error\n");
	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	close(fd);
	return 0;
}
*/
