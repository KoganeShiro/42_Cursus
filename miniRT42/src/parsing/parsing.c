/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:22:49 by cejin             #+#    #+#             */
/*   Updated: 2024/11/13 15:41:34 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/minirt.h"

/*
step 1
read the file
init struct
init the right struct from what you are reading, check if there enough arguments
if not quit

if (check if file is .rt, exist and we have perms to read it)
	return (error_parsing(fd, graphics));
//step 1
if (read_file(graphics, file) == EXIT_FAILURE)
	return (error_parsing(fd, graphics));
//step 2
if (is_data_in_range(graphics) == EXIT_FAILURE)
	return (error_parsing(fd, graphics));

step 2
check if the init struct values are in range
if not quit
*/

static int	_is_file_rt(const char *file)
{
	int	i;

	i = 0;
	while (file[i] != '\0')
	{
		if (file[i] == '.')
		{
			if (ft_strcmp(file + i, ".rt") == 0)
			{
				printf("\033[1m\033[32mfile is a .rt\033[0m\n");
				return (EXIT_SUCCESS);
			}
		}
		i++;
	}
	printf("\033[1m\033[31mfile is not a .rt\033[0m\n");
	return (EXIT_FAILURE);
}

//		printf("line = [%s]\n", line);

static int	_read_rtfile(int fd, t_graphics *rt)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	while (line != NULL)
	{
		i = skip_whitespaces(line);
		if (i == -1)
			continue ;
		if (fill_struct(line, i, rt) == EXIT_FAILURE)
		{
			return (free(line), EXIT_FAILURE);
		}
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	free(line);
	line = NULL;
	if (rt->has_require_obj == 3)
		return (EXIT_SUCCESS);
	printf("%s\n", ERR_MISS_OBJ);
	return (EXIT_FAILURE);
}

int	parse_file(const char *file, t_graphics *rt)
{
	int	fd;

	if (_is_file_rt(file) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		return (EXIT_FAILURE);
	}
	if (_read_rtfile(fd, rt) == EXIT_FAILURE)
		return (close(fd), EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}

// int	test(const char *file, t_graphics *rt)
// {
// 	printf("\033[1m\033[37m========= %s =========\033[0m\n", file);
// 	if (parse_file(file, rt) == EXIT_FAILURE)
// 	{
// 		printf("\033[31mError \033[0m\n\n");
// 		return (EXIT_FAILURE);
// 	}
// 	else
// 	{
// 		printf("\033[32mSuccess \033[0m\n\n");
// 		return (EXIT_SUCCESS);
// 	}
// }
