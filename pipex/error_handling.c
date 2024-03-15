/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 error_handling.c									:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: cejin <marvin@42.fr>						+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/02/21 13:47:14 by cejin			   #+#	  #+#			  */
/*	 Updated: 2024/02/26 11:49:13 by cejin			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(char **argv, t_pipex *pipex)
{
	pipex->infile_error = 0;
	pipex->outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile_fd < 0)
	{
		perror(argv[4]);
		exit(EXIT_FAILURE);
	}
	pipex->infile_fd = open(argv[1], O_RDONLY);
	if (pipex->infile_fd < 0)
	{
		perror(argv[1]);
		pipex->infile_error = 1;
	}
}

void	check_cmd1(t_pipex *pipex, char **argv)
{
	int		i;

	pipex->cmd_is_path = 0;
	i = ft_strlen(argv[2]);
	while (i != 0)
	{
		if (ft_strncmp(&argv[2][i], "/", 1) == 0)
		{
			pipex->cmd_args1 = ft_calloc(2, sizeof(char *));
			if (ft_strchr(argv[2] + (i + 1), ' ') == 0)
			{
				pipex->cmd_args1[0] = ft_strdup(argv[2] + (i + 1));
				pipex->cmd_args1[1] = NULL;
				pipex->cmd_path = ft_strdup(argv[2]);
			}
			else
			{
				pipex->cmd_args1 = ft_split(argv[2] + (i + 1), " ");
				pipex->cmd_path = ft_strdup_modif(argv[3]);
			}
			pipex->cmd_is_path = 1;
			break ;
		}
		i--;
	}
}

void	check_cmd2(t_pipex *pipex, char **argv)
{
	int	i;

	pipex->cmd_is_path = 0;
	i = ft_strlen(argv[3]);
	while (i != 0)
	{
		if (ft_strncmp(&argv[3][i], "/", 1) == 0)
		{
			pipex->cmd_args2 = ft_calloc(2, sizeof(char *));
			if (ft_strchr(argv[3] + (i + 1), ' ') == 0)
			{
				pipex->cmd_args2[0] = ft_strdup(argv[3] + (i + 1));
				pipex->cmd_args2[1] = NULL;
				pipex->cmd2_path = ft_strdup(argv[3]);
			}
			else
			{
				pipex->cmd_args2 = ft_split(argv[3] + (i + 1), " ");
				pipex->cmd2_path = ft_strdup_modif(argv[3]);
			}
			pipex->cmd2_is_path = 1;
			break ;
		}
		i--;
	}
}

void	is_cmd_exist(t_pipex *pipex)
{
	int		i;

	i = 0;
	if (pipex->cmd_is_path == 1)
		return ;
	while (pipex->all_paths[i] != NULL)
	{
		free(pipex->tmp_path);
		pipex->tmp_path = ft_strjoin(pipex->all_paths[i], pipex->cmd_args1[0]);
		if (access(pipex->tmp_path, X_OK) != -1)
		{
			free(pipex->cmd_path);
			pipex->cmd_path = ft_strdup(pipex->tmp_path);
		}
		if (pipex->all_paths[i + 1] == NULL)
			break ;
		i++;
	}
}

void	is_cmd2_exist(t_pipex *pipex)
{
	int		i;

	i = 0;
	if (pipex->cmd2_is_path == 1)
		return ;
	while (pipex->all_paths[i] != NULL)
	{
		free(pipex->tmp_path2);
		pipex->tmp_path2 = ft_strjoin(pipex->all_paths[i], pipex->cmd_args2[0]);
		if (access(pipex->tmp_path2, X_OK) != -1)
		{
			free(pipex->cmd2_path);
			pipex->cmd2_path = ft_strdup(pipex->tmp_path2);
		}
		if (pipex->all_paths[i + 1] == NULL)
			break ;
		i++;
	}
}
