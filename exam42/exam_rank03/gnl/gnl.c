
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

int	ft_strchr(char *str, char c);
int	ft_strlen(char *s);
char	*ft_strjoin(char *buf, char *tmp);
char	*update_buffer(char *buffer);
char	*get_line(char *buffer);
char	*read_file(int fd, char *buffer);
char	*get_next_line(int fd);

/*
int	main()
{
	int fd = open("test", O_RDONLY);
	char	*line;
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	printf("%s", line);
	free(line);
	return (0);
}
*/

char	*get_next_line(int fd)
{
	char	*line;
	static char	*buffer = NULL;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	line = get_line(buffer);
	buffer = update_buffer(buffer);
	if (!line && !buffer)
	{
		free(line);
		line = NULL;
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (line);
}

char	*read_file(int fd, char *buffer)
{
	char	*tmp_buffer;
	int	byte_read = 1;

	if (!buffer)
		buffer = malloc(1 * sizeof(char));
	tmp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (tmp_buffer == NULL)
		return (NULL);
	while (byte_read > 0 && ft_strchr(tmp_buffer, '\n') != 1)
	{
		byte_read = read(fd, tmp_buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(tmp_buffer), free(buffer), NULL);
		tmp_buffer[byte_read] = '\0';
		buffer = ft_strjoin(buffer, tmp_buffer);
	}
	free(tmp_buffer);
	return (buffer);
}

char	*get_line(char *buffer)
{
	int	i = 0;
	char	*line;

	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer && buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	i = 0;
	while (buffer && buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_buffer(char *buffer)
{
	int	i = 0;
	int	j = 0;
	char	*res;

	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer && buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	res = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	while (buffer && buffer[i])
	{
		res[j] = buffer[i];
		j++;
		i++;
	}
	res[j] = '\0';
	free(buffer);
	return (res);
}

char	*ft_strjoin(char *buf, char *tmp)
{
	int	len = ft_strlen(buf);
	int	len2 = ft_strlen(tmp);
	int	i = 0;
	int	j = 0;
	char	*res = malloc((len + len2 + 1) * sizeof(char));

	while (buf && buf[i])
	{
		res[i] = buf[i];
		i++;
	}
	while (tmp && tmp[j])
	{
		res[i + j] = tmp[j];
		j++;
	}
	res[i + j] = '\0';
	free(buf);
	return (res);
}

int	ft_strlen(char *s)
{
	int	i = 0;

	if (s == NULL || s[i] == '\0')
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *str, char c)
{
	int	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
